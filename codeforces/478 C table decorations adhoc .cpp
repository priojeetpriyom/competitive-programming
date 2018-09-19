#include <bits/stdc++.h>
using namespace std;

#define MX 110
#define ll long long

long long int rec(long long int a, long long int i, long long int c);

ll solve(ll a, ll b, ll c) {
    ll ans=0;
    while(1) {
        cout<<a<<" "<<b<<" "<<c<<endl;
        getchar();
        if(a==b && b==c) {
            ans+=a;
            break;
        }

        if(b>a)
            swap(a, b);
        if(c>a)
            swap(a,c);
        if(c>b)
            swap(b, c);

        if(b==c) {
            if(b==0)
                break;
            ll cut = min( (a-b)/2, b);
            if(!cut)
            {
                ans+= b;
                break;
            }
            ans+= cut;
            a-= (cut<<1);
            b-=cut;
//            cout<<"aise cut "<<cut<<endl;
            continue;
        }

        ll dab = a-b; //,dbc = b-c, dac = a-c;

        ll cut = min(b, dab/2);
        if(cut==0) {
//            ans+= min(a, min(b,c));
            cut = (b-c)/3;
            if(!cut) {
                return ans+ min(a, min(b,c));
            }
            ans+= (cut*2);
            a-= cut*3;
            b-= cut*3;
            continue;
        }
        ans+= cut;
        a = a- cut-cut;
        b-=cut;
    }
//    cout<<"a "<<a<<" b "<<b<<" c "<<c<<endl;


    //vcout<<ans<<endl;
    return ans;
}

int main() {
    ll a, b, c;

    while(cin>>a>>b>>c) {
//        cout<<rec(a,b,c)<<endl;
        vector<ll> vec({a,b,c});
        sort(vec.begin(), vec.end());
        if(vec[2]>= 2* (vec[0]+vec[1]))
            cout<<vec[0]+vec[1]<<endl;
        else
            cout<<(a+b+c)/3<<endl;
    }
//    int n=10;
//    for(a =1; a<=n; a++) {
//        for(b=1; b<=n; b++) {
//            for(c=1; c<=n; c++) {
//                if( solve(a,b,c) != rec(a, b, c))
//                    cout<<"a "<<a<<" b "<<b<<" c "<<c<<" = rec "<<rec(a,b,c)<<"; sol "<<solve(a, b, c)<<endl;
//            }
//        }
//    }

    return 0;
}

long long int rec(long long int a, long long int b, long long int c) {
    if(a<0 || b<0 || c<0)
        return static_cast<long long int>(-1e9);
    if((a+b+c)<3)
        return 0;
    ll ret=0;

    ret = max(ret, rec(a-1, b-1, c-1)+1);

    ret = max(ret, rec(a-2, b-1, c)+1);
    ret = max(ret, rec(a-2, b, c-1)+1);

    ret = max(ret, rec(a-1, b-2, c)+1);
    ret = max(ret, rec(a, b-2, c-1)+1);

    ret = max(ret, rec(a-1, b, c-2)+1);
    ret = max(ret, rec(a, b-1, c-2)+1);

    return ret;
}

