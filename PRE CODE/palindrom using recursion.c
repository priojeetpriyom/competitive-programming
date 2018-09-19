#include <stdio.h>
#include <string.h>

void recursion (char str[100],int i,int j,int len)
{
   int temp;
   if (j==len-1) printf("%s\n",str);
   else {
        for(i=j;i<len;i++) {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            recursion(str,(i),(j+1),len);
            /*temp = str[i];
            str[i] = str[j];
            str[j] = temp;*/
        }
   }
}


int main()
{
    char str[100];
    scanf("%s",str);
    int len = strlen(str);
    recursion(str,0,0,len);


    return 0;
    }


