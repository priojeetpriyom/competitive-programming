///in a lis all vertices will elements of the maximum independent set.
///
///complexity: nlogn

#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 200100
int I[MX], ara[MX];

int n;
int getPos(int val)  {


    int low=1, high= n;
    int mid;

    while(low<high) {
        mid = (high+low)/2;
//        printf("high %d low %d mid %d\n", high, low, mid);
        if(I[mid] < val)
            low = mid+1;
        else
            high = mid;
    }
//    cout<<"returning "<<low<<endl;

    return low;


}


int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//
//    int n;
    cin>>n;
    I[0]=0;
    for(int i=1; i<=n; i++) {
        cin>>ara[i];
        I[i] = 1<<30;
    }
    int ans=1;

    for(int i=1; i<=n; i++) {
//        printf("i %d\n", i);
        int pos = getPos(ara[i]);

        ans = max(ans, pos);
        I[pos] = ara[i];
//        for(int i=1; i<=n; i++)
//            cout<<I[i]<< " ";
//        cout<<endl;

    }


    cout<<ans<<endl;




    return 0;
}


