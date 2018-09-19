#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int k=1;
    char str[20];
    while(1) {
        gets(str);
        if(str[0]=='#' && str[1]=='\0') break;
        else {
            printf("Case %d: ",k++);
            if(!strcmp(str,"HELLO")) printf("ENGLISH\n");
            else if(!strcmp(str,"HOLA")) printf("SPANISH\n");
            else if(!strcmp(str,"HALLO")) printf("GERMAN\n");
            else if(!strcmp(str,"BONJOUR")) printf("FRENCH\n");
            else if(!strcmp(str,"CIAO")) printf("ITALIAN\n");
            else if(!strcmp(str,"ZDRAVSTVUJTE")) printf("RUSSIAN\n");
            else printf("UNKNOWN\n");
        }
    }
    return 0;
}

