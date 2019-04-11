#include <bits/stdc++.h>
using namespace std;

vector<int> storage;
vector<int> vec[100005],dist[100005];


 map<int,int> mp;

int main()
{
//    freopen("myOutput.txt","w",stdout);
storage.clear();
    for(int i=0; i<100005; i++)
    {
        vec[i].clear();

        dist[i].clear();

    }
    mp.clear();
    int n,m,k,d;
    scanf("%d %d %d",&n, &m, &k);

    for(int i=0; i<m; i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a, &b, &c);
        vec[a].push_back(b);
        vec[b].push_back(a);
        dist[a].push_back(c);
        dist[b].push_back(c);
    }
    for(int i=0; i<k; i++)
    {
        int a;
        scanf("%d",&a);
        storage.push_back(a);
        mp[a]=1;
    }
    int mn=INT_MAX;
    if(n==k || k==0)
    {
        printf("-1\n");
    }
    else
    {
        std:map<int,int>:: iterator it;
        k = storage.size();
        for(int i=0; i<k; i++)
        {
            int x = storage[i];
            if(vec[x].size()!=0) {
                for(int j=0; j<vec[x].size(); j++) {
                    it= mp.find(vec[x][j]);
                    if(it == mp.end()) {
                        if(dist[x][j]<mn)
                            mn = dist[x][j];
                    }
                }
            }
        }
        bool oka = false;

        if(mn == INT_MAX)
        {
            mn= -1;
        }
        printf("%d\n",mn);
    }

    return 0;
}
