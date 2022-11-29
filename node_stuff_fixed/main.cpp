#include <stdio.h>
#include <math.h>
#include <string.h>


/*

a) Schreiben Sie eine Funktion, die neben notwendigen Listeninformationen ein
Charakter ubernimmt, einen neuen Knoten erzeugt und vorne der Liste hin- ¨
zufugt. ¨
b) Schreiben Sie eine Funktion, die neben notwendigen Listeninformationen einen
String ubernimmt und alle im String gespeicherten Zeichen vorne der Liste ¨
hinzufugt. Verwenden Sie zur L ¨ ¨osung die Funktion aus a).
c) Schreiben Sie eine Funktion, die alle in der Liste gespeicherten Zeichen auf
stdout ausgibt.
d) Schreiben Sie eine Funktion, die alle dynamisch angeforderten Knoten wieder
freigibt.
Testen Sie ihre Funktionen indem sie eine Liste erzeugen, den String "Missisippi"
in die Liste schreiben und anschließend den Inhalt der Liste wieder ausgeben. Sie
sollten den String in umgekehrter Reihenfolge der Zeichen erhalten.

*/
typedef struct node {
    char ch;
    struct node *next;
} node_t;

void addNode( char c , node_t ** begin){

    node_t * newNode;

    newNode = (node_t *)malloc( sizeof(node_t) );
    if(newNode == NULL){
        printf("error in alloc\n");
        //error handling
        return;
    }

    newNode->ch = c;
    // *x = c <==> struct->x

    newNode->next = *begin;


    *begin =  newNode;

}

void addString(char * str, node_t ** begin)
{
    int i;
    for ( i = 0; i < strlen(str); i++)
    {
        addNode( str[i], begin );
    }
}

// do not need to change -> no need for address, so call by reference
void printCharList(node_t * begin)
{
    node_t * tmp;
    tmp = begin;
    while ( tmp != NULL )
    {
        printf("%c", tmp->ch);

        tmp = tmp->next;
    }

}

void freeCharList(node_t ** begin)
{
    node_t * tmp;
    while ( *begin != NULL )
    {
        tmp = (*begin) -> next;
        free(*begin);
        begin = &tmp;
    }

}

int main(void)
{
    //((initialize some list))

    node_t * char_list;
    char str [5] = "abcd";

    char_list = NULL;

    addNode('a', &char_list);
    addString(str, &char_list);
    printCharList(char_list);
    freeCharList(&char_list);


      
    
    return 0;

}

