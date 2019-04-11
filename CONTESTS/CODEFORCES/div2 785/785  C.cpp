#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll m,n;
bool ans = false;
bool validate(ll day) {
    ull seq = (day*(day+1))>>1;

//    ll seq = (day*( 2*(m+1) + (day-1)  ))>>1;

    if(seq == (ull)(n-m))
       {
           ans = true;
           return true;
       }

    if(seq <(ull) (n-m))
       return true;
    else return false;
}

ll bin_search(ll high, ll low, ll mid) {

    while(high >=low) {
//        printf("high %I64d low %I64d mid %I64d\n", high, low, mid);
        if(validate(mid))
        {
            low = mid+1;
        }
        else
            high = mid - 1;
        if(ans)
            return mid;
        mid = (high+low)>>1;
    }
//    cout<<"low "<<low<<endl;
    while(!validate(low))
        low--;

//    cout<<"low "<<low<<endl;
    return low;
}



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin>>n>>m;
    if(n==1)
        printf("1\n");
    else if(n<=m) {
        printf("%I64d\n", n);
    }
    else
        cout<<bin_search(1e9, 1, (1430000001+1)/2 )+m;

    return 0;
}


