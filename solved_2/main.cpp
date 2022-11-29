#include <stdio.h>
#include <math.h>
#include <string.h>


// there is no return value expected, so void  is fine
void out(int * p, int n ){
    int i;
    for( i = 0; i<n; i++){
        printf("%d ", p[i]);
    }

    //main already frees the memory space, so we dont need to free(p) after output
}

// n = number of items in the array
void sort ( int * arr, int n)
{

    // Bubble sort for integer array
    int b, k, tmp;

    for (k=1; k < n; k++){
      for(b = 0; b < (n-k); b++){
        if(arr[b] > arr[b+1]) {

          tmp     = arr[b+1];
          arr[b+1]= arr[b];
          arr[b]  = tmp;
          
        }
      }
    }

}

// must return the datatype (int *) as we assign it to p in the main function, which is type (int *)

int * merge(int * f1, size_t n1, int * f2, size_t n2)
{
    int * arr;
    int n = n1 + n2;
    int i;


    arr = (int *)malloc( n * sizeof(int) );
    if(arr == NULL){
        // memory allocation error
        return NULL;
    }


    // fill the array

    for (i = 0; i < n1; i++)
    {
        arr[i] = f1[i];
    }
    // n1 points here       v , so start there and increase by 1 every step
    // pos :    0 1 2 3 4 5 6 7 8 9
    // arr == { 3 7 5 3 9 1 x x x x }
    for (i = 0; i < n2; i++)
    {
        arr[ n1 + i ] = f2[i];
    }
    // other solution would be: for (i = n1; i<n; i++){  arr[i] = f2[i-n1];  }
    

    sort(arr, n);

    return arr;


}

// no need for argc, argv 
int main(void)
{
    int f1[] = {3,7,5,3,9,1};
    int f2[] = {1,2,7,4};

    size_t n1 = sizeof(f1) / sizeof(int);
    size_t n2 = sizeof(f2) / sizeof(int);

    int  * p = NULL;

    p = merge(f1, n1, f2, n2);
    out(p, n1+n2);

    free(p);

    return 0;

}

