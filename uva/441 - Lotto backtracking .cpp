#include <bits/stdc++.h>
using namespace std;
int n,ara[20],temp[20];

void findPossibleGame(int i, int len)
{
    if(len== 6)
    {
        for(int j=0; j<len; j++)
        {
            if(j>0)
                printf(" ");
            printf("%d",temp[j]);
        }
        printf("\n");
    }
    for( ; i<n; i++)
    {
        temp[len] = ara[i];
        findPossibleGame(i+1,len+1);
    }

}

int main()
{
    bool newLine=false;
    while(scanf("%d",&n)==1 && n!=0)
    {
        for(int i=0; i<n; i++)
            scanf("%d",&ara[i]);
        if(newLine)
            printf("\n");
        else
            newLine= true;
        findPossibleGame(0, 0);
    }
    return 0;
}
