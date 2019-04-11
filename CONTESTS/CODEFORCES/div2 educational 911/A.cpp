#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 15
int ara[100100];

int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    int n, a, b;

    cin>>n;
    int num  = 2e9;
   for(int i=0; i<n; i++)
    {

        cin>>ara[i];
        num = min(num, ara[i]);
    }

    int pos= -1, mn = 1e9;
   for(int i=0; i<n; i++) {
        if(ara[i] == num) {
            if(pos==-1) {

            } else
                mn = min(mn, i-pos);
            pos = i;
        }
   }

    cout<<mn<<endl;

    return 0;
}

