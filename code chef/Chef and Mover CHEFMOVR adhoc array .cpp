#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef unsigned long long ull;



int ara[100100];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin>>t;

    while(t--)
    {
        int n, d;
        cin>>n>>d;
        ll sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>ara[i];
            sum+=ara[i];
        }

        if(sum%n)
        {
            cout<<-1<<endl;
            continue;
        }
        int avg = (sum/n);

        ll ans=0;
        for(int i=0; i<n-d; i++)
            if(ara[i]< avg)
            {
                int temp = min(avg - ara[i],(int) 1e9);
                ara[i] += temp;
                ara[i+d] -= temp;
                ans+= temp;
            }
            else if(ara[i] > avg)
            {
                int temp = abs(avg - ara[i]);
                ara[i] -= temp;
                ara[i+d] += temp;
                ans+= temp;
            }
        int f=0;
        for(int i=0; i<n; i++)
            if(ara[i] !=avg)
            {
                cout<<-1<<endl;
                f=1;
                break;
            }


        if(!f)
        {
            cout<<ans<<endl;
        }
    }

    return 0;
}

