#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>


//Function definition
void startworld(int rows, int columns);
double randomnumbers(double min, double max);
char *create_simulation(int rows, int columns);
void display_simulation(int rows, int columns, char *simulation);
int countneighborhood(int rows, int columns, int r, int c, char *simulation);
//int countneighborhood(int rows, int columns, int x, int y, char *simulation);
char *spaceshipworld(int rows, int columns);

char *new_simulation(int rows, int columns, char *prev_simulation);



int main()
{

    int rows = 21; //gamesize in height.
    int columns = 44; //gamesize in lenght


    //Main function
    startworld(rows,columns);

    return 0;
}





//  Main Function that starts the game.
void startworld(int rows, int columns)
{
    puts("Starting world");
    char *simulation = spaceshipworld(rows, columns); //creates the header simulation
    display_simulation(rows, columns, simulation); //displays the header simulation

    Sleep(100);

    // keeps the simulation running.
    while(1)
    {
        system("cls");

        char *nextsim = new_simulation(rows, columns, simulation); //creates a new simulation
        if(simulation == NULL) return;

        free(simulation); // frees memory from the previous simulation.
        simulation = nextsim;
        display_simulation(rows, columns, simulation); //displays the new simulation
        Sleep(20);
    }

}



// Function that returns a random number between min and max.
double randomnumbers(double min, double max)
{
    return ((double)rand()/RAND_MAX)*(max-min)+min;
}



// Function that creates the game of life simulation, with cells dead or alive. And returns it.
char *create_simulation(int rows, int columns)
{
    char *simulation = calloc(rows*columns, sizeof(char)); //Allocate memory for the simulation.
    if(simulation == NULL)
        return NULL;
    for(int y = 0; y < rows; y++) // y == height/row
    {
        for(int x = 0; x < columns; x++) // x == width/column
        {
            //Creates borders for the first simulation game.
            if(y == 0)
            {
                *(simulation + y*columns + x) = '-';
            }

            else if (x == 0 && y == rows - 1)
            {
                *(simulation + y*columns + x) = '-';
            }
            else if(x == 0)
            {
                *(simulation + y*columns + x) = '!';
            }
            else if (y == rows -1)
            {
                *(simulation + y*columns + x) = '-';
            }
            else if (x == columns - 1)
            {
                *(simulation + y*columns + x) = '!';
            }
            else
            {
                double random = randomnumbers(0.0,1.0);
                if( random <= 0.40) // if random number below 0.4 create a alive cell. Else create a dead cell.
                {
                    *(simulation + y*columns + x) = 'X';
                }
                else
                {
                    *(simulation + y*columns + x) = ' ';

                }

            }

        }
    }
    return simulation;
}



// Displays the simulation to the terminal
void display_simulation(int rows, int columns, char *simulation)
{
    printf("\n");
    for(int y = 0; y < rows; y++)
    {
        for(int x = 0; x < columns; x++)
        {
            printf("%c", *(simulation + y*columns + x));
        }
        printf("\n");
    }

}




/*//Counts all the living cells in the neighborhood.
int countneighborhood(int rows, int columns, int x, int y, char *simulation)
{
    int count = 0;
    int root = y*columns+x;

    for (int i = -1; i <= 1; i++) {

        for (int j = -1; j <= 1; j++) {

            char cell = *(simulation+root+(i*columns)+j);
            if(cell == 'X') count++;

        }
    }
    return count;
}*/





//Counts all the living cells in the neighborhood.
int countneighborhood(int rows, int columns, int r, int c, char *simulation)
{
    int count = 0;
    int minrow = r - 1;
    int maxrow = r + 1;

    int mincol = c - 1;
    int maxcol = c + 1;

    int row_end = rows - 2;
    int row_start = 1;

    int col_end = columns - 2;
    int col_start = 1;



    for (int y = minrow; y <= maxrow; y++) {
        for (int x = mincol; x <= maxcol; x++) {

            //north
            if(y == 0)
            {
                if(x == 0)
                {
                    char cell = *(simulation + row_end*columns + col_end);
                    if(cell == 'X') count++;
                }
                else
                {
                    char cell = *(simulation + row_end*columns + x);
                    if(cell == 'X') count++;
                }

            }
                //East
            else if(x == columns - 1)
            {
                if (y == 0) {
                    char cell = *(simulation + row_end * columns + col_start);
                    if (cell == 'X') count++;
                } else {
                    char cell = *(simulation + y * columns + col_start);
                    if (cell == 'X') count++;
                }
            }

            //South
            else if (y == rows - 1)
            {
                if(x == columns - 1)
                {
                    char cell = *(simulation + row_start*columns + col_start);
                    if(cell == 'X') count++;
                }
                else
                {
                    char cell = *(simulation + row_start*columns + x);
                    if(cell == 'X') count++;
                }

            }
            //West
            else if (x == 0)
            {
                if(y == rows - 1)
                {
                    char cell = *(simulation + row_start*columns + col_end);
                    if(cell == 'X') count++;
                }
                else
                {
                    char cell = *(simulation + y*columns + col_end);
                    if(cell == 'X') count++;
                }

            }



           /* //Northeast
            else if((minrow == 0) && (x == columns - 1))
            {
                char cell = *(simulation + row_end*columns + col_start);
                if(cell == 'X') count++;
            }
            //SouthEast
            else if(y == rows - 1 && x == columns - 1)
            {
                char cell = *(simulation + row_start*columns + col_start);
                if(cell == 'X') count++;
            }
            //SouthWest
            else if(y == rows - 1 && mincol == 0)
            {
                char cell = *(simulation + row_start*columns + col_end);
                if(cell == 'X') count++;
            }
            //NorthWest
            else if(minrow == 0 && mincol == 0)
            {
                char cell = *(simulation + row_end*columns + col_end);
                if(cell == 'X') count++;
            }*/
            else
            {
                char cell = *(simulation + y*columns + x);
                if(cell == 'X') count++;
            }


        }
    }
    return count;
}





