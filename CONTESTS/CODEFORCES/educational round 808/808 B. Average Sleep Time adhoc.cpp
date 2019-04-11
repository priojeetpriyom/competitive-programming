#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



double ara[200100];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    double n;
    int k;
    cin>>n>>k;
    double ans=0;
    double ans_db=0;
    double avg=0;
    double x = n-k+1;

//    for(int i=0; i<n;)


    for(int i=0; i<k-1; i++)
    {
        scanf("%lf", &ara[i]);
        avg+= ara[i]/x;
    }



    for(int i = k-1; i<n; i++) {
        scanf("%lf", &ara[i]);
        avg = avg  - ((i-k<0) ? 0:ara[i-k] /x) + (ara[i] /max(x,(double) 1) );

        ans+= avg;
    }
//    x=0;
//    x++;
//    x--;
//    if(x==0) x=0;


    printf("%.10lf\n", ans);

    return 0;
}


