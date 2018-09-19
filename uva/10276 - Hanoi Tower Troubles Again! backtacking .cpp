#include <bits/stdc++.h>
using namespace std;
int ara[100]={0},ans[100],n,balls=0;
bool squares[100000001];
void squareGenerator()
{
    for(int i=1; i<=10000;i++)
        squares[i*i] = true;
}
void findMaxBalls(int level)
{
//    if(level== 51)
//        return;
    int i;
    for(i = 1; i<level;i++)
    {
        if(squares[balls+ ara[i]] || ara[i] == 0)
        {
            ara[i]= balls;
            balls+=1;
            findMaxBalls(level);
            return;
        }
    }
    if(i == level)
    {
        ara[i]=balls;
        return;
    }
}
int main()
{
    memset(squares,0,sizeof(squares));
    squareGenerator();

    for(int i =1; i<51; i++)
    {
        for(int j=0; j<51; j++)
            ara[j]=0;
        balls++;
         findMaxBalls(i);
         //cout<<balls<<endl;
         ans[i] = balls;

    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n", ans[n]);
    }
    return 0;
}
