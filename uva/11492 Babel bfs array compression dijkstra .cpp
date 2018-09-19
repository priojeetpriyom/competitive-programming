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
vector<bool> visited[4004];

int costs[4004];

int n;
void calculate()
{
    int cnt=0;
    queue< struct node > pq;

    struct node curr;
    curr.lang_index = 1;
    curr.cost = 0;
    curr.prevChar=-1;
    curr.len=0;

    pq.push(curr);

    while(!pq.empty())
    {
//        printf("aise\n");
//        cnt++;
        curr = pq.front();
        pq.pop();
//        printf("======= %d ========= size %d curr_cost %d\n", curr.lang_index, connection[curr.lang_index].size(), curr.cost);
        if(curr.lang_index==2)
        {
            costs[2] = min(curr.cost, costs[2]);
            continue;
        }
        for(int i=0; i< connection[curr.lang_index].size(); i++)
        {
//            printf("trav_indx %d => frst %c last %c \n",connection[curr.lang_index] [i].lang_index ,curr.frstChar,curr.prevChar);
//            printf("curr_cost %d ttl_cost %d\n", costs[connection[curr.lang_index] [i].lang_index ], connection[curr.lang_index] [i].len + curr.cost);

//            printf("curr_cost %d ttl_cost %d ",curr.cost,  connection[curr.lang_index] [i].len + curr.cost);

            if( connection[curr.lang_index] [i].frstChar != curr.prevChar &&  (!visited[curr.lang_index] [i] || curr.cost + connection[curr.lang_index] [i].len < costs[connection[curr.lang_index] [i].lang_index] ))
            {
                costs[connection[curr.lang_index] [i].lang_index] = min( costs[connection[curr.lang_index] [i].lang_index], curr.cost + connection[curr.lang_index] [i].len);
//                printf("going %d\n", connection[curr.lang_index] [i].lang_index);
                visited[curr.lang_index] [i] = true;

//                printf("%d ",connection[curr.lang_index] [i].lang_index);
//                if(connection[curr.lang_index] [i].lang_index !=2)
//                    costs[connection[curr.lang_index] [i].lang_index ] = min(costs[connection[curr.lang_index] [i].lang_index], connection[curr.lang_index] [i].len + curr.cost);
//                else
//                    costs[connection[curr.lang_index] [i].lang_index ] = min(costs[connection[curr.lang_index] [i].lang_index ], connection[curr.lang_index] [i].cost + curr.cost);

                struct node next;

                next.lang_index = connection[curr.lang_index] [i].lang_index;
                next.cost = connection[curr.lang_index] [i].len + curr.cost;
                next.prevChar = connection[curr.lang_index] [i].frstChar ;
                pq.push(next);
//                connection[curr.lang_index].erase(connection[curr.lang_index].begin() +i);
//                i--;
            }
//            else printf("not going %d                                 first %c last %c\n", connection[curr.lang_index] [i].lang_index, connection[curr.lang_index] [i].frstChar, curr.prevChar);


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
        string u,v;
        char w[100];
        int lang_index =1 ;
        getchar();
        cin>>u>>v;

        lang[u] = lang_index++;
        lang[v] = lang_index++;
//            cout<<u<<"_"<<lang[u]<<"__"<<v<<"_"<<lang[v]<<"__"<<endl;

        for(int i=0; i<4004; i++)
            costs[i] = INT_MAX;

        for(int i=1; i<=n; i++)
        {
            cin>>u>>v;
            scanf("\n%s", w);
//        cout<<u<<"___"<<v<<"___"<<w<<endl;
//            printf("%s %s %s\n",u,v,w);
            int x,y, len;
            if(!lang[u])
            {
//                cout<<u<<endl;
                lang[u] = lang_index++;
            }

            if(!lang[v])
            {
//                cout<<v<<endl;
                lang[v] = lang_index++;
            }

            x = lang[u];
            y = lang[v];
//            cout<<u<<"_"<<x<<"__"<<v<<"_"<<y<<"__"<<w<<endl;
            len = strlen(w);
            struct node temp;
            temp.lang_index = y;
            temp.frstChar = w[0];
            temp.len = len;
//            cout<<u<<"to "<<v<<" cost "<<len<<" firstChar "<<temp.frstChar<<endl;
            visited[x].push_back(0);
            visited[y].push_back(0);

//            cout<<x<<"to "<<y<<" cost "<<len<<endl;

            connection[x].push_back(temp);
            temp.lang_index = x;
            connection[y].push_back(temp);

//            cout<<x<<"to "<<connection[x] [connection[x].size()-1].lang_index<<" cost "<<connection[x] [connection[x].size()-1].len<<" firstChar "<<connection[x] [connection[x].size()-1].frstChar<<endl;
//            cout<<y<<"to "<<connection[y] [connection[y].size()-1].lang_index<<" cost "<<connection[y] [connection[y].size()-1].len<<" firstChar "<<connection[y] [connection[y].size()-1].frstChar<<endl;
//            w.clear();
//                printf("%s %d; %s %d frstChar %c\n",u,x,v,y,w[0]);


        }


//        for(int i=1; i<lang_index; i++)
//        {
//            printf("%d=> ",i);
//            for(int j=0; j< connection[i].size(); j++) {
//                printf(", %d",connection[i][j]);
//            }
//            printf("\n");
//        }

        calculate();
        if(costs[2]==INT_MAX)
        {
            printf("impossivel\n");
        }
        else
            printf("%d\n",costs[2]);

        lang.clear();
        for(int i=0; i<lang_index; i++)
        {
            connection[i].clear();
            visited[i].clear();
            costs[i] = INT_MAX;
        }
    }


    return 0;
}

