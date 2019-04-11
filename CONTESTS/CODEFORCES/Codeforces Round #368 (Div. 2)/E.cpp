#include<bits/stdc++.h>
using namespace std;
#define sq(n) sqrt(n)
#define ll long long int
#define mem(n) memset(n,0,sizeof(n))
#define tst int tst; scanf("%d",&tst) ; while(tst--)
#define LCM(a,b) (a / __gcd(a,b) ) * b
#define gcd(a,b) __gcd(a,b)
#define Case printf("Case %d: ",cs++);
#define for0(l,n) for(int l=0;l<n;l++)
#define for1(l,n) for(int l=1;l<=n;l++)
#define ulta(n) for(int i=n-1;i>=0;i--)
#define bug(n) cout<<">> "<<n<<" <<";
#define szv(v) v.size()
#define sz(a) sizeof(a)
#define YES printf("YES\n")
#define NO printf("NO\n")
#define Yes printf("Yes\n")
#define No printf("No\n")
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define cl(v) v.clear;

vector<int>v;

//  vector<long long>vll;
//  map<long long,bool>mp;

int rev(int a)
{
    int  revv = 0;
    int n = a;
    while(n != 0)
    {
        int remainder = n%10;
        revv = revv*10 + remainder;
        n/=10;
    }
    return revv;
}


int main()
{
    ll n;
    cin>>n;
    if(n==1||n==2)cout<<"-1"<<endl;
    else if(n%2==1)
        cout<<((n*n)/2)<<" "<<((n*n)/2+1)<<endl;
    else if( ((n*n)/4-1)*((n*n)/4-1)+n*n== ((n*n)/4+1)*((n*n)/4+1)&&((n*n)/4-1)>n ) cout<< ((n*n)/4-1)<<" "<<((n*n)/4+1)<<endl;

    else cout<<"-1"<<endl;

}
