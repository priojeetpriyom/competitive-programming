#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[20], dp_lim [20] [20] [3] [2];
int len;
char str[20];
ll rec_lim(int l, int r, int prev_lim, int first) { // used prev_lim to indicate- 2, if num>str[r],1 if num==str[l], 0 if num<str[l]
//    printf("l %d r %d prev_lim %d\n", l, r, (prev_lim));
//    if((l==r || ((l+1 > r-1) && (len%2==0) )) && prev_lim==2 ) {
//        return (ll)max(0, min(str[l], str[r]) - '0');
//    }
    if(l>r) {
//        printf("return from l>r %d\n", prev_lim!= 2);
        return (prev_lim!= 2);
    }
//    if(l == r+1) {
//        return min(str[l],str[r]);
//    }
    ll &ret = dp_lim[l] [r] [prev_lim] [first];
    if(ret != -1) return ret;
    ret=0;
    int lim = (prev_lim) ? (str[l]-'0'): 9;

    for(int i= first; i<=lim; i++) {
        if(!prev_lim) {
            ret+= rec_lim(l+1, r-1, 0, 0);
        }else if(i < str[l]-'0')
            ret+= rec_lim(l+1, r-1, 0, 0);
        else if(i > str[r]-'0') {
            ret+= rec_lim(l+1, r-1, 2, 0);
        } else if(i == str[l]-'0') {
            if(i < str[r]-'0')
                ret+= rec_lim(l+1, r-1, 1, 0);
            else
                ret+= rec_lim(l+1, r-1, max(1, prev_lim), 0);
         }

    }

    return ret;
}



void str_rec(ll n) {
    if(n==0) {
//        if(!depth) {
//            str[len++] = '0';
//        }
        return;
    }
    str_rec(n/10);
    str[len++] = (n%10 + '0');
}

void toStr(ll num) {
    len =0;
    str_rec(num);
    str[len] = '\0';
}

ll rec(int len) {
    if(len<=0) return 1;
    ll &ret = dp[len];
    if(ret != -1) return ret;
    ret=0;
    for(int i=0; i<10; i++)
        ret+= rec(len-2);
    return ret;
}

bool is_palindrom() {
    for(int i=0; i<len/2; i++) {
        if(str[i]!= str[len-i-1]) return false;
    }
    return true;
}

ll calc(ll num) {
    if(num < 0) return 0;
    if(!num) return 1;
    if(num<10) return num+1;
    toStr(num);
    ll ans=1;
//    printf("str %s len %d\n", str, len);

    for(int i=1; i<len; i++) {
        for(int j=1; j<10; j++) {
            ans+= rec(i- 2);
        }
    }
//    printf("pre_ans %lld\n", ans);
    memset(dp_lim, -1, sizeof dp_lim);
//    for(int i=1; i<= (str[0]-'0'); i++) {
//        if(i == (str[0]-'0') && i> (str[len-1]-'0')) continue;
        ans+=rec_lim(0, len-1, 1, 1);
//    }
    return ans;
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

//light oj1205

    memset(dp, -1, sizeof dp);
    ll ans=0;
    int len=3;

    int t;
    cin>>t;
    ll a,b;
    for(int tc=1; tc<=t; tc++) {
        scanf("%lld %lld", &a, &b);
        if(a>b) swap(a,b);
        ans = calc(b) - calc(a-1);
//        printf("ans_a %lld ans_b %lld\n",calc(a-1), calc(b));
//        ans = calc(b);
        printf("Case %d: %lld\n", tc, ans);
    }


    return 0;
}

//int main()
//{
////    freopen("in.txt", "r", stdin);
////    freopen("out.txt", "w", stdout);
//    memset(dp, -1, sizeof dp);
//    int n;
//    while(cin>>n) {
//        ;
//    cout<<calc(n)<<endl;
//    }
//    return 0;
//}


