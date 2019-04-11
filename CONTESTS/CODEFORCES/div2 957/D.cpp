#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100


int up[MX], need[MX];


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin>>n;

    for(int i=1; i<=n; i++) {
        cin>>up[i];
    }

    int prev=0;
    int pos = n;
    for(int i = n; i>0; i--) {
        if(up[i]>prev - max(0, pos-i-1)) {
            prev = up[i];
            pos = i;
        }
        need[i] = (prev - max(0, pos-i-1));
    }
    ll ans=0;
    int cur_size=0;
    for(int i=1; i<=n; i++) {
        if(up[i]==cur_size) {
            cur_size += 1;
        }
        else {
            if(need[i]>cur_size)
                cur_size++;
            ans+= (cur_size-up[i]-1);
        }
        printf("i %d cur_size %d need %d ans %lld\n", i, cur_size, need[i], ans);
    }

    cout<<ans<<endl;


    return 0;
}


