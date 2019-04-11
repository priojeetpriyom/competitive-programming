#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int ara[100100];

int main()
{
//    freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        scanf("%d", &ara[i]);
    sort(ara, ara+n);

    int cnt=0;
    int l=0, r=n-1;

    while(l<n-1) {
        if(ara[l] != ara[l+1])
            break;
        l++;
    }
    while(r>1) {

        if(ara[r] != ara[r-1])
            break;
            r--;
    }

    cout<<max(r-l+1 -2, 0)<<endl;

    return 0;


}


