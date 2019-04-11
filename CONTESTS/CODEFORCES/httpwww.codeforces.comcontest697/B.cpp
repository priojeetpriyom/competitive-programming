
#include <bits/stdc++.h>

using namespace std;

int main ()
{
//    freopen("input.txt","r",stdin);
    char str[111];
    scanf("\n%s",str);
    int len = strlen(str);
    bool is_decimal=false;
    for(int i=0; i<len; i++)
        if(str[i]=='.')
        {
            is_decimal=true;
        }

    if(is_decimal)
    {
        for(int i=0; ; i++)
        {
            if(str[i]=='e')
            {
                char temp[100];
                int len_temp=0;
                for(int j=i+1; j<len; j++)
                {
                    temp[len_temp++] = str[j];
                }
                temp[len_temp] = '\0';
                int x = atoi(temp);
//                printf("x %d\n",x);
                for(i =0; ; i++)
                    if(str[i] == '.')
                        break;
                int j,cnt;
                for( j=i+1, cnt=0; cnt<x; j++,cnt++)
                {
                    if(str[j]=='e')
                    {
                        j--;
                        for(; cnt<x; cnt++,j++)
                        {
                            str[j]= '0';
                        }
                        str[j] ='\0';
                        break;
                    }
                    swap(str[j],str[j-1]);

                }
//                printf("%s j %d\n",str,j);

//
                for(i=0; i<len; i++)
                    if(str[i]=='e')
                    {
                        str[i]='\0';
                        break;
                    }

//                printf("%s\n",str);
                break;
            }
        }
//        printf("%s\n",str);
        len =strlen(str)-1;


        for(int i = len; i>=0; i--)
        {
            if(str[i] == '.')
            {
                for(int i=len; i>=0; i--)
                {
                    if(str[i]!= '0')
                    {
                        str[i+1] = '\0';
                        break;
                    }
                }
                break;
            }
        }
        int i;
        for(i=0; str[i]!= '.'; i++)
        {
            if(str[i]!='0' || str[i+1]=='.')
                break;
        }
        if(str[len] == '.')
            str[len] = '\0';
        for(; i<=len; i++)
        {

            printf("%c",str[i]);

        }
        printf("\n");
    }

    return 0;
}


