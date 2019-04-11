#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


struct node
{
    ll start,endd, cost;
    ll mn_l, mn_r;
    node(int s,int e,  int c)
    {
        start = s;
        endd = e;
        cost = c;
        mn_l = mn_r = 1e9;
    }
};

struct node2
{
    int l,r,c;
    node2(int ll, int rr, int cc)
    {
        l=ll, r=rr, c=cc;
    }
};

bool cmp(node a, node b)
{

    return a.start < b.start;
}

int lower_bin(vector<node> &ara, int high, int val)
{

    int low = 0;
    high--;
    int mid = (low+high)/2;

    while(low<high)
    {
        mid= (low+high)/2;
        if(ara[mid].start < val) low = mid+1;
        else high  = mid-1;
    }

    return low;
}

int higher_bin(vector<node> &ara, int high, int val)
{

    int low = 0;
    high--;
    int mid = (low+high)/2;

    while(low<high)
    {
        mid= (low+high)/2;
        if(ara[mid].endd < val) low = mid+1;
        else high  = mid-1;
    }

    return low;
}





vector<node> pre[200100];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, x;
    cin>>n>>x;
    vector<node2> vec;
    int l,r,c, mx_diff=0;
    for(int i=0; i<n; i++)
    {
        cin>>l>>r>>c;
        vec.push_back(node2(l,r,c));
        pre[r-l+1].push_back(node(l,r,  c));
        mx_diff = max(mx_diff, r-l+1);
    }
    for(int i=1; i<=mx_diff; i++)
        sort(pre[i].begin(), pre[i].begin()+mx_diff+1, cmp);
    int len;

    for(int i=1; i<=mx_diff; i++)
    {

        len = pre[i].size();
        if(!len) continue;
        pre[i][0].mn_l = pre[i] [0].cost;
        for(int j=1; j<len; j++)
        {
            pre[i][j].mn_l = min(pre[i][j].cost, pre[i][j-1].mn_l);
        }
    }
    for(int i=1; i<=mx_diff; i++)
    {
        len = pre[i].size();
        if(!len) continue;
        pre[i][len-1].mn_r = pre[i][len-1].cost;
        for(int j=len-2; j>=0; j--)
        {
            pre[i][j].mn_r = min(pre[i][j].cost, pre[i][j+1].mn_r);
        }
    }
    ll mn_cost = 3e9;

    for(int i=0; i<n; i++)
    {
        l = vec[i].l, r = vec[i].r, c =  vec[i].c;
        if(x - (l-r+1) <=0) continue;
        vector<node> & ara = pre[x - (r-l+1) ];


        int it = lower_bin(ara, ara.size(), r+1);

        ll temp = 4e9;
        while(it<ara.size() && ara[it].start <=  r)
        {
            it++;
        }
        if(it< ara.size())
        {
            temp = ara[it].mn_l;
        }

        it = higher_bin(ara, ara.size(), l-1);


        while(it>=0 && ara[it].endd >=  l)
        {
            it--;
        }
        if(it>=0)
        {
            temp = ara[it].mn_l;
        }

        mn_cost = min(mn_cost, temp+c);


    }


    if(mn_cost==3e9) cout<<-1<<endl;
    else cout<<mn_cost<<endl;


    return 0;
}


