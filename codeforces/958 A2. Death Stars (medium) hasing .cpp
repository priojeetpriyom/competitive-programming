#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 1100
#define double long double

char a[2020] [202], b[202] [2020];
map<ull, int> mp;
ull base =257;
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n, m;

    cin>>n>>m;

    for(int i=1; i<=n; i++) {

        a[i][0]=' ';
        scanf("\n%s", a[i]+1);
    }
//    for(int i=1; i<=n; i++)
//        cout<<a[i]<<endl;

    for(int i=1; i<=m; i++){
        b[i][0]=' ';
        scanf("\n%s", b[i]+1);
    }
//    for(int i=1; i<=m; i++)
//        cout<<b[i]<<endl;

    for(int i=1; i<=n-m+1; i++) {
        ull hash=0, pw=1;
        for(int j = 1; j<= m; j++) {
            for(int k =i; k<i+m; k++) {
                hash += pw* b[j][k];
                pw*=base;
            }
        }
        mp[hash] = i;
//        cout<<"i "<<i<<" hash "<<hash<<endl;
    }

    for(int i=1; i<=n-m+1; i++) {
        ull hash=0, pw=1;
        for(int j = i; j< i+m; j++) {
            for(int k =1; k<=m; k++) {
                hash += pw* a[j][k];
                pw*=base;
            }
        }
//        cout<<"i "<<i<<" hash "<<hash<<endl;
        if(mp.find(hash) != mp.end()) {
//            cout<<i<<" "<<mp[hash]<<endl;
            printf("%d %d\n", i, mp[hash]);
            return 0;
        }
    }


    return 0;
}
