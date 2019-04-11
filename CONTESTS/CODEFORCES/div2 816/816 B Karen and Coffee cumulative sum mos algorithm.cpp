#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



//USING CUMULATIVE SUM METHOD

int ara[200100];



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    scanf("%d %d %d", &n, &k, &query);

    int l,r;

    for(int i=1; i<=n; i++)
    {

        scanf("%d %d", &l, &r);
        ara[l]++;
        ara[r+1]-- ;
    }

    for(int i=1; i<=200000; i++)
        ara[i] += ara[i-1];
    for(int i=1; i<=200000; i++)
        ara[i] = ara[i-1] + (ara[i]>=k);


    for(int i=0; i<query; i++)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", ara[r] - ara[l-1]);
    }
//    sort(q, q+query, cmp);
//    init();
//    vector<pair<int, int> >ans(query);
//
//    for(int i=0; i<query; i++) ans[i] = make_pair(q[i].pos, mos(i) );
//
//    sort(ans.begin(), ans.begin()+query);
//
//    for(int i=0; i<query; i++) printf("%d\n", ans[i].second);





    return 0;
}





//USING MO'S ALGORITHM



struct node
{
    int l, r, pos;

};

int ara[200100];

int b, e, block_size;
struct node q[200100];
int n, k,query;
int cnt;

void init()
{
    b = q[0].l;
    e = b-1;
}


bool cmp(node a, node b)
{
    if(a.l/ block_size == b.l/ block_size) return a.r< b.r;
    return a.l/block_size<b.l/block_size;
}







int mos(int pos)
{
    int &l  = q[pos].l, &r = q[pos].r;
//    string &val_s = q[pos].s;

    while(b<l)
    {
        if(ara[b]>=k) cnt--;
        b++;
    }

    while(b>l)
    {
        b--;
        if(ara[b]>=k) cnt++;
    }

    while(e< r)
    {
        e++;
        if(ara[e]>=k) cnt++;

    }
    while(e> r)
    {
        if(ara[e]>=k) cnt--;
        e--;

    }
    return cnt;
}




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    scanf("%d %d %d", &n, &k, &query);
    block_size = max(1,(int) sqrt(n));
    int l,r;

    for(int i=1; i<=n; i++)
    {

        scanf("%d %d", &l, &r);
        ara[l]++;
        ara[r+1]-- ;
    }

    for(int i=1; i<=200000; i++)
        ara[i] += ara[i-1];
    for(int i=1; i<=200000; i++)
        ara[i] = ara[i-1] + (ara[i]>=k);


    for(int i=0; i<query; i++)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", ara[r] - ara[l-1]);
    }
//    sort(q, q+query, cmp);
//    init();
//    vector<pair<int, int> >ans(query);
//
//    for(int i=0; i<query; i++) ans[i] = make_pair(q[i].pos, mos(i) );
//
//    sort(ans.begin(), ans.begin()+query);
//
//    for(int i=0; i<query; i++) printf("%d\n", ans[i].second);





    return 0;
}
