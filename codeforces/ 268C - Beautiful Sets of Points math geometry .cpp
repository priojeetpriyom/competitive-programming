#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

unordered_set<int> squares;
int valid [111] [111];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m ,k ,s;

    cin>>n>>m;

    cout<<min(n, m)+1<<endl;

    for(int i=0; i<=min(n, m); i++)
        cout<<i<< " "<<min(n,m)-i<<endl;





    return 0;
}


