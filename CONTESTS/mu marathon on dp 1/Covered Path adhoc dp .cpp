#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//#include <stdio.h>
//#include <string.h>
//#define ll long long

    int s, f, t, d;

int valid(int mid) {
    return ( t- (1+ (mid-s)/d + ( (mid-s)%d !=0) + ((mid-f)/d) + ( (mid-f)%d!=0 ) ) );

}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    cin>>s>>f>>t>>d;

    if(d==0) return cout<<s*t<<endl,0;
    if(t==2) return cout<<s+f<<endl,0;

    int mid;

    for(int i = max(s,f); valid(i)>=0 ; i++) {

        mid =i;

    }
//    printf("mid %d val %d\n", mid, valid(mid));

    int ans=0;
    if(valid(mid)) ans+=mid;

//    if((mid-f)%d!=0 ) {
//
//    }

    for(int i=s; ; i+=d) {
        if(i >=mid) {
            break;
        }
        ans+=i;
    }



    for(int i = mid; ; i-=d) {
        if(i<=f) {
            ans+=f + (f-i);
            break;
        }
        ans+=i;
    }

    cout<<ans<<endl;

    return 0;
}
