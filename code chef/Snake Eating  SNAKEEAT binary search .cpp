#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll > vec(100100), cum(100100);

bool cmp(ll a, ll b) {
    return a>b;
}
ll k, n;


int get_val_pos(int low, int high, int mid, ll k) {

    while(low<= high) {
        mid = (high+low)>>1;
        if(vec[mid]>=k) low = mid+1;
        else high = mid-1;
    }
    if(vec[low] < k) low--;
    return low;
}

bool solve(int pos, int lim) {
//    printf("k %lld pos %d lim %d cum_pos %lld cum_lim %lld n %d\n",k, pos, lim, cum[pos], cum[lim], n );
    return (k * (pos-lim) - (cum[pos]-cum[lim])  <= (n - pos) );
}



int get_rem(int low, int high, int mid, int left_lim) {
    int mx =0;

    while(low <= high) {
        mid = (low+high)>>1;
        if(solve(mid, left_lim)) {
//            printf("mid %d lim %d mx %d\n", mid, left_lim, mx);
            mx = max(mx, mid-left_lim);
            low = mid+1;
        } else high = mid-1;
    }
    return mx;
}


int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);


    int t;
    cin>>t;
    int q;

    while(t--) {
        scanf("%lld %d", &n, &q );

        for(int i=1; i<=n; i++)
            {
                scanf("%lld", &vec[i]);
            }

        sort(vec.begin()+1, vec.begin()+n+1, cmp);

//        for(int i=0; i<=n; i++) printf("%d ", vec[i]); printf("\n");

//        cum[0]=0;
        for(int i=1; i<=n; i++)
            cum[i]=cum[i-1]+vec[i];
        vec[n+1] = -1;

        while(q--) {
            scanf("%lld", &k);
            int val_pos = get_val_pos(1, n,(n+1)>>1, k);
//            printf("val_pos %d\n", val_pos);
            int ans = val_pos + get_rem(val_pos+1, n, 0, val_pos);

            printf("%d\n", ans);
            ans=0;
        }

    }

    return 0;

}

