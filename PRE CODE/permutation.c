#include <stdio.h>
#include <string.h>

void recursion (char str[100],int i,int j,int len)
{
   char temp;
   if (j==len-1) printf("%s\n",str);
   else {

        /*if (j == len-1) printf("%s\n",str);*/
        for(i=j;i<len;i++) {
            //printf("%d %d\n",i,j);
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            recursion(str,(i),(j+1),len);
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
        //swap(str[i],str[j]);
   }
}


int main()
{
    char str[100];
    gets(str);
    int len;
    len = strlen(str);
    //printf("%d\n",len);

    recursion(str,0,0,len);


    return 0;
}

