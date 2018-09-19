#include<bits/stdc++.h>
using namespace std;
vector<int> connection[111], dist[111];
int visited[111];
bool bfs(int u, int v, int lim) {
    queue<int> Q;
    memset(visited, 0 ,sizeof visited);

    Q.push(u);
    int cur;

    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        visited[cur] = 1;
        if(cur ==v)
            return true;
        int len = connection[cur].size();
        for(int i=0; i<len; i++) {
            int next = connection[cur] [i];
            if(dist[cur] [i] <=lim && !visited[next] ) {
                Q.push(next);
            }
        }
    }
    return false;
}

int getMinAudio(int high, int low, int mid, int u, int v) {
    int lim = INT_MAX;
    while(high >=low) {
        mid = (high+low)>>1;
        if(bfs(u, v, mid)) {
            if(mid<lim)
                lim = mid;
            high = mid-1;
        } else
            low = mid+1;
    }
    return lim;
}

int main()
{
    int n, c,s,q;
    int tc=1;

    while(scanf("%d %d %d",&c, &s, &q) == 3 && c!=0) {
        if(tc>1)
        printf("\n");
        printf("Case #%d\n", tc++);
        int u,v,d,mxDist=0;
        for(int i=0; i<s; i++) {
            scanf("%d %d %d", &u, &v, &d);
            connection[u].push_back(v);
            connection[v].push_back(u);
            if(d>mxDist)
                mxDist = d;
            dist[u].push_back(d);
            dist[v].push_back(d);
        }

        while(q--) {
            scanf("%d %d", &u, &v);
            int x = getMinAudio(mxDist, 0, (mxDist)/2, u, v);
            if(x == INT_MAX)
                printf("no path\n");
            else
                printf("%d\n", x);
        }
        for(int i=0; i<111; i++) {
            connection[i].clear();
            dist[i].clear();
        }
    }
    return 0;
}

