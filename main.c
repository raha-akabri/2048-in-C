
#include <stdio.h>
#include <stdlib.h> // Allow to generate random numbers
#include <time.h>
#include <conio.h>  // Read keyboard arrow keys

int main(void)
{
    int screen[4][4] = {0}; // Create a 4x4 game board

    srand(time(NULL)); // Initialise random number generator

    // Generate two random positions
    for (int a = 0; a < 2; a++)
    {
        int r, c;

        do
        {
            r = rand() % 4;
            c = rand() % 4;
        }
        while (screen[r][c] != 0);

        screen[r][c] = 2;
    }

    printf("Welcome to 2048 game!\n");

    // Print the initial board
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            printf("%4d", screen[r][c]);
        }
        printf("\n");
    }

    // Get movement from player using arrow keys
    char move = '\0'; // Store the player's movement direction

    printf("Use arrow keys to move the numbers\n");

    int key = _getch(); // Read the first keyboard code

    if (key == 0 || key == 224) // Check if a special key was pressed
    {
        key = _getch(); // Read the arrow key code

        if (key == 72) // UP arrow pressed
        {
            move = 'w'; // Direction UP
        }
        else if (key == 80) // DOWN arrow pressed
        {
            move = 's'; // Direction DOWN
        }
        else if (key == 75) // LEFT arrow pressed
        {
            move = 'a'; // Direction LEFT
        }
        else if (key == 77) // RIGHT arrow pressed
        {
            move = 'd'; // Direction RIGHT
        }
    }

    printf("\nDetected movement: %c\n", move);

    // Move all numbers to the LEFT
    if (move == 'a')
    {
        for (int r = 0; r < 4; r++)
        {
            int pos = 0;

            // Move numbers to the left
            for (int c = 0; c < 4; c++)
            {
                if (screen[r][c] != 0)
                {
                    int number = screen[r][c];
                    screen[r][c] = 0;
                    screen[r][pos] = number;
                    pos++;
                }
            }

            // Merge equal numbers
            for (int c = 0; c < 3; c++)
            {
                if (screen[r][c] != 0 &&
                    screen[r][c] == screen[r][c + 1])
                {
                    screen[r][c] *= 2;
                    screen[r][c + 1] = 0;
                    c++;
                }
            }

            // Remove empty boxes after merging
            pos = 0;

            for (int c = 0; c < 4; c++)
            {
                if (screen[r][c] != 0)
                {
                    int number = screen[r][c];
                    screen[r][c] = 0;
                    screen[r][pos] = number;
                    pos++;
                }
            }
        }
    }

    // Move all numbers to the RIGHT
    if (move == 'd')
    {
        for (int r = 0; r < 4; r++)
        {
            int pos = 3; // Start from the rightmost column

            // Move numbers to the right
            for (int c = 3; c >= 0; c--)
            {
                if (screen[r][c] != 0)
                {
                    int number = screen[r][c];
                    screen[r][c] = 0;
                    screen[r][pos] = number;
                    pos--;
                }
            }

            // Merge equal numbers
            for (int c = 3; c > 0; c--)
            {
                if (screen[r][c] != 0 &&
                    screen[r][c] == screen[r][c - 1])
                {
                    screen[r][c] *= 2;
                    screen[r][c - 1] = 0;
                    c--;
                }
            }

            // Remove empty boxes after merging
            pos = 3;

            for (int c = 3; c >= 0; c--)
            {
                if (screen[r][c] != 0)
                {
                    int number = screen[r][c];
                    screen[r][c] = 0;
                    screen[r][pos] = number;
                    pos--;
                }
            }
        }
    }

    // Move all numbers UP
    if (move == 'w')
    {
        for (int c = 0; c < 4; c++)
        {
            int pos = 0; // Start from the topmost row

            // Move numbers to the top
            for (int r = 0; r < 4; r++)
            {
                if (screen[r][c] != 0)
                {
                    int number = screen[r][c];
                    screen[r][c] = 0;
                    screen[pos][c] = number;
                    pos++;
                }
            }

            // Merge equal numbers
            for (int r = 0; r < 3; r++)
            {
                if (screen[r][c] != 0 &&
                    screen[r][c] == screen[r + 1][c])
                {
                    screen[r][c] *= 2;
                    screen[r + 1][c] = 0;
                    r++;
                }
            }

            // Remove empty boxes after merging
            pos = 0;

            for (int r = 0; r < 4; r++)
            {
                if (screen[r][c] != 0)
                {
                    int number = screen[r][c];
                    screen[r][c] = 0;
                    screen[pos][c] = number;
                    pos++;
                }
            }
        }
    }

    // Move all numbers DOWN
    if (move == 's')
    {
        for (int c = 0; c < 4; c++)
        {
            int pos = 3; // Start from the bottommost row

            // Move numbers to the bottom
            for (int r = 3; r >= 0; r--)
            {
                if (screen[r][c] != 0)
                {
                    int number = screen[r][c];
                    screen[r][c] = 0;
                    screen[pos][c] = number;
                    pos--;
                }
            }

            // Merge equal numbers
            for (int r = 3; r > 0; r--)
            {
                if (screen[r][c] != 0 &&
                    screen[r][c] == screen[r - 1][c])
                {
                    screen[r][c] *= 2;
                    screen[r - 1][c] = 0;
                    r--;
                }
            }

            // Remove empty boxes after merging
            pos = 3;

            for (int r = 3; r >= 0; r--)
            {
                if (screen[r][c] != 0)
                {
                    int number = screen[r][c];
                    screen[r][c] = 0;
                    screen[pos][c] = number;
                    pos--;
                }
            }
        }
    }

    // Print the updated board
    printf("\nUpdated board:\n");

    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            printf("%4d", screen[r][c]);
        }
        printf("\n");
    }

    return 0;
}
