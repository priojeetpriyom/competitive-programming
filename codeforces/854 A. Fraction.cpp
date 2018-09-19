#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;


    for(int a = n/2-(n%2==0); a>0; a++) {
        if(__gcd(a, n-1)==1) {
            cout<<a<<" "<<n-a<<endl;
            return 0;
        }
    }



    return 0;
}


