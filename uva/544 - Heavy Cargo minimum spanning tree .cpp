#include <bits/stdc++.h>
using namespace std;



int vis[222];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n, r;
    int tc=1;

    while(cin>>n>>r && !(n==0 && r==0))
    {
        int idx=1;
        unordered_map<string, int> mp;
        vector<pair<int, int> > conn[222];
        set<tuple<int,int, int>> sset;
        string s1, s2;
        int u,v,cost;
        for(int i=0; i<r; i++ )
        {
            cin>>s1>>s2>>cost;
            if(!mp[s1]) mp[s1]=idx++;
            if(!mp[s2]) mp[s2] = idx++;
//            cout<<s1<<" "<<mp[s1]<<","<<s2<<" "<<mp[s2]<<endl;

            u = mp[s1];
            v= mp[s2];
            conn[u].push_back(make_pair(v, cost));
            conn[v].push_back(make_pair(u, cost));
        }
        cin>>s1>>s2;

        if(!mp[s1]) mp[s1]=idx++;
        if(!mp[s2]) mp[s2] = idx++;

        u = mp[s1];
        v = mp[s2];
        int mx_cost = 1e6;
//        int cur_u;
        tuple<int, int, int> cur_tuple;
        pair<int, int> cur_pair;
        int len = conn[u].size();
        for(int i=0; i<len; i++)
        {
            cur_pair = conn[u][i];
            sset.insert(make_tuple(cur_pair.second,u,cur_pair.first));
        }
        vis[u]=1;
        int cur_u, cur_v;
//        printf("u %d v %d\n", u, v);
        while(sset.size())
        {
            cur_tuple = *(sset.rbegin());
            sset.erase(--sset.end());

            cur_u = get<1>(cur_tuple);
            cur_v = get<2>(cur_tuple);
            cost = min(cost, get<0>(cur_tuple));
            if(cur_u==v || cur_v==v) break;
            if(vis[cur_u]!=tc) swap(cur_u, cur_v);
            vis[cur_v]=tc;

            len = conn[cur_v].size();

//            printf("cur_u %d cur_v %d\n", cur_u, cur_v);
            for(int i=0; i<len; i++)
            {

                cur_pair = conn[cur_v][i];
                if(vis[cur_pair.first]!=tc )
                    sset.insert(make_tuple(cur_pair.second,cur_v,cur_pair.first));
            }

        }
        cout<<"Scenario #"<<tc++<<endl;
        cout<<cost<<" tons"<<endl<<endl;;

    }


    return 0;
}


