#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

int ara[MX];


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

        if(n==1) {
          cout<<-1<<endl;
          return 0;
        }
            if(n==2) {
              int x, y;
              cin>>x>>y;
              if(x==y)
                cout<<-1<<endl;
              else
                  cout<<1<<endl;
              return 0;
            }


      for(int i=1; i<=n; i++) {
        cin>>ara[i];
      }

      int mn = 1e9, pos;

      for(int i=1; i<=n; i++) {
        if(ara[i]<mn)
          {
            mn = ara[i];
            pos = i;
          }
      }

cout<<1<<endl;
  cout<<pos<<endl;

    return 0;
}
