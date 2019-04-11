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

    int n, m;

    int c[1111], a[1111];

    for (int i = 0; i < n; i++) {
      cin>>c[i];
    }
    int ans=0;
    for (int i = 0; i < m; i++) {
      cin>>a[i];
    }
    a[n] = -1;
    int pos=0;
    for(int i=0; i<n; i++) {
      if(c[i]<=a[pos]) {
        ans++;
        pos++;
      }
    }

    std::cout << ans << '\n';
    return 0;
  }
