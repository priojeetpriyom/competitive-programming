#include <bits/stdc++.h>
using namespace std;

struct node
{
    int lang_index,len, cost=0;
    char frstChar, prevChar;
//    bool  operator<(const node& a) const
//    {
//        return cost > a.cost;
//    }
};

map<string, int> lang;
vector< struct node > connection[4004];

int costs[4004];

int n;
void calculate()
{
    int cnt=0;
    queue< struct node > pq;

    struct node curr;
    curr.lang_index = 0;
    curr.cost = 0;
    curr.prevChar=-1;
    curr.len=0;

    pq.push(curr);

    while(!pq.empty())
    {
//        cnt++;
        curr = pq.front();
        pq.pop();
        if(curr.lang_index==1)
        {
            costs[1] = min(curr.cost, costs[1]);
            continue;
        }
//        printf("curr %d => frst %c last %c ",curr.lang_index,curr.frstChar,curr.lastChar);
        for(int i=0; i< connection[curr.lang_index].size(); i++)
        {

            if( connection[curr.lang_index] [i].frstChar != curr.prevChar &&  costs[connection[curr.lang_index] [i].lang_index ] > connection[curr.lang_index] [i].len + curr.cost)
            {
//                printf("%d ",connection[curr.lang_index] [i].lang_index);
//                if(connection[curr.lang_index] [i].lang_index !=2)
                    costs[connection[curr.lang_index] [i].lang_index ] = connection[curr.lang_index] [i].len + curr.cost;
//                else
//                    costs[connection[curr.lang_index] [i].lang_index ] = min(costs[connection[curr.lang_index] [i].lang_index ], connection[curr.lang_index] [i].cost + curr.cost);

                struct node next;

                next.lang_index = connection[curr.lang_index] [i].lang_index;
                next.cost = costs[connection[curr.lang_index] [i].lang_index ];
                next.prevChar = connection[curr.lang_index] [i].frstChar ;
                pq.push(next);
//                connection[curr.lang_index].erase(connection[curr.lang_index].begin() +i);
//                i--;
            }


        }
//        printf("\n");

    }
}


int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);


    while(scanf("%d", &n)==1 && n!=0)
    {
        string u,v,w;
        int lang_index =0 ;
        getchar();
        cin>>u>>v;
        lang[u] = lang_index++;
        lang[v] = lang_index++;

        for(int i=0; i<4004; i++)
            costs[i] = INT_MAX;

        for(int i=1; i<=n; i++)
        {
            cin>>u>>v>>w;
//        cout<<u<<"___"<<v<<"___"<<w<<endl;
//            printf("%s %s %s\n",u,v,w);
            int x,y, len;
            if(!lang[u])
            {
                lang[u] = lang_index++;
            }

            if(lang[v])
            {
                lang[v] = lang_index++;
            }

            x = lang[u];
            y = lang[v];

            len = w.length();
            struct node temp;
            temp.lang_index = y;
            temp.frstChar = w[0];
            temp.len = len;

            connection[x].push_back(temp);
            temp.lang_index = x;
            connection[y].push_back(temp);

//                printf("%s %d; %s %d frstChar %c\n",u,x,v,y,w[0]);


        }

        calculate();
        if(costs[1]==INT_MAX)
        {
            printf("impossivel\n");
        }
        else
            printf("%d\n",costs[1]);

        lang.clear();
        for(int i=0; i<4004; i++)
        {
            connection[i].clear();
        }
    }


    return 0;
}


