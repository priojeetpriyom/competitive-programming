#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n , k;
vector<ll> ara(100100);
ll mx=0, mx_cost=0;
//    ll n, k;



bool valid(ll mid) {

    ll sum=0;
    ll temp[100100];
    for(int i=0; i<n; i++) {
        temp[i]= (ara[i] + ( (i+1)*mid) );
    }
    sort(temp, temp+n);

    for(int i=0; i<mid; i++) sum+=temp[i];

//    printf("mid %d sum %lld\n", mid, sum);
    return sum<= k && mid<=n;
}


int bin_search(int low, int high, int mid) {


    while(low<=high) {
        mid = (high+low)/2;
        if(valid(mid)) low = mid+1;
        else
            high = mid-1;
    }
//    printf("low %d\n", low);
    while(!valid(low) ) low--;
    return low;
}



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin>>n>>k;

    for(int i=0; i<n; i++) {
        cin>>ara[i];
    }



//    sort(ara.begin(), ara.begin()+n);
//    ara[n]= 1e9;
//    ara[0]+=1;
//    for(int i=1; i<n; i++) {
//        ara[i] = ara[i-1] + (ara[i]+ (i+1)*n );
//        printf("i %d ara %lld\n", i,  ara[i]);
//    }




    int ans= bin_search(0, n, n/2);

//    for(int i=0; i<n; i++) {
//
//        if(ara[i] >k) {
//            ans=i;
//            break;
//        } else if(ara[i] == n-1) ans = n;
//    }



//    if(it == ara.end()) ans = n;
//    else if(*it <= k) ans++;
////    if(ara[ans]  <=k) ans++;

    ll sum=0;


    for(int i=0; i<n; i++) {
        ara[i]= (ara[i] + ( (i+1)*ans) );
    }
    sort(ara.begin(), ara.begin()+n);

    for(int i=0; i<ans; i++) sum+=ara[i];



//    for(int i=0; i<ans; i++) {
//        sum+= (ara[i] +  ( (i+1) *ans) );
//    }

    cout<<ans<<" "<<sum<<endl;

    return 0;
}


