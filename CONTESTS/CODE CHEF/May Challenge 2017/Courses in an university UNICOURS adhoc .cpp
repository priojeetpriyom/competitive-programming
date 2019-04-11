#include<bits/stdc++.h>

using namespace std;
typedef long long ll;



int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int t,n,x;
    cin>>t;

    while(t--) {
        scanf("%d", &n);
        int mx=-1;

        for(int i=0; i<n; i++)
        {
            scanf("%d", &x);
            if(x>mx) mx = x;
        }

        printf("%d\n", n-mx);
    }

    return 0;
}

