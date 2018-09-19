#include <bits/stdc++.h>
using namespace std;

struct node
{

    pair<int, int> u, v;
    double cost;

};

bool cmp(node a, node b)
{
    return a.cost>= b.cost;

}
priority_queue<node, vector<node>, decltype(&cmp)> pq(&cmp);
vector<pair<int, int> > conn;
map<pair<int, int>, int> mp;
int par[1000100];

double get_cost(int pos1,int pos2)
{

    pair<int, int> p1= conn[pos1], p2 = conn[pos2];
//    printf("u1 %d v1 %d u2 %d v2 %d cost %lf\n", p1.first, p1.second, p2.first, p2.second, sqrt( (double) ( ( (p1.first-p2.first) * (p1.first-p2.first) ) + ( (p1.second-p2.second) * (p1.second-p2.second) ) )  ) );
    return sqrt( (double) ( ( (p1.first-p2.first) * (p1.first-p2.first) ) + ( (p1.second-p2.second) * (p1.second-p2.second) ) )  );

}

int find_par(int r) {
    if(r == par[r]) return r;

    return par[r] = find_par(par[r]);


}

void unionn(int u, int v) {

    par[find_par(u)] = find_par(v);
    find_par(u);


}





int mst(int n, int r)
{
//    printf("mst pq_size %d\n", pq.size());
    node a;
    int len=conn.size();

    for(int i=0; i<=n; i++) par[i] = i;

    double ans_road=0, ans_rail=0;
    int cnt=1;
    int division=1;
    while(cnt<n)
    {
//        printf("cnt %d pq_size %d\n", cnt, pq.size());
//        printf("%d %d")
        a = pq.top();
        pq.pop();
//        printf("1 pq top u1 %d v1 %d u2 %d v2 %d cost %lf\n", a.u.first, a.u.second, a.v.first, a.v.second, a.cost );
        if(find_par(mp[a.u]) == find_par(mp[a.v])  ) continue;
//        cnt++;
        unionn(mp[a.u], mp[a.v]);
        if(a.cost<= (double) r)
        {
            ans_road+= a.cost;
        }
        else
        {
            ans_rail+= a.cost;
            division++;
        }


        cnt++;
//        if(vis[ mp[a.u] ]) swap(a.u, a.v);
//        vis[ mp[a.u] ]=1;


////        printf("cnt %d a_u %d a_v %d ans %d\n",cnt, a.u,a.v, ans );
//        printf("2 pq top u1 %d v1 %d u2 %d v2 %d cost %lf\n", a.u.first, a.u.second, a.v.first, a.v.second, a.cost );
//        getchar();

    }
    cout<<max(1, division)<<" "<<(int)round(ans_road)<<" "<<(int) round(ans_rail)<<endl;
    while(!pq.empty()) pq.pop();

}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n=-1, r;
    int u=-1, v, cost;
    int t;
    cin>>t;
    node a;
    for(int tc=1; tc<=t; tc++)
    {
        int idx=1;
        mp.clear();
        conn.clear();
        cin>>n>>r;
        for(int i=0; i<n; i++)
        {
            cin>>a.u.first>>a.u.second;
            if(!mp[make_pair(a.u.first, a.u.second)]) mp[make_pair(a.u.first, a.u.second)] = idx++;
            conn.push_back( make_pair(a.u.first, a.u.second) );

            for(int j=i-1; j>=0; j--)
            {
                a.cost = get_cost(i,j);
                a.v = conn[j];
                pq.push(a);
//                printf("i %d j %d cost %lf pq_size %d\n", i, j, a.cost,pq.size());
            }
        }
//        printf("aise\n");


        cout<<"Case #"<<tc<<": ";

        mst(n, r);

    }

    return 0;
}

