#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int ara[2020];

int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n;
    cin>>n;
    int cnt=0;
    int gcdd=-1;
    for(int i=1; i<=n; i++)
    {
        cin>>ara[i];
        if(ara[i]==1)
            cnt++;
        if(gcdd == -1) {
            gcdd = ara[i];
        } else
            gcdd = __gcd(gcdd, ara[i]);
    }

    if(cnt) {
        cout<<n-cnt<<endl;
        return 0;
    }
    if(gcdd!= 1) {
        cout<<-1<<endl;
        return 0;
    }
    int pos = 1e9;
    for(int i=1; i<=n; i++) {
        gcdd = ara[i];
        for(int j = i+1; j<=n; j++) {
            if(__gcd(gcdd, ara[j])==1) {
                pos = min(pos, j-i);
                break;
            }
            gcdd = __gcd(gcdd, ara[j]);
        }

    }
    if(pos == 1e9) {
        cout<<-1<<endl;
        return 0;
    }

    cout<<pos+n-1<<endl;


    return 0;

}
