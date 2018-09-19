/*
    algo:
    idea:

*/
//
//
//#include<stdio.h>
//#include<string.h>

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 500010
//#define mod 1000000007
int ara[MX];

ll cnt[MX] ,sum[MX];
int main()
{
//freopen("output.txt", "w", stdout);


    int n;
        scanf("%d", &n);
        

        ll ssum=0;
        
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &ara[i]);
            ssum+= ara[i];
     //       if(ara[i]!=0)
		//		allZero=false;
        }

        if(ssum%3 !=0 || n<3)
         {
            printf("0\n");
            return 0;
         }
      ll temp=0, part = ssum/3;
      
     for(int i=n; i>=1; i--) {
		 temp+= ara[i];
		 if(temp== part) {
			cnt[i]=1;
			 }
	 }
	 
	 
      sum[n+1]=0;
     for(int i=n; i>=1; i--) {
		 sum[i] = cnt[i]+ sum[i+1];
	 }
	 ll ans=0;
	 temp=0;
	 for(int i=1; i<=n-2; i++){
		 temp+= ara[i];
		 if(temp == part)
		 ans+= sum[i+2];
		 }
	 
	 
	 

	printf("%lld\n", ans);
    return 0;
}

