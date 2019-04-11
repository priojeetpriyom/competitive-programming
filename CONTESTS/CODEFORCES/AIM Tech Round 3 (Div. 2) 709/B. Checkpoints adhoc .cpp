#include <bits/stdc++.h>
using namespace std;

int positions[100100];

int main()
{
//    freopen("myOutput.txt","w",stdout);
    int n, start,ans=0;
    scanf("%d %d",&n, &start);

    for(int i=0;i<n; i++) {

        scanf("%d",&positions[i]);
    }
    if(n==1){
        printf("0\n");
        return 0;
        }
    positions[n++] = start;
    sort(positions,positions+n);

    for(int i=1; i<n; i++)
        ans+= (positions[i]-positions[i-1]);

    int ans1=0,ans2=0;

    int latest_start = 0;
    for(int i=0; i<n; i++) {
        if(positions[i] == start)
            {
                latest_start = i;
                break;
            }

    }

    for(int i=latest_start+1; i<n; i++)
    {

        ans1 = ans1+ (positions[i]-positions[i-1]);

    }

    for(int i=latest_start; i> 0; i--)
    {
        ans2 = ans2+ (positions[i]-positions[i-1]);

    }

    if(n>2) {
        if((positions[1]-positions[0])<(positions[n-1]-positions[n-2])) {
            ans -= (positions[n-1]-positions[n-2]);
            ans1-= (positions[n-1]-positions[n-2]);;
        } else if(((positions[1]-positions[0]) == (positions[n-1]-positions[n-2])) && latest_start< (n/2)) {

        } else {
                ans -= (positions[1]-positions[0]);
            ans2-= (positions[1]-positions[0]);;
        }
//        ans -= max((positions[1]-positions[0]),(positions[n-1]-positions[n-2]));
    }
//    printf("ans %d latest_start %d\n",ans,latest_start);

    if(latest_start>0 && latest_start!=n-1 && n>3) {
        if(ans1<ans2) {
        ans+=ans1;
    } else
        ans+=ans2;
    }

    printf("%d\n",ans);

    return 0;
}
