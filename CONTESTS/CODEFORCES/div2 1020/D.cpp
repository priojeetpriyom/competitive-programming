#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 200100


int ara[MX];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);


    int n;

    cin>>n;

    for(int i=1; i<=n; i++)
        ara[i]= INT_MAX;

    cout<<"? "<<1<<endl;
    fflush(stdout);
    cin>>ara[1];

    cout<<"? "<<1+n/2<<endl;
    fflush(stdout);
    cin>>ara[1+n/2];

    int comp = ara[1]<ara[1+n/2];

    int low = 1, high = n/2;
    int mid;

    while(low<=high) {
        int mid = (low+high)>>1;
//        cout<<"low "<<low<<" high "<<high<<" mid "<<mid<<" mid+n/2 "<<mid+n/2<<endl;
        if(ara[mid]== INT_MAX) {

            cout<<"? "<<mid<<endl;
            fflush(stdout);
            cin>>ara[mid];
        }
        if(ara[mid+n/2]== INT_MAX) {

            cout<<"? "<<mid+ n/2<<endl;
            fflush(stdout);
            cin>>ara[mid+n/2];
        }

        if(ara[mid] == ara[mid+n/2]){
            cout<<"! "<<mid<<endl;
            fflush(stdout);
            return 0;
        } else if( (ara[mid]<ara[mid+n/2]) ==comp) {
            low = mid+1;
        } else
            high = mid-1;
    }


    cout<<"! -1"<<endl;

    fflush(stdout);



    return 0;
}


