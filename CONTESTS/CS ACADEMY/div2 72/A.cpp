#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int t = n;
    int sum=0;
    while(n>0)
    {
        sum = sum * 10 + (n%10);
        n/=10;
    }
//    cout<<sum<<endl;
    cout<<(sum>t);


    return 0;
}


