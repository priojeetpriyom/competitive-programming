#include <bits/stdc++.h>
using namespace std;

int ara[30001];
vector <int> vec[30001];
vector<int> dist[30001];
bool isAvailable[30001];
int mx_dist=0, mx_pos;

struct node
{
    int dist=0;
    int pos=0;
};
node currentNode;
int bfs()
{
    stack <node> S;
    S.push(currentNode);
    while(S.size())
    {
        currentNode = S.top();
        S.pop();
        isAvailable[currentNode.pos]=false;

        for(int i=0; i< vec[currentNode.pos].size(); i++)
        {
            if(isAvailable[vec[currentNode.pos] [i]])
            {
                struct node newNode;
                newNode.pos = vec[currentNode.pos] [i];
                newNode.dist = currentNode.dist + dist[currentNode.pos] [i];

                if(newNode.dist> mx_dist)
                    {
                        mx_dist=newNode.dist;
                        mx_pos = newNode.pos;
                    }
                S.push(newNode);
                isAvailable[vec[currentNode.pos] [i]]=false;
            }
        }

    }

}

int main()
{

//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w",stdout);

    int n, t;
    scanf("%d", &t);

    for(int i=1; i<= t; i++)
    {
        mx_dist=0;
        scanf("%d",&n);
        for(int j = 0; j<=n; j++)
        {
            ara[j]=0;
            vec[j].clear();
            dist[j].clear();
            isAvailable[j]= true;
        }

        n--;
        int u,v,w;
        int mx=0,mx_i,mx_j;
        for(int j=0; j<n; j++)
        {
            scanf("%d %d %d",&u, &v, &w);
//            if(u>v)
//                swap(u,v);
//            if(w>mx)
//            {
//                mx=w;
//                mx_i=u;
//                mx_j=v;
//            }
            vec[u].push_back(v);
            vec[v].push_back(u);

            dist[u].push_back(w);
            dist[v].push_back(w);
        }

//        for(int p=0; p<=n; p++)
//        {
//            for(int q=0; q< vec[p].size(); q++)
//            {
//                printf("%d %d %d\n",p, vec[p] [q], dist[p][q]);
//            }
//        }
//        long long sum=0;
        for(int j=0; ; j++)
        {
            if(vec[j].size()==1)
            {
                currentNode.pos= j;
                currentNode.dist=0;
                bfs();
                break;
            }
        }

        mx_dist=0;
        currentNode.pos = mx_pos;
        currentNode.dist=0;
        for(int j=0; j<=n; j++)
            isAvailable[j]=true;
        bfs();
//        for(int j=0; j<=n; j++)
//            isAvailable[j]=true;
//        currentNode.pos = mx_j;
//        currentNode.dist=0;
//        bfs();
//        sum = max(sum, mx_dist);
//        for(int j= 0; j< n; j++)
//        {
//            int mx = INT_MIN, mx_pos=30000;
//            for(int k =0; k< vec[j].size(); k++)
//            {
//                if(isAvailable[vec[j] [k]])
//                {
//                    mx = max(mx, ara[vec[j] [k]]);
//                    mx_pos =  vec[j] [k];
//                }
//            }
//            isAvailable[mx_pos] = false;
//            if(mx != INT_MIN)
//                sum+=mx;
//        }
        printf("Case %d: %d\n",i,mx_dist);
        mx_dist=0;
//        printf("mxd %d\n",mx_dist);
    }

    return 0;
}


