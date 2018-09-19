#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int base,k, len, tc;
char str[20];
ll dp [1<<16] [20];
int visited [1<<16] [20];

bool CHECK(int mask, int pos) {
    return mask & (1<<pos);
}
int SET(int mask, int pos) {
    return mask | (1<<pos);
}

int get_val(int val, int pos, int num) {
    if(num >='A') num = num-'A'+10;
    else num = num-'0';
    int pw=num;
    for(int i=1; i<=pos; i++) {
        pw = (pw*base)%k;
    }
    return (pw+val)%k;
}

ll rec(int mask, int val) {
//    printf("mask %d\n", mask);
    if(mask == (1<<len)-1) {
        if(val==0) return 1;
        return 0;
//        return !(bool)val;
    }

    ll &ret = dp[mask] [val];
    int &vis  = visited[mask] [val];
    if(vis == tc) return ret;
    vis = tc;
    ret=0;
    for(int i=0; i<len; i++) {
        if(!CHECK(mask, i)) {
            ret+= rec(SET(mask, i), get_val(val,__builtin_popcount(mask), str[i]));
        }
    }
    return ret;

}

int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int t;
    cin>>t;

    for(tc=1; tc<=t; tc++) {
        scanf("%d %d", &base, &k);
        scanf("\n%s", str);
        len = strlen(str);
        printf("Case %d: %lld\n",tc, rec(0, 0));
    }

    return 0;
}





