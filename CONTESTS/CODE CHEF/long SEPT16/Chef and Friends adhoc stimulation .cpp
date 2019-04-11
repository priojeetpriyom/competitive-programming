#include <bits/stdc++.h>
using namespace std;

bool friends[1002] [1002];
vector<int> frnds[1002];
bool belongs_to(vector<int> table,int u )
{
    int len = table.size();

    int x,y;
    for(int i=0; i<len; i++)
    {

        if(friends[table[i]] [u]!=1)
        {

            return false;
        }
//        else
//        {
//            int len1= frnds[u].size(), len2 = frnds[table[i]].size();
//            len2 = min(len1,len2);
//
//            for(int j=0; j<len2; j++)
//            {
//                if(frnds[table[i]] [j]!= frnds[u][j])
//                {
//
//                    return false;
//                }
//            }
//        }

    }
    return true;

}

int main()
{
//    freopen("myOutput.txt","w",stdout);

    int t;
    scanf("%d",&t);
    vector<int> table1,table2;
    while(t--)
    {
        memset(friends,0,sizeof(friends));
        int n,m;
        scanf("%d %d",&n,&m);
        int u,v;
        for(int i=0; i<1002; i++)
            frnds[i].clear();
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&u,&v);

            friends[u][v] =1;
            friends[v][u] =1;
            frnds[u].push_back(v);
            frnds[v].push_back(u);
//            printf("u %d v %d\n",u,v);

        }
        table1.clear();
        table2.clear();
//        printf("us %d vs %d\n",us[0],vs[0]);

        for(int i=1; i<=n; i++)
        {

//            printf("oka");
//            int x=0;

            if(belongs_to(table1,i))
            {
//                x=1;
//                printf("oka\n");

                table1.push_back(i);

//                for(int i=0; i<table1.size(); i++)
//                    printf("%d ",table1[i]);
//                printf("pint ches\n");

            }
            else if(belongs_to(table2,i))
            {
//                x=2;
//                printf("aise");

                table2.push_back(i);
            }
            else
            {
                n= -1;
                printf("NO\n");
                break;
            }
//            printf("dhukse %d\n",x);
//            printf("i %d\n",i);
        }
//        for(int i=0; i<table1.size(); i++)
//            printf("%d ",table1[i]);
//        printf("\n");
//
//        for(int i=0; i<table2.size(); i++)
//            printf("%d ",table2[i]);
//        printf("\n");

        if(n!= -1)
            printf("YES\n");


    }


    return 0;
}

