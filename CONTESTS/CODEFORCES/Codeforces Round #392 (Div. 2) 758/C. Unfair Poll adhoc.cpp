#include <bits/stdc++.h>
using namespace std;

int main()
{
//        freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    long long n,m,k,x,y;
    while(cin>>n>>m>>k>>x>>y) {

    long long into = (n*m)-m, mul=0,s=0;
    long long mn=0, mx=0;
long long pos=0;
    if(n==1)
    {
        mul = (k/m);
        k%=m;
        long long a =(k>0)?1:0;
        printf("%I64d ", mul+a);
        printf("%I64d ",mul);
        a = (y<=k)? 1:0;
        printf("%I64d\n",mul+a);
        return 0;
    }

    else if(k>= n*m)
    {
        k-=m;
        mul = k/into;
        k%=into;
        mn = (mul+1)>>1;
        if(n==2)
        {
            mx= mn;
            if(mul%2 ==0 || k>0)
                mx++;
        }
        else {
            mx= mul;
            if(k>0)
                mx++;
        }
        if(x==1) {
            pos =mn;
            if(mul%2==0)
                pos++;
        } else if(x==n) {
            pos = mn;
        } else {
            pos = mul;
        }
    } else mx=1;


    long long ans=0;
//    printf("k %I64d mul %I64d\n", k, mul);

//    if(k> 0 && n!=2)
//    {
//        p++;
//    }
//    if(x==1 && mul%2==0 && mul>0)
//        ans++;
//    else
        if(mul%2==0 && mul>0)
    {
        for(int i=2; k>0 && i<=n; i++)
        {
            for(int j=1; k>0 && j<=m; j++)
            {
                k--;
                if(i == x && j==y)
                {
                    ans++;
                    break;
                }
            }

        }
    }
    else if(mul>0)
    {
        for(int i=n-1; k>0 && i>0; i--)
        {
            for(int j=1; k>0 && j<=m; j++)
            {

                k--;
                if(i == x && j==y)
                {
                    ans++;
                    break;
                }
            }

        }
    } else {
        for(int i=1; k>0 && i<=n; i++)
        {
            for(int j=1; k>0 && j<=m; j++)
            {
                k--;
                if(i == x && j==y)
                {
                    ans++;
                    break;
                }
            }

        }
    }
//    printf("ans %I64d mul %I64d\n", ans, mul);

//    if(n==2)
//    {
//        if(mul%2==0)
//            mul=1;
//        else mul=0;
//        mul+=mn;
//        pos = mn;
//
//    }
//    else if(x==n || x==1)
//    {
//        pos = mn;
//    }
//    else
//        pos = mul;


    printf("%I64d %I64d %I64d\n", mx, mn, pos+ans);
    }
    return 0;
}






