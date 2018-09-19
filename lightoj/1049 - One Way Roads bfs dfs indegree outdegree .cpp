#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 105

int n, tc, m;

struct node
{
    vector<int> in, out;

};

vector<node> conn(MX); //, cnt[1010];

int cost[MX] [MX];


int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    ll t, q;
    cin>>t;
    cin.ignore();
    for(tc=1; tc<=t; tc++)
    {
//        memset(vis, -1, sizeof vis);
        cin>>n;

        for(int i=1; i<=n; i++)
        {
            conn[i].in.clear();
            conn[i].out.clear();
        }
        for(int i=1; i<=n; i++)
        {
            int u, v, c;
            cin>>u>>v>>c;
            cost[u][v] = cost[v][u]= c;
            conn[u].out.push_back(v);
            conn[v].in.push_back(u);

//            conn[u].cost = conn[v].cost = c;
        }

        int cur=-1, prevv= -1;
        int inCost=0, outCost=0;
        while(cur!= 1)
        {
            if(cur==-1)
                cur=1;
            vector<int> &in = conn[cur].in;
            vector<int> &out = conn[cur].out;
            int nextt=0;
            for(int i=0; i< out.size(); i++)
            {
                if(out[i]!= prevv)
                {
                    nextt = out[i];
                    inCost+= cost[cur ] [ out[i] ];
                    break;
                }
            }
            if(!nextt )
            {

                for(int i=0; i< in.size(); i++)
                {
                    if(in[i]!= prevv)
                    {
                        nextt = in[i];
                        outCost+= cost[cur ] [ in[i] ];
                        break;
                    }
                }
            }
//            printf("cur %d next %d inCost %d outCost %d\n",cur,nextt,  inCost, outCost);
            prevv = cur;
            cur = nextt;
        }


        cout<<"Case "<<tc<<": "<<min(inCost, outCost)<<endl;

//        cout<<a<<","<<b<<","<<c<<endl;
//        if(ret==0 || ret==tot)
//        else
//            cout<<"Case "<<tc<<": "<<ret<<"/"<<tot<<endl;
    }



    return 0;
}

