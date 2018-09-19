#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;


struct node{

int l, r, pos;

};



int ara[30000+5];
int f[ (int)1e6+5];
vector<struct node>  q(200001);
int n, query, cnt=0;
int b, e;
int l,r, block_size;

bool cmp(struct node a, struct node b) {

    if(a.l/block_size == b.l/ block_size)
        return a.r < b.r;

    return  (a.l/block_size <= b.l/block_size);

}

void init() {
    b= q[0].l;
    e = b-1;


}

int mos(int pos) {

     l = q[pos].l;
     r = q[pos].r;

     while(b <l) {
        f[ara[b] ]--;
        if(!f[ara[b] ]) cnt--;
        b++;
     }

     while(b> l) {
        b--;

        f[ ara[b] ]++;
        if(f[ara[b] ]==1) cnt++;
     }


     while(e < r) {
        e++;
        f[ ara[e] ] ++;
        if(f[ara[e] ]==1) cnt++;
     }

     while(e>r) {
        f[ ara[e] ] --;
        if(!f[ara[e] ]) cnt--;
        e--;
      }

    return cnt;

}







int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);    cin.tie(0);

//    cin>>n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) cin>>ara[i];

    block_size = max(1, (int)sqrt(n));

//    cin>>query;
    scanf("%d", &query);

    for(int i=0; i<query; i++) {
//        cin>>q[i].l>>q[i].r;
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].pos = i;
    }

    sort(q.begin(), q.begin()+query, cmp);
    init();
    vector<pair<int, int> > ans;

    for(int i=0; i<query; i++)
    {
        ans.push_back(make_pair(q[i].pos, mos(i)));
    }
    sort(ans.begin(), ans.end());

    for(int i=0; i<query; i++) {
//        cout<<ans[i].second<<endl;
        printf("%d\n", ans[i].second);
    }


    return 0;
}

