#include <bits/stdc++.h>

using namespace std;


int main()
{

//    process[0]= {1,2,3};

//    cout<<process[0].id<<" "<<process[0].at<<" "<<process[0].bt<<endl;
    int t;

    scanf("%d", &t);
////    memset(ncr, -1, sizeof ncr);
//    memset(dp, -1, sizeof dp);

    int n, i;
        int sum, neg;
        int x;

    for(int tc=1; tc<=t; tc++)
    {
        sum=0, neg=0;
//        int n;
        scanf("%d", &n);
        for( i=1; i<=n; i++)
        {
            scanf("%d", &x);
            if(x<0)
                neg++;
            sum+=abs(x);
        }
        printf("Case %d: ", tc);
        neg = n- neg;
        if(!neg) {
            printf("inf\n");
            continue;
        }
        while(__gcd(sum, neg)!=1)
        {
            x = __gcd(sum, neg);
            sum/=x;
            neg/=x;
        }
        printf("%d/%d\n",sum, neg);

    }


    return 0;
}
