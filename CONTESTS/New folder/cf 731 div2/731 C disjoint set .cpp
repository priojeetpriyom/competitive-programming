#include <bits/stdc++.h>
using namespace std;

int ara[210000], par[210000];
map<int, bool> parents;
map<int, int> elements;
map<int, int> :: iterator it;
int find_par(int r) {
    return (par[r] == r)? r : par[r] = r;
}


int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);

    for(int i=1; i<=n; i++)
    {
        scanf("%d", &ara[i]);
        par[i] = i;
    }
    int u,v;
    while(m--) {

        scanf("%d %d", &u, &v);
        int x = find_par(u);
        int y = find_par(v);
        par[y] = x;
        find_par(v);
    }
int ans=0;

    for(int i=1; i<=n; i++) {
          printf("aiseee %d\n",i);
        if(!parents[par[i]]) {
            int cnt=0;
            for(int j = i+1; j<=n; j++) {
                if(par[j] == par[i]) {
                    cnt++;
                    elements[ara[j]]++;
                }
            }
            parents[par[i]] =1;
//            it = elements.rbegin();
//            --it;
//int x = elements.rbegin();
            ans += (cnt - (elements.rbegin())->second);
            elements.clear();
        }
    }

    printf("%d\n", ans);

    return 0;
}
