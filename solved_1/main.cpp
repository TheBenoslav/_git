#include <stdio.h>
#include <math.h>
#include <string.h>

int getCharInString( char * str, char c );


int getCharInString( char * str, char c ){

    int i;
    int cnt = 0;

    
    // "heute" -> str[0] == h
    for ( i = 0; i < strlen(str); i++)
    {
        if(str[i] == c){
            cnt++;
        }
    }

    return cnt;
}

// argc : argument count
// argv : argument value


int main(int argc, char * argv[])
{

    int i;
    int num;
    char c;

    printf("Zeichen:");

    //getchar: ein zeichen, scanf für formattierte strings
    //scanf("%c", &c);

    c = getchar();


    for ( i = 1; i < argc; i++)
    {
        num = getCharInString( argv[i], c );
        printf("%s : %d\n", argv[i], num );

    }
    

    return 0;

}


