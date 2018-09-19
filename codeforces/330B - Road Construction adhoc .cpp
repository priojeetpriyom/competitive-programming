#include <bits/stdc++.h>
using namespace std;

bool isRestcited[1001];
int main()
{
    //freopen("myOutput.txt","w",stdout);
    //freopen("myInput.txt",")
    int m,n;
    int x,y;
    scanf("%d %d",&n, &m);
    for(int i=0; i<m;i++)
    {
        scanf("%d %d",&x,&y);
        isRestcited[x]=isRestcited[y]=true;
    }
    int element=0;
    for(int i=1; i<=n;i++)
    {
        if(!isRestcited[i])
        {
            element= i;
            break;
        }
    }
    if(element==0)
    {
        printf("0\n");
        return 0;
    }
    printf("%d\n",n-1);
    for(int i=1;i<=n;i++)
    {
        if(i!=element)
            printf("%d %d\n",i,element);
    }
    return 0;
}


