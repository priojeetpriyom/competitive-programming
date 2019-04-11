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

    int n, a, b;

    cin>>n>>a>>b;
    if(a==b) {
        cout<<1<<endl;
        return 0;
    }

    int tot = (log2(n));

    int need = log2(abs(a-b) )+1;

    if(need==tot)
        cout<<"Final!"<<endl;
    else
        cout<<need<<endl;



    return 0;
}


