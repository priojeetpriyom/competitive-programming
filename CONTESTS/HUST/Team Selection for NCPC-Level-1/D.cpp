#include <bits/stdc++.h>
//#define N 5
//#define ll long long
//int ara[N];
using namespace std;

int main()
{
    int n,ara[5];
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%d",&n)== 1)
    {
        int a, b;
        ara[1]=1,ara[2]=2,ara[3]=3;
        for(int i=0; i<3; i++)
        {
            scanf("%d %d",&a, &b);
//            if(a==n || b==n)
//                n=a+b-n;
            swap(ara[a],ara[b]);
            //printf("ara %d %d %d\n",ara[1],ara[2],ara[3]);
        }
        //printf("n %d\n",n);
        if(n==ara[1])
            n=1;
        else if(n==ara[2])
            n=2;
        else
            n=3;
        printf("%d\n",n);
   }
    return 0;
}

