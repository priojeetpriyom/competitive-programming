#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    ll n, k;

    cin>>n>>k;

    if( (k+1) > ( (n*2)/k) ) return printf("-1\n"), 0;

    int root = ceil(sqrt(n));
    ll ii=-1;
    for(int i=root; i>0; i--)
    {
        ll ans = (1 * (2*i + (k-1)*i )  )/2;
        if(ans<= (n/k) && n%i==0)
        {
            if(i>ii) ii=i;
            if(n/i > ii &&  ((1 * (2*(n/i) + (k-1)*(n/i) )  )/2) <= (n/k)  ) ii = n/i;
//            return 0;
        }
    }

    if(ii!= -1)
    {
        ll x, sum=0;
        for( x =0 ; k>1; k--)
        {
            x+=ii;
            sum+=x;
            printf("%I64d ", x);
        }
//            cout<<"x "<<x<<endl;
        printf("%I64d\n", n - sum);
    }
    else
        printf("-1\n");
    return 0;

}