char *spaceshipworld(int rows, int columns)
{
    char *simulation = calloc(rows*columns, sizeof(char)); //Allocate memory for the simulation.
    if(simulation == NULL)
        return NULL;
    for(int y = 0; y < rows; y++) // y == height/row
    {
        for(int x = 0; x < columns; x++) // x == width/column
        {
            //Creates borders for the first simulation game.
            if(y == 0)
            {
                *(simulation + y*columns + x) = '-';
            }

            else if (x == 0 && y == rows - 1)
            {
                *(simulation + y*columns + x) = '-';
            }
            else if(x == 0)
            {
                *(simulation + y*columns + x) = '!';
            }
            else if (y == rows -1)
            {
                *(simulation + y*columns + x) = '-';
            }
            else if (x == columns - 1)
            {
                *(simulation + y*columns + x) = '!';
            }
            else
            {
                if((x == 7 && y == 2 ) || (x == 8 && y == 3) || (x > 5 && x < 9 && y == 4))
                {
                    *(simulation + y*columns + x) = 'X';
                }
                else if((x == 12 && y == 16 ) || (x == 11 && y == 17) || (x > 10 && x < 14 && y == 18))
                {
                    *(simulation + y*columns + x) = 'X';

                }
                else
                {
                    *(simulation + y*columns + x) = ' ';

                }

            }

        }
    }
    return simulation;
}







//Function that creates a new simulation out from the previous one.
char *new_simulation(int rows, int columns, char *prev_simulation)
{
    char *nextsimulation = calloc(rows*columns, sizeof(char)); //allocate memory for the next simulation.
    if(nextsimulation == NULL) return NULL;

    for(int y = 0; y < rows; y++)
    {
        for(int x = 0; x < columns; x++)
        {
            //Creates borders for the first simulation game.
            if(y == 0)
            {
                *(nextsimulation + y*columns + x) = '-';
            }

            else if (x == 0 && y == rows - 1)
            {
                *(nextsimulation + y*columns + x) = '-';
            }
            else if(x == 0)
            {
                *(nextsimulation + y*columns + x) = '!';
            }
            else if (y == rows -1)
            {
                *(nextsimulation + y*columns + x) = '-';
            }
            else if (x == columns - 1)
            {
                *(nextsimulation + y*columns + x) = '!';
            }
            else
            {
                int live = countneighborhood(rows, columns, y, x, prev_simulation); //count cell in the prev neighborhood.
                char cell = *(prev_simulation+y*columns+x); //cell = cell from previous simulation.
                if(cell == 'X') live--; // if previous cell is alive: decrease the count to get the right amount of living cells in the neighborhood.
                *(nextsimulation+y * columns+x) = cell; //set prev cell as the next cell.

                // rule 1. checks if a live cell has less than two neighbors.
                if(live < 2)
                {
                    *(nextsimulation+y * columns+x) = ' ';
                }
                    // rule 2. if a living cell has 2 or 3 live cell, make that cell alive.
                else if((live == 2 || live == 3) && cell == 'X')
                {
                    *(nextsimulation+y * columns+x) = 'X';
                }
                    // if a living cell has more than 3 living neighbors, kill that cell.
                else if(live > 3 && cell == 'X')
                {
                    *(nextsimulation+y * columns+x) = ' ';
                }
                    // if a dead cell has 3 living neighbors, make that cell alive.
                else if(live == 3 && cell == ' ')
                {
                    *(nextsimulation+y * columns+x) = 'X';
                }
            }
        }
    }
    return nextsimulation; //return the new simulation
}
