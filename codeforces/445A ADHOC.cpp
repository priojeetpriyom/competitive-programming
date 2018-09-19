#include <bits/stdc++.h>
using namespace std;

int main()
{
    char preStr[111] [111], str[111] [111];
    int n,m;
    for(int i=0; i<=101; i++)
        {
            int j;
            //char lastChar=0;
            for(j=0; j<=101; j++)
            {
                if((i+j)%2==0)
                    preStr[i] [j] = 'W';
                else
                    preStr[i] [j]= 'B';
            }

        }
    while(scanf("%d %d",&n,&m)==2)
    {
//        memset(str,0,sizeof(str));
        for(int i=0; i<n; i++)
            scanf("\n%s",str[i]);
//        printf("\n\n");
//            for(int i=0; i<n; i++)
//            printf("%s\n",str[i]);
        for(int i=0; i<n; i++)
        {
            int j;
            //char lastChar=0;
            for(j=0; j<m; j++)
            {
                if(str [i] [j] == '.')
                    printf("%c",preStr[i] [j]);
                else
                    printf("%c",str[i] [j]);
            }
            printf("\n");

        }
//        for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<m; j++)
//            {
//                printf("%c",str[i] [j]);
//                str[i][j]=0;
//            }
//            printf("\n");
//        }

    }
    return 0;
}
