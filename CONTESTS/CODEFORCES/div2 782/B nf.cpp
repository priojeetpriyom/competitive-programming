#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
double dist[60010], velocity[60010];

double time_cost(double pos) {
    double cost = 0;
    for(int i=0; i<n; i++) {
        cost= max(cost, (abs(pos - dist[i])/ velocity[i]));
    }
    return cost;
}


double bin_search(double high, double low, double mid) {
    double mn = 2000000000;
    while(high- low >= .000000000001) {
        double time_high = time_cost(high), time_low = time_cost(low);
//        printf("1 high %lf low %lf mid %lf time_high %lf time_low %lf\n", high, low, mid, time_high, time_low);
        mn = min(mn, time_high);
        mn = min(mn, time_low);
        mn = min(mn, time_cost(mid));
        if(time_high < time_low)
            low = mid+ .000000000001;
        else
            high = mid - .000000000001;
        mid = (high+low)/2;

//        printf("2 high %lf low %lf mid %lf\n", high, low, mid);
    }
//    if(mn == 2000000000) mn=0;
    return mn;
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);


    cin>>n;
    double high=0, low=INT_MAX;
    for(int i=0; i<n; i++) {
        scanf("%lf", &dist[i]);
        high = max(high, dist[i]);
        low = min(low, dist[i]);
    }

    for(int i=0; i<n; i++) {

        scanf("%lf", &velocity[i]);
    }

    printf("%.10lf\n", bin_search(high, low, (high+low)/2));

    return 0;
}


