#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int l1,l2,l3,l4;
    int s1, s2, s3,s4;
    int r1, r2,r3,r4;
    int p1, p2, p3, p4;


    cin>>l1>>s1>>r1>>p1;

    cin>>l2>>s2>>r2>>p2;
    cin>>l3>>s3>>r3>>p3;
    cin>>l4>>s4>>r4>>p4;
    int ans=0;

    if(p1) {
        if(s1 || r1 || l1) ans=1;
        if(l2 || s3 || r4) ans=1;

    }
    if(p2) {
        if(s2 || r2 || l2) ans=1;
        if(l3 || s4 || r1) ans=1;

    }


    if(p3) {
        if(s3 || r3 || l3) ans=1;
        if(l4 || s1 || r2) ans=1;

    }

    if(p4) {
        if(s4 || r4 || l4) ans=1;
        if(l1 || s2 || r3) ans=1;

    }

     if(ans) cout<<"YES"<<endl;
     else cout<<"NO"<<endl;



    return 0;
}


