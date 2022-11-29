#include <stdio.h>
#include <math.h>
#include <string.h>


int getBiggest( int * x, int *y, int  matrix[80][80] ){
    int max;
    int i,j;

    max = matrix[0][0];

    for ( i = 0; i < 80; i++)
    {
        for (j = 0; j < 80; j++)
        {
            if(matrix[i][j] > max){
                max = matrix[i][j];
                *x = i;
                *y = j;
            }
        }
        
    }
    
    return max;


}

int main(void)
{
    int matrix [80][80];
    int i, j;
    int x, y;
    int max;

    //arg 2: modus ("rw", "r", "w")

    FILE * f = fopen("./matrix.txt", "r" ) ;

    if(f == NULL){
        printf ("file read error\n");
        return 0;
    }

    //fscanf( f , "%d", matrix[][] );

    //zeile
    for ( i = 0; i < 80; i++)
    {
        //spalte
        for (j = 0; j < 80; j++)
        {
            fscanf( f , "%d", & matrix[i][j] );
            // andere methode für file lesen fgets() (file get string) und strtok
        }
        
    }

    max = getBiggest( &x, &y, matrix);
    
    printf("Biggest: %d at (%d|%d)", max, x,y);


    return 0;

}

