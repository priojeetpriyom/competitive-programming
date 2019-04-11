#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100
ll ara[MX], pre[MX], suf[MX], ans[MX];
ll n;


bool is_ok_pre(int start, int endd, ll val) {

    if(start>=endd)
        return true;
//
//    ll sum=0;
//
//    for(int i=0; i<n; i++) {
//
//        sum+= (( ara[i]+k-1 )/k);
//    }
//    cout<<"k "<<k<<" sum "<<sum<<" h"<<h<<endl;
//    printf("val %lld start %d endd %d pre[start] %lld pref[endd] %lld\n", val, start,endd-1, pre[start], pre[endd-1]);
    return (pre[endd-1]- pre[start])<=val;

}

bool is_ok_suf(int start, int endd, ll val) {

//
//    ll sum=0;
//
//    for(int i=0; i<n; i++) {
//
//        sum+= (( ara[i]+k-1 )/k);
//    }
//    cout<<"k "<<k<<" sum "<<sum<<" h"<<h<<endl;
//    printf("val %lld start %d endd %d suf[start] %lld suf[endd] %lld\n", val, start,endd+1, suf[start], suf[endd-1]);
    return (suf[endd+1]- suf[start])<=val;

}

int bsearch_pre(int low, int high, int mid,int start, ll val)
{

    while(low<=high) {
        mid = (high+low)/2;
        bool ok = is_ok_pre(start, mid, val);
//        printf("start %d low %d high %d mid %d is_ok %d\n", start, low, high, mid, ok);
        if(ok)
            low = mid+1;
        else
            high = mid-1;

    }
//    cout<<"high after search "<<high<<endl;
//    if(is_ok(low))
//        return high;
//    printf("\n");
    return low;

}

int bsearch_suf(int low, int high, int mid,int start, ll val)
{
//    printf("SUF_bsearch\n");
    while(low<=high) {
        mid = (high+low)/2;

        bool ok = is_ok_suf(start, mid, val);
//        printf("start %d low %d high %d mid %d is_ok %d\n", start, low, high, mid, ok);
        if(ok)
            high = mid-1;
        else
            low = mid+1;

    }
//    cout<<"high after search "<<high<<endl;
//    if(is_ok(high))
//        return high;


    return high;

}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int t;
    cin>>t;

    while(t--) {
        memset(ans, 0, sizeof ans);
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>ara[i];
        pre[1] = ara[1];
        suf[n] = ara[n];
        ara[0]=ara[n+1]= pre[0]=pre[n+1]= suf[0]=suf[n+1]= 0;
        for(int i=2; i<=n; i++)
        {
            pre[i]= pre[i-1]+ ara[i];
        }
        for(int i = n-1; i>=1; i--)
        {
            suf[i]= suf[i+1] + ara[i];
        }


        for(int i=1; i<=n; i++) {

            ans[i+1]++;
            int pref = bsearch_pre(i, n, 0,i,  ara[i]);
            ans[pref]--;
            int suff=0;
//            if(i>1)
            ans[i]--;
            suff = bsearch_suf(1, i, 0,i, ara[i]);
            ans[suff+1]++;
//            printf("i %d pref %d suff %d\n\n", i, pref, suff);
        }

        for(int i=1; i<=n; i++) {

            ans[i]+= ans[i-1];

        }
        for(int i=1; i<=n; i++) {
            cout<<ans[i]<<" ";
        }

        cout<<endl;

    }



    return 0;
}
