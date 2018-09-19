#include<bits/stdc++.h>
using namespace std;

double getArea(double a, double b, double c) {
    double p = (a+b+c)/2;
//    return sqrt(p) * sqrt(p-a) *sqrt(p-b) *sqrt(p-c);
    return sqrt(p * (p-a) * (p-b) * (p-c));
}

double check(double ad, double ab, double bc, double ac, double AREA, double rat) {
    double area = getArea(ad, (ad/ab)*ac, (ad/ab)*bc);
    if(area > AREA)
        return 1;
    return (area/(AREA-area)) - rat;
}

double getAD(double ab, double ac, double bc, double rat) {
    double high =(double) 10000000000, low =(double)0, mid;
    double AREA = getArea(ab, ac, bc);
    while(low <= high) {
        mid = (high+low)/2;
        double x = check(mid, ab, bc, ac, AREA, rat);
//        printf("high %lf low %lf mid %lf x %lf\n", high, low, mid, x);
        if(abs(x) <= .000000001) {
            return mid;
        } else if(x>0)
            high = mid - .0000000001;
        else
            low = mid+ .0000000001;
    }
}


int main()
{
    freopen("myOut.txt", "w", stdout);
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++) {
        double ab,ac,bc,rat;
        cin>>ab>>ac>>bc>>rat;
        double x = getAD(ab, ac, bc, rat);


//        double x = sqrt(rat/ (rat+1))*ab;


        printf("Case %d: ", tc);
        cout<<setprecision(10)<<x<<endl;
//        cout<<getAD(ab, ac, bc, rat)<<endl;
    }
    return 0;

}
