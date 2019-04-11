#include <bits/stdc++.h>

using namespace std;
char str[100000];
int main()
{
    char current=1,prev=0;
    int space=0;

    while(gets(str))
    {
        int len = strlen(str);
        str[len]= '\0';
        space=0;
        for(int i=0; i<len; i++)
        {
            if(str[i]== 32)
            {
                space++;
                if(space==3)
                    space =0;
            }
            else if(str[i]!=32)
            {
                if(space==1)
                {
                    printf(" ");
                    space=0;
                }
                else space=0;
//                while(space-->0)
//                    printf(" ",space);

                printf("%c",str[i]);
            }
            else space=0;
        }
        printf("\n");
    }
}
