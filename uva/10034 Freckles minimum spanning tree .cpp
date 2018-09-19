#include <bits/stdc++.h>
using namespace std;

struct node
{
    pair<double, double> x, y;
    double cost;

};

bool cmp(node a, node b)
{
    return a.cost > b.cost;
}
priority_queue<node, vector<node>, decltype(&cmp) > pq(&cmp);
vector<pair<double, double> > vec;




//double calc(int pos1,int pos2) {
//    pair<int, int> x,y;
//    x = vec[pos1], y = vec[pos2];
//    return sqrt( (double) ( abs(x.first-y.first) * abs((x.first-y.first)) ) + ( abs(x.second - y.second) * abs(x.second - y.second) ) );
//}

double calc(pair<double, double>x, pair<double, double> y)
{

    return sqrt( ( (x.first-y.first) * ((x.first-y.first)) ) + ( (x.second - y.second) * (x.second - y.second) ) );

}

double mst(int n)
{
    if(n<2) return 0.0;
    int cnt=0;
    map< pair<double, double>, int> mp;
//    int vis[111];
//    memset(vis, 0, sizeof vis);
    node a;
    a.x = vec[0];
    for(int i=1; i<n; i++) {

    a.y = vec[i];
    a.cost = calc(vec[0], vec[i]);
    pq.push(a);
    }

    double ans=0;
    mp[vec[0]]=1;
    while(cnt< n && pq.size())
    {
        node a = pq.top();
        pq.pop();

        if(!mp[a.x] || !mp[a.y]) ans+= a.cost;
        if(!mp[a.x]) cnt++, mp[a.x]=1;
        if(!mp[a.y])
        {
            cnt++, mp[a.y]=1;
            swap(a.x, a.y);
        }

//        node a;
//            a.x = make_pair(x,y);
//            a.b = y;
//            printf("x %lf y %lf\n", x, y);
        for(int j= n-1; j>=0; j--)
        {
            a.cost  = calc(a.x, vec[j]);
            a.y = vec[j];
            if(!mp[vec[j] ])
                pq.push(a);
        }

//        printf("x1 %d y1 %d x2 %d y2 %d cost %.2lf ans %.2lf cnt %d\n",a.x.first, a.x.second, a.y.first, a.y.second, a.cost,ans, cnt);
    }
    return ans;
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int x,y,xx,yy;
//    cin>>x>>y>>xx>>yy;
//    cout<<calc(make_pair(x,y), make_pair(xx,yy));

    int t;

    cin>>t;

    while(t--)
    {

        int n;
        cin>>n;
        double x, y;
        for(int i=0; i<n; i++)
        {
            cin>>x>>y;
            vec.push_back(make_pair(x,y));
            node a;
            a.x = make_pair(x,y);
//            a.b = y;
//            printf("x %lf y %lf\n", x, y);
//            for(int j= i-1; j>=0; j--) {
//                a.cost  = calc(i, j);
//                a.y = vec[j];
//                pq.push(a);
//            }
        }
//            printf("aise\n");

        cout<<std::fixed<<setprecision(2)<<mst(n)<<endl;
        if(t) cout<<endl;
//
        while(!pq.empty()) pq.pop();
        vec.clear();
//        else cout<<"T "<<t<<endl;

    }





    return 0;
}


