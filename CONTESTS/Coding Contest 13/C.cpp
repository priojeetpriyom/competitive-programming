#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    return (a%b==0) ? b: gcd(b, a%b);
}

int lcm(int a, int b) {
    return (a*b)/gcd(a,b);
}
int main()
{
//    freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);
//    cout<<gcd(12,4);
    int n;
    cin>>n;

    while(n--) {
        int r1,r2;
        cin>>r1>>r2;
        r1+=r1;
        r2+=r2;

        printf("%d\n",lcm(r1,r2));
    }

    return 0;


}



