#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

struct node {
    int att, pos;
} ara[MX];

bool cmp(node a, node b) {
    return a.att<b.att;
}
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, A, B, C, T;
    cin>>n>>A>>B>>C>>T;

    for(int i=1; i<=n; i++) {
        int x;
        cin>>x;
        ara[i]  = {x, i};

    }
    sort(ara, ara+n, cmp);

    ll ans=0, waiting=0;
    int pos=1;
    queue<node> Q;
    int cnt=0;
    for(int i=1; i<=T && pos<=n; i++) {
        cnt=0;
        while(ara[pos].att<=i && pos<=n) {
            if(C>B) {
                Q.push(ara[pos]);
                if(ara[pos].att==i)
                    cnt++;
                else waiting++;
            } else {
                ans+= A;
            }
            pos++;
        }
        ans+= (waiting*C);
//        printf("i %d ans %lld waiting %lld idx %d ara_pos %d att %d\n", i, ans, waiting,pos,ara[pos].pos, ara[pos].att);
        waiting+= cnt;
    }

    while(!Q.empty()) {
        node u = Q.front();
        Q.pop();
        ans += ( A - ( (T- u.att) *B) );
//        cout<<" u "<<u.pos<<" waited "<<(T- u.att)<< "ans "<<ans<<endl;
    }




    cout<<ans<<endl;

    return 0;
}


