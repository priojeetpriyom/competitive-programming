#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MX 100100
#define MOD 1000000007


int dp [MX] [3];
int n;
double xx[MX],yy[MX], path[MX];
int exitcode;
double threshold = 1500000;

double get_dist(double x, double y);

bool check_valid(double x, double y);

void rec(int pos, int taken, double x, double y) {
//    cout<<"pos "<<pos<<endl;
    if(exitcode)
        return;
    if(pos==n) {
            for(int i=0; i<n; i++) {
                if(path[i])
                 printf("1 ");
                 else
                    printf("-1 ");
            }
            printf("\n");
            exitcode=1;
            return;
    }
    int & ret = dp[pos] [taken];
    if(~ret) {
        return;
    }
    ret =0;
//    cout<<"aise"<<endl;
    if(check_valid(x+xx[pos], y+yy[pos])) {
        path[pos] =1;
        rec(pos+1, 1, x+xx[pos], y+yy[pos]);
    }
    if(check_valid(x-xx[pos], y-yy[pos])) {
        path[pos]=0;
        rec(pos+1, 0, x-xx[pos], y-yy[pos]);
    }
}

bool check_valid(double x, double y) {
    return get_dist(x,y)<= threshold;
}

double get_dist(double x, double y) {
    cout<<"x "<<x<<" y "<<y<<" dist "<<sqrt(x*x+ y*y)<<endl;
    return  sqrt(x*x+ y*y);
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);
    memset(dp, -1, sizeof dp);

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%lf %lf", &xx[i], &yy[i]);
        cout<<"xx "<<xx[i]<< " yy "<<yy[i]<<endl;
    }

    rec(0,0,0,0);


    if(!exitcode)
        printf("-1\n");


    return 0;
}



