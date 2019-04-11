#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


     int t;
     cin>>t;

     while(t--) {

        int n;
        cin>>n;

        int L[MX], G[MX];

        for(int i=0; i<n; i++)
            cin>>L[i];
        for(int i=0; i<n; i++)
            cin>>G[i];

        bool frontt=true, backk=true;

        for(int i=0; i<n; i++)
            if(L[i]>G[i])
                frontt=false;

        for(int i=0; i<n; i++)
            if(L[i]>G[n-i-1])
                backk=false;

        if(frontt && backk)
            cout<<"both"<<endl;
        else if(frontt)
            cout<<"front"<<endl;
        else if(backk)
            cout<<"back"<<endl;
        else
            cout<<"none"<<endl;

     }


    return 0;
}


