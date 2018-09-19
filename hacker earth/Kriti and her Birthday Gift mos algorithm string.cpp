#include <bits/stdc++.h>
using namespace std;

struct node
{
    int l, r, pos;
    string s;
};
unordered_map<string, int> f;
string s[100100];
int b, e, block_size;
struct node q[100100];

void init()
{
    b = q[0].l;
    e = b-1;
}


bool cmp(node a, node b)
{
    if(a.l/ block_size == b.l/ block_size) return a.r< b.r;
    return a.l<b.l;
}

int mos(int pos)
{
    int &l  = q[pos].l, &r = q[pos].r;
    string &val_s = q[pos].s;

    while(b<l)
    {
        f[s[b] ]--;
        b++;
    }

    while(b>l)
    {
        b--;
        f[s[b] ]++;
    }

    while(e< r)
    {
        e++;
        f[ s[e] ]++;

    }
    while(e> r)
    {
        f[s[e] ]--;
        e--;

    }
    return f[val_s];
}




int main()
{
    int n, query;
    cin>>n;
    block_size = max(1, (int) sqrt(n) );
    for(int i=1; i<=n; i++) cin>>s[i];
    cin>>query;
    for(int i=0; i<query; i++)
    {
        cin>>q[i].l>> q[i].r>>q[i].s;
        q[i].pos = i;
    }
    sort(q, q+query, cmp);
    init();
    vector<pair<int, int> >ans(query);

    for(int i=0; i<query; i++) ans[i] = make_pair(q[i].pos, mos(i) );

    sort(ans.begin(), ans.begin()+query);

    for(int i=0; i<query; i++) cout<<ans[i].second<<endl;


    return 0;
}

