#include <bits/stdc++.h>
using namespace std;

struct node
{
    int l, r, pos;

};
unordered_map<int, int>  mp;
int ara[100100];

int b, e, block_size;
struct node q[100100];
int n;
int tree[100100];
int mx;

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



void update(int idx,int val) {

    while(idx<= mx) {
        tree[idx]+=val;
        idx+= idx &(-idx);
    }
}

int query(int idx) {
    int sum=0;
    while(idx) {
        sum+=tree[idx];
        idx-= idx & (-idx);
    }

    return sum;
}

int cnt=0;

int mos(int pos)
{
    int &l  = q[pos].l, &r = q[pos].r;
   // string &val_s = q[pos].s;

    while(b<l)
    {

        cnt-= ( query(ara[b]-1) );
        update(ara[b], -1);
        b++;
    }

    while(b>l)
    {
        b--;
        cnt+= query(ara[b]-1);
        update(ara[b],1);
    }
//    printf("b %d e %d cnt %d\n", b,e,cnt);

    while(e< r)
    {
        e++;
        cnt+= ( query(mx) - query(ara[e])) ;
        update(ara[e], 1);

    }
    while(e> r)
    {
        cnt-= ( query(mx) - query(ara[e]) );
        update(ara[e], -1);
        e--;

    }
    return cnt;
}




int main()
{
//    ios_base::sync_with_stdio(false); cin.tie(0);

    int query;
//    cin>>n>>query;
    scanf("%d %d", &n, &query);
    block_size = max(1, (int) sqrt(n) );
    for(int i=1; i<=n; i++) {
//        cin>>ara[i];
        scanf("%d", &ara[i]);
    }

    vector<int> temp(ara, ara+n);
    sort(temp.begin(), temp.end());
    int idx=1;
    for(int i=0; i<n; i++) {
        if(!mp[temp[i] ])
            mp[ temp[i] ] = idx++;
    }
    mx = idx;

    for(int i=1; i<=n; i++) ara[i] = mp[ara[i] ];


//    cin>>query;
    for(int i=0; i<query; i++)
    {
//        cin>>q[i].l>> q[i].r;
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].pos = i;
    }
    sort(q, q+query, cmp);
    init();
    vector<pair<int, int> >ans(query);

    for(int i=0; i<query; i++) ans[i] = make_pair(q[i].pos, mos(i) );

    sort(ans.begin(), ans.begin()+query);

    for(int i=0; i<query; i++) {
//        cout<<ans[i].second<<endl;
        printf("%d\n", ans[i].second);
    }


    return 0;
}

\
