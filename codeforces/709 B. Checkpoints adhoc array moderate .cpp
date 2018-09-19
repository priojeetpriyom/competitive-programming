#include <bits/stdc++.h>
using namespace std;

int positions[100100];

int main()
{
//    freopen("myInput.txt","r",stdin);
//    freopen("myOutput.txt","w",stdout);
    int n, start;
    scanf("%d %d",&n, &start);

    for(int i=0; i<n; i++)
        scanf("%d",&positions[i]);

    if(n==1)
    {
        printf("0\n");
        return 0;
    } else if(n==2) {
        printf("%d\n", min(abs(positions[0]-start),abs(positions[1] - start)));
        return 0;
    }

    positions[n++] =start;
    sort(positions,positions+n);


    int ans1=0,ans2=0;

    int latest_start = 0;
    for(int i=0; i<n; i++)
    {
        if(positions[i] == start)
        {
            latest_start = i;
            break;
        }

    }

//    ans1 = abs(positions[latest_start]);
int lim = min(latest_start,n-latest_start-1),lim1 = latest_start+lim,lim2=latest_start-lim;
int ans1Frac=0,ans2Frac=0;

    for(int i=latest_start+1; i<n; i++)
    {

        ans1 = ans1+ (positions[i]-positions[i-1]);

    }

//    for(int i=latest_start+1; i<=lim1; i++)
//    {
//
//        ans1Frac = ans1Frac+ (positions[i]-positions[i-1]);
//
//    }

    for(int i=latest_start; i> 0; i--)
    {
        ans2 = ans2+ (positions[i]-positions[i-1]);

    }

//    for(int i=latest_start; i> lim2; i--)
//    {
//        ans2Frac = ans2Frac+ (positions[i]-positions[i-1]);
//
//    }

//    printf("ans1 %d ans2 %d\n",ans1,ans2);

//    if(latest_start==0 )
//    {
//        ans1-= (positions[n-1]-positions[n-2]);
//        printf("%d\n",ans1);
//    }
//    else if((latest_start==1 && (((positions[1] -positions[0])*2)>= (positions[n-1] -positions[n-2]) ))) {
//        printf("%d\n",ans1);
//    }
//    else if(latest_start == n-1)
//    {
//        ans2 -= (positions[1]-positions[0]);
//        printf("%d\n",ans2);
//    }
//    else if((latest_start== n-2 && (((positions[n-1] -positions[n-2])*2)>= (positions[1]-positions[0]) ))) {
//        printf("%d\n",ans2);
//    }
//    else
//    {
        if(((ans1<ans2) && ans1!=0) || ans2==0)
        {
            if(((positions[n-1] - positions[n-2])*2 >(positions[1]-positions[0])) || ans2==0)
                ans1-= (positions[n-1] - positions[n-2]);
            else
                ans2-= (positions[1]-positions[0]);
        }
        else{
                if((((positions[n-1] - positions[n-2]) <(positions[1]-positions[0])*2 )) || ans1==0)
                    ans2-= (positions[1]-positions[0]);
                else
                    ans1-= (positions[n-1] - positions[n-2]);
            }

        int z1,z2;
//        if((ans1<ans2) || ((ans1Frac<ans2)&&((n-latest_start-1)<latest_start )))
//        {
            z1 = ((ans1)*2)+(ans2);
//        }
//        else
//        {
            z2 = (ans1) + ((ans2)*2);
//        }
        printf("%d\n",min(z1,z2));
//    }


//    z = max(z,0);


    return 0;
}


