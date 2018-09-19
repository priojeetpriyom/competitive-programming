#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


map< pair<int, int>, int> mp;
int update[300100], deg[300100, bad_deg[300100], d[300100];
vector<int> conn[300100];
map<int, pair<int, int>> mp2;

//bool fail(int u)
//{
//
//    int len = conn[u].size();
//
//    for(int i=0; i<len; i++)
//        if(d[conn[u][i] ] == -1)
//        {
//            if(mp.find(make_pair(u,conn[u][i])) != mp.end())
//                mp[make_pair(u,conn[u][i])]= -1;
//            else mp[make_pair(conn[u][i],u) ] = -1;
//
//
//            return false;
//        }
//
//    return true;
//
//}
set<pair<int, int>> sset;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n, m;

    scanf("%d %d", &n, &m);

    int u,v;
    for(int i=1; i<=n; i++)
        scanf("%d", &d[i]);
    for(int i=0; i<m; i++)
    {

        scanf("%d %d", &u, &v);
//        if(u>v)
//            swap(u,v);
        mp[make_pair(u,v)]=i;
        deg[u]++;
        deg[v]++;
        conn[u].push_back(v);
        conn[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        int len = conn[i].size();

        for(int j=0; j<len; j++) {
            if(d[conn[i][j] ]!=-1 && (deg[conn[i][j] ]&1)!= d[conn[i][j]])
                bad_deg[i]++;
        }

    }


    for(int i=1; i<=n; i++)
    {
        int len = conn[i].size(), f=0;
        if(len < d[i])
        {
            printf("-1\n");
            return 0;
        }
        if(d[i]!= -1 && ( (deg[i]&1) != d[i] ) )
        {
//            printf("i %d d[i] %d\n", i, d[i]);

            sset.insert(make_pair(bad_deg[i], i));
        }

    }

    while(sset.size()) {
        u = (*sset.begin()).second;
    }




//    for(int i=1; i<=n; i++)
//        if(update[i] && fail(i))
//        {
////            printf("i %d still to be updated\n", i);
//            int len = conn[i].size(), f=0;
//            for(int j=0; j< len; j++)
//            {
//                if(d[conn[i][j] ]!= -1 )
//                {
//                    f=1;
//                    if(mp.find(make_pair(i,conn[i][j])) != mp.end())
//                        mp[make_pair(i,conn[i][j])]= -1;
//                    else mp[make_pair(conn[i][j],i) ] = -1;
//                    update[i]= 0;
//                    update[conn[i][j] ]=0;
//                    break;
//                    if(!f)
//                    {
//                        printf("-1\n");
//                        return 0;
//                    }
//                }
//
//
//            }
//
//
//
//
//        }
//    map<pair<int, int>, int> :: iterator it;
//    int len_ans=0;
//    for(it = mp.begin(); it!= mp.end(); it++)
//    {
//        if(it->second != -1)
//        {
//            mp2[it->second] = it->first;
//        }
//    }
//
//    map<int, pair<int, int> > :: iterator it2;

    printf("%d\n", mp2.size());

    for(it2 = mp2.begin(); it2!= mp2.end(); it2++)
    {
        printf("%d\n", it2->first+1);
    }





    return 0;
}



