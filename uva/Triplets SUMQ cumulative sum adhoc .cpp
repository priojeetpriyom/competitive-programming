#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll mod = 1000000007;

ll x[100100], y[100100], z[100100];
ll cum_x[100100], cum_z[100100];


ll findd(ll ara[], ll val, ll high) {

    ll low=1;

    ll mid;


    while(low<=high) {
//        printf("high %lld low %lld mid %lld ara %lld val %lld\n", high, low, mid, ara[mid], val);
        mid = ( (high+low)>>1 );
//        printf("high %lld low %lld mid %lld ara_m %lld val %lld\n", high, low, mid, mid, val);
        if(ara[mid] <= val) low = mid+1;
        else high = mid-1;
    }

    while(ara[low]> val) low--;

    return low;
}






int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;

    cin>>t;

    while(t--) {

        int a,b,c;

         cin>>a>>b>>c;

         for(int i=1; i<=a ; i++) {
            cin>>x[i];
         }
         for(int i=1; i<=b ; i++) {
            cin>>y[i];
         }
         for(int i=1; i<=c ; i++) {
            cin>>z[i];
         }

         sort(x+1, x+a+1);
         sort(z+1, z+c+1);

         cum_x[0]=y[0]=cum_z[0]=0;
         for(int i=1; i<=a; i++) {
            cum_x[i]= x[i] +  cum_x[i-1];
            if(cum_x[i]>= mod) cum_x[i] %=mod;
         }

         for(int i=1; i<=c; i++)
            {
                cum_z[i] = z[i] + cum_z[i-1];
                if(cum_z[i] >= mod)
                    cum_z[i] %= mod;
            }

//            for(int i=1; i<=a; i++) cout<<cum_x[i]<<" "; cout<<endl;
//            for(int i=1; i<=c; i++) cout<<cum_z[i]<<" "; cout<<endl;




         ll sum=0;

         x[a+1] = z[c+1] = 2e9;
         ll n_x, n_z;

         for(int i=1; i<=b; i++) {

            n_x = findd(x, y[i], a);
//            printf("called find for z\n");
            n_z = findd(z, y[i], c);

//            printf("i %d n_x %lld n_z %lld\n", i, n_x, n_z);
            sum += ( ( ( y[i] * ((n_x * n_z)%mod) ) %mod ) * y[i] ); // n_x n_z y^2
            if(sum>= mod) sum %=mod;

            sum += ( ( (n_x * y[i])%mod ) * cum_z[n_z]);      //n_x y (z)
            if(sum >=mod) sum %=mod;



            sum += ( ( (n_z * y[i])%mod ) * cum_x[n_x]);      //n_z y (x)
            if(sum >=mod) sum %=mod;


            sum += (cum_x[n_x] * cum_z[n_z]);

            if(sum >= mod) sum %= mod;
         }

         cout<<sum<<endl;



    }


    return 0;
}





