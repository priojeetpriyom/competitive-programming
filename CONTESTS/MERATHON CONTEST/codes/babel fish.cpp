#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
char english[100010] [11], foreign [100010] [11],word[11];
int main ()
{
    int i=0,len=0,r=0;
    memset(foreign,0,sizeof(foreign));
    memset(english,0,sizeof(english));
    memset(word,0,sizeof(word));
    while(gets(word) != NULL) {

        if(word [0]=='\0') break;
        //getchar();
        //scanf("%s",foreign[len++]);
        len=strlen(word);
        for(i=0;i<len;i++) {
            if(word[i] == 32) {
                i++;
                break;
            }
            english[r] [i] = word[i];

        }
        english[r] [i]= '\0';
        int j=0;
        for(;i<len;i++) {

            foreign[r] [j++] = word[i];
        }
        r++;
        foreign[r] [j]= '\0';
        //printf("%s %s\n",english,foreign);
        memset(word,0,sizeof(word));
    }
    memset(word,0,sizeof(word));
    while(gets(word) != NULL) {
        if(word [0]=='\0') break;
        len = strlen(word);
        word[len] = '\0';
        for(i=0;i<r;i++) {
            if(strcmp(foreign[i],word)==0) {
                printf("%s\n",english[i]);
                i= -1;
                break;
            }
        }
        if(i != -1) printf("eh\n");
        memset(word,0,sizeof(word));
    }

    return 0;
}
