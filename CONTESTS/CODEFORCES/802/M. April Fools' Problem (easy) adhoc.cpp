#include<bits/stdc++.h>

using namespace std;
typedef long long ll;




int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin>>n>>k;
    int ara[2222];

    for(int i=0; i<n; i++)
        cin>>ara[i];

    sort(ara, ara+n);
    int sum=0;

    for(int i=0; i<k; i++)
        sum+=ara[i];

    cout<<sum<<endl;

    return 0;

}

