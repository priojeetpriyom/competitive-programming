#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, len;
char str[100100];

ll pre_calc() {
    ll ans=0, continuous=0;
    int lim = len-1;
    while(str[lim]=='1' && lim>=0) lim--;
        ll cnt=0;
    for(int i=0; i<=lim; i++) {
        if(str[i]=='1') {
            for(int j= i; j<=lim; j++) {
                if(str[j]== '0') {
//                    continuous+= cnt;
                    ans+= cnt;
                    i = j;
                    break;
                }
                cnt++;
            }
        }
    }
    return ans;
}

ll calc() {
    len--;
    while(str[len]=='1' && len>=0) len--;
    ll ans=0, pos = len;
    for(int i = len; i>=0; i--) {
        if(str[i]=='1') {
            ans += (pos - i);
            pos--;
        }
    }
    return ans;
}

int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);


    cin>>n;

    while(n--) {
        scanf("\n%s", str);
        len = strlen(str);
        ll ans = pre_calc();
//        cout<<pre_calc()<<endl;
        ans+=calc();
        cout<<ans<<endl;
    }

    return 0;
}





