#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



ll b, q, l, m, x, ara[100100];
map<int, int> mp;
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin>>b>>q>>l>>m;
    for(int i=0; i<m; i++)
    {
        scanf("%I64d", &ara[i]);
        mp[ara[i]]=1;
    }

    ll ans = 0 , seq = b, last = b-1;
    if(abs(b)>l) {
        printf("0\n"); return 0;
    }
//    cout<<"ans "<<ans<<endl;
    while(abs(seq) <=l) {
        if(abs(last) == abs(seq)) break;
        if(!mp.count(seq))
        {
            ans++;
//            printf("seq %I64d ans %I64d\n", seq, ans);
        }
        last = seq;
        seq *= q;
    }

    if(q==1) {
        if(ans>0) printf("inf\n");
        else printf("0\n");
    } else if(q == -1) {
        if(!mp.count(b) || !mp.count(-b)) printf("inf\n");
        else printf("0\n");
    } else if(q==0) {
        if(!mp.count(0)) printf("inf\n");
        else if(ans>0) printf("1\n");
        else printf("0\n");
    } else if(b==0) {
        if(!mp.count(0)) printf("inf\n");
        else printf("0\n");
    }else
        cout<<max(ans,0LL);
    return 0;
}


