#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int t;
    cin>>t;

    while(t--) {

        int n;
        cin>>n;

        double price,quan,dis,tot=0;

        while(n--) {
            cin>>price>>quan>>dis;
            double increased = (price*(dis/100));
            double newPrice = price + increased;
            double decreased = newPrice* (dis/100);
            tot+= (decreased-increased)*quan;
        }
        printf("%lf\n", tot);
    }



    return 0;
}


