#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOutput.txt","w",stdout);

    int tcase;
    scanf("%d",&tcase);

    for(int t=1; t<=tcase; t++) {
        int cost[102];
        int n,m;
        int current_node=0;
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++) {
            scanf("%d",&cost[i]);
            if(cost[i]==0)
                current_node=i;
        }
        int sum=0;
        vector<int> connection[102];
        while(m--) {

            int u,v;
            scanf("%d %d",&u,&v);
            connection[u].push_back(v);
        }


        while(connection[current_node].size()>0) {

            int mx=INT_MIN,mx_i=current_node;

            for(int i=0; i<connection[current_node].size(); i++) {
                if(cost[connection[current_node][i]] > mx) {
                    mx_i = connection[current_node][i];
                    mx = cost[connection[current_node][i]];
                }
            }
            current_node=mx_i;
            sum+=cost[current_node];
//            printf("curren node %d sum %d\n",current_node,sum);
        }


        printf("Case %d: %d %d\n",t,sum,current_node);

        for(int i=0; i<101; i++) {

        connection[i].clear();

        }
    }

    return 0;
}
