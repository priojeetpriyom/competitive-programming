#include <bits/stdc++.h>
using namespace std;

int people[111];
vector<int> connection[1011];
bool visited[1011];
int mn,mx;
void find_possible_path(int n, int cnt) {
//    if(cnt>5011)
//        return;
    if(connection[n].size() == 0) {
        mx = max(mx, cnt);
        return;
    }
    visited[n] = 1;
    for(int i=0; i<connection[n].size(); i++) {
        if(!visited[ connection[n][i] ])
        {

            find_possible_path(connection[n][i], cnt+1);

        }
    }
    visited[ n ] = 0;
}

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for(int tc=1; tc<=t; tc++) {


         int k, n,q,u,v;
         scanf("%d %d %d",&k, &n, &q);

         for(int i=0; i<k; i++) {
            scanf("%d",&people[i]);
         }

         while(q--) {
            scanf("%d %d",&u, &v);
            connection[u].push_back(v);

         }
         mn=INT_MAX;
         for(int i=0; i<k; i++) {
            mx=INT_MIN;
            find_possible_path(people[i],1);
            mn = min(mn,max(mx,1));
//            memset(visited,0,sizeof(visited));
         }
         printf("Case %d: ",tc);
         printf("%d\n",mn);

         for(int i=0; i<1011; i++){

            connection[i].clear();
//            visited[i] = 0;
         }
    }

    return 0;
}

