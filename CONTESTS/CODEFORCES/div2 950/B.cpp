#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

int a[MX], b[MX], ans;



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    for(int i=1; i<=m; i++) {
        cin>>b[i];
    }

//    cout<<"ok";
//    return 0;
    int ptr1=1, ptr2=1;
    int sum1=0, sum2=0;
    while(ptr1<=n || ptr2<=m) {

        while(sum1<sum2 && ptr1<=n)
            sum1+=a[ptr1++];
        while(sum1>sum2 && ptr2<=m)
            sum2+=b[ptr2++];

        if(sum1== sum2)
        {
//        cout<<"sum "<<sum1<<"p1 "<<ptr1<< " p2 "<<ptr2<<endl;
            ans++;
            if(ptr1==n+1 || ptr2==m+1)
                break;
            sum1 = a[ptr1++];
            sum2 = b[ptr2++];

        }
    }


    cout<<ans-1<<endl;

    return 0;
}


