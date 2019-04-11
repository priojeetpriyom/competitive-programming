#include<stdio.h>
#include<string.h>

char x[100000],y[100000]={"^_^"};

int len_x,len_y;
int dp[1000][1000];

int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void printLCS(int i, int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    if(x[i-1]==y[j-1])
    {
       printLCS(i-1,j-1);
       printf("%c",x[i-1]);
    }
    else if(dp[i][j]==dp[i-1][j])
    {
        printLCS(i-1,j);
    }
    else
    {
        printLCS(i,j-1);
    }
}

int main()
{
    int i,j,tcase,z=0;
    scanf("%d\n",&tcase);

    while(tcase--)
    {
        gets(x);//Main String
        //gets(y);//Sub_String
        len_x=strlen(x);
        len_y=strlen(y);

        printf("%d %d\n",len_x,len_y);

        memset(dp,0,sizeof(dp));

        for(i=1;i<=len_x;i++)
        {
            for(j=1;j<=len_y;j++)
            {
                if(x[i-1]==y[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        printf("Max LCS_Length: %d\n",dp[len_x][len_y]);
        printf("Case %d: %d\n",++z,(dp[len_x][len_y])/len_x);

        printLCS(len_x,len_y);
        printf("\n");
    }
    return 0;
}

