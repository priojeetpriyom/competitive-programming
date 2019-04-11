#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100


unordered_set<int> sset;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
//    n=1e18;
//    n=1e9+7;
    cin>>n>>k;
//
//    if(n==1 || k==1)
//    {
//        cout<<"no"<<endl;
//        return 0;
//    }
//    for(int i=1; i<=1000000000; i++);

//    for(int n=2; n<=1000; n++)
//    {
//        int vis[1000];
//        memset(vis, 0, sizeof vis);

        int mn_k=2;
        if(n==1)
            mn_k=3;
        if(n%2==0)
        {
            mn_k = 2;
        }
        else
        {
//            sset.clear();
            for(int i=1; i<=n; i++)
            {
                int x =(n)%i;

                if(sset.find(x)!= sset.end())
                {
                    mn_k = i;
                    break;
                }
                sset.insert(x);
            }


        }

        if(k>=mn_k)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;



//        for(int k=1; k<=1000; k++)
//        {
//            if(vis[n%k])
//            {
//                cout<<n<<"=> "<< (k==mn_k) <<" "<< mn_k<<endl;
//                if(k!=mn_k) {
//                    cout<<"fck"<<endl;
//                    return 0;
//                }
//                break;
//            }
//            vis[n%k]=1;
//        }
//    }



    return 0;
}


