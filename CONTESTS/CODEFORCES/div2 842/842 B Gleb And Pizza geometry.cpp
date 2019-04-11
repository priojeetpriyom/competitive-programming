#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double calc(double x1, double y1, double x2, double y2) {
    double x  =(x1- x2);
    x*=x;
    double y = (y1-y2);
    y*=y;
//    cout<<"X "<<x<<" Y "<<y<<endl;
    return sqrt(x+y);


}
//int get_sq(int a, int b) {
//
//    return (4*a*a) - (4*a*b) + (b*b);
//
//}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int r, d, n;
    cin>>r>>d>>n;
    r-=d;
    int low = r;
    int high = r+d;
//    cout<<"low "<<low<<" high "<<high<<endl;
    int cnt=0;
//    double r_two = sqrt(2);
    for(int i=0; i<n; i++) {
        int x, y;
        double rr;
        cin>>x>>y>>rr;
//        rr /= 2;
//        rr*=rr;


        double dist = calc(0, 0 , abs(x), abs(y) );
        double ll = low;
        double hh = high;

        if(dist-rr>= ll && dist+rr<=hh) cnt++;
//        cout<<"i "<<i<<" dist "<<dist<<" hh "<<hh <<" ll "<<ll<<" cnt "<<cnt<<endl;
    }


    cout<<cnt<<endl;



    return 0;
}


