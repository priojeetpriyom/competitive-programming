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


    int a, b;
    cin>>a>>b;
    int diff = abs(a-b);
    int sum=0;
    if(diff%2==0) {
        sum = (diff/2) * (diff/2 + 1);
    } else {
        sum = (diff/2) * (diff/2 + 1);
        sum+= diff/2 +1;
    }

    cout<<sum<<endl;


    return 0;
}


