#include <bits/stdc++.h>
using namespace std;
map<int, int> lang;
int audio[200011], subtitle[200011];
int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int n,m,x;
    scanf("%d",&n);

    for(int i=0; i<n;i++)
    {
        scanf("%d",&x);
        lang[x]++;
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++)
        scanf("%d", &audio[i]);

    for(int i=0; i<m; i++)
        scanf("%d", &subtitle[i]);

    int full=0,almost=0;
    int mx_full=0,mx_almost, mx_index=0;
    for(int i=0; i<m; i++) {
        full = lang[audio[i]];
        almost = lang[subtitle[i]];
        if(full > mx_full) {
            mx_full = full;
            mx_almost = almost;
            mx_index = i+1;
        } else if(full == mx_full && almost> mx_almost) {
            mx_almost = almost;
            mx_index = i+1;
        }
    }
    printf("%d\n", mx_index);

    return 0;
}
