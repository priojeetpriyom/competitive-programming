/*
    IDEA:

    complexity:
    algo:

*/
//
//
//#include<stdio.h>
//#include<string.h>

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 50005

int ara[MX*3];
int updates[MX][3], queries[MX];


int main()
{
//freopen("output.txt", "w", stdout);

//    process[0]= {1,2,3};

//    cout<<process[0].id<<" "<<process[0].at<<" "<<process[0].bt<<endl;
    int t;
    scanf("%d", &t);
//    memset(ncr, -1, sizeof ncr);
//    memset(dp, -1, sizeof dp);
//        for(int i=1; i<MX; i++)
//        {
//            dist[i] = 1<<30;
//        }
    for(int tc=1; tc<=t; tc++)
    {
//        memset(tree, 0, sizeof tree);
        memset(ara, 0, sizeof ara);
//    len=0;
//        memset(dist, -1, sizeof dist);
//        memset(vis, 0, sizeof vis);
        int n,q;
        scanf("%d %d", &n, &q);
        map<int, int> mp;
//        int l, r;
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d", &updates[i][1], &updates[i][2]);
            mp[updates[i][1]] = 0;
            mp[updates[i][2]] = 0;
        }
        printf("Case %d:\n", tc);
        for(int i=1; i<=q; i++)
        {
            scanf("%d", &queries[i]);
            mp[queries[i]] =0;
        }
        int idx=0;
        for(map<int, int> :: iterator it = mp.begin(); it!= mp.end(); it++)
        {
            it->second = ++idx;
        }

        for(int i=1; i<=n; i++)
        {
//            scanf("%d %d", &updates[i][1], &updates[i][2]);
            updates[i][1] = mp[updates[i][1]];
            updates[i][2] = mp[updates[i][2]];
        }

        for(int i=1; i<=q; i++)
        {
//            scanf("%d", &queries[i]);
            queries[i] = mp[queries[i]];
        }

        for(int i=1; i<=n; i++)
        {
//            scanf("%d %d", &updates[i][1], &updates[i][2]);
            ara[updates[i][1]]++;
            ara[updates[i][2]+1]--;
        }
        for(int i=1; i<=idx; i++)
            ara[i]+= ara[i-1];

        for(int i=1; i<=q; i++)
        {
            printf("%d\n", ara[queries[i] ]);
        }

    }
//    printf("\n");


    return 0;
}

