#include<bits/stdc++.h>
using namespace std;



void setVal(int visited[], int pos, int ara[])
{
//    if(pos ==1)
//    {
//        visited[ara[0] + ara[1] ] =1;
//        return;
//    }
//    printf("aise\n");
    for(int i=999; i>0; i--)
        if(visited[i] && (ara[pos]+i <= 1000))
            visited[i+ ara[pos]] =1;

    visited[ara[pos]]=1;
}

bool rec(int ara[], int pos, int lim, int visited[])
{
//    printf("pos %d\n", pos);
    if(pos == lim)
    {
//        printf("pos now %d lim %d\n", pos, lim);
        return true;
    }
    if(visited[ara[pos]]==1 || ara[pos] <= ara[pos-1])
    {
//        printf("val %d visited %d\n", ara[pos], visited[ara[pos]]);
        return false;
    }

    setVal(visited, pos, ara);
//    printf("after setting\n");
//    for(int i=1; i<20; i++)
//        printf("%d ", visited[i]);
//    printf("\n");
    bool x = rec(ara, pos+1, lim, visited);
//    setVal(visited, pos, -1, ara);
    return x;
}

int main()
{
//    freopen("myOut.txt", "w", stdout);
    int tc=1,n;
    int ara[35];
    int visited[1010];
    while(scanf("%d", &n) == 1)
    {
        for(int i=0; i<n; i++)
            scanf("%d", &ara[i]);
//        printf("fsdfsd");
        memset(visited, 0, sizeof (visited));
//        for(int i=0; i<30001; i++)
//            visited[i]=0;
        printf("Case #%d:", tc++);
        for(int i=0; i<n; i++)
            printf(" %d",ara[i]);
        printf("\n");
        visited[ara[0]] =1;
        if(rec(ara,1, n, visited ) && ara[0]>0)
            printf("This is an A-sequence.\n");
        else
            printf("This is not an A-sequence.\n");
    }
    return 0;
}

