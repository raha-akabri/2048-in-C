#include <stdio.h>
#include <stdlib.h> // allow to generate randdom nubers
#include <time.h>

int main(void)
{
    int screen[4][4] = {0}; // create a 4*4 game boxes


    srand(time(NULL));  // Generate two random positions

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


    for (int r = 0; r < 4; r++)    // Print the boxes
    {
        for (int c = 0; c < 4; c++)
        {
            printf("%4d", screen[r][c]);
        }

        printf("\n");
    }

    char move; // get movement from player
    printf("Enter your move to start (W/A/S/D):");
    scanf("%c", &move);

    if (move == 'a' || move =='A') //move all numbers to the left
    {
        for (int r=0; r < 4; r++)
        {
            int pos = 0;

        for (int c=0; c < 4; c++)
        {
            if (screen[r][c] !=0)
            {
                int number = screen[r][c];
                screen [r][c] = 0;
                screen [r][pos] = number;
                pos++;
            }
        }
        for (int c=0; c < 3; c++) // merge equal numbers
        {
            if (screen [r][c] !=0 &&
                screen[r][c] == screen[r][c+1])
                {
                    screen[r][c] *=2;
                    screen[r][c+1]= 0;

                    c++;
                }
        }
        pos =0; // remove empty boxes after merging
        for (int c= 0; c<4; c++)
        {
            if (screen[r][c] !=0)
            {
            int number = screen[r][c];
            screen[r][c]= 0;
            screen[r][pos] = number;
            pos++;
        }
        }
        }
    }
    if (move =='d' || move == 'D')   // move all numbers to the right
    {
        for (int r=0; r < 4; r++)
        {
            int pos = 3; // where to start

        for (int c=3; c >= 0; c--) // decrese column number
        {
            if (screen[r][c] !=0)
            {
                int number = screen[r][c];
                screen [r][c] = 0;
                screen [r][pos] = number;
                pos--;
            }
        }
        for (int c=3; c > 0; c--) // merge equal numbers
        {
            if (screen [r][c] !=0 &&
                screen[r][c] == screen[r][c-1])
                {
                    screen[r][c] *=2;
                    screen[r][c-1]= 0;

                    c--;
                }
        }
        pos =3; // remove empty boxes after merging
        for (int c= 3; c>=0; c--)
        {
            if (screen[r][c] !=0)
            {
            int number = screen[r][c];
            screen[r][c]= 0;
            screen[r][pos] = number;
            pos--;
        }
        }
        }
        
    }
    
    
        printf("\nupdated board:\n");

    for (int r=0; r < 4; r++) // print the new or updated board
    {
        for (int c=0; c < 4; c++)
        {
            printf("%4d", screen[r][c]);
        }
        printf("\n");
    }

    return 0;

}
