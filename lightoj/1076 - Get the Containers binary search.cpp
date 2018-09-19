#include<bits/stdc++.h>
using namespace std;
long long vessel[1000100];

bool valid(long long vol, int containers, int vessels)
{
    int cnt=0;
    for(int i=0; i<vessels && cnt<=containers; i++)
    {
        long long sum=0;
        for(int j=i; j<vessels; j++)
        {
            if(sum + vessel[j] <= vol )
            {
                sum+= vessel[j];
                if(j == vessels-1)
                {
                    i = j;
                    cnt++;
                    break;
                }
            }
            else
            {
                i = j-1;

                cnt++;
                sum=0;
                break;
            }

        }
    }
//    printf("volume %lld cnt %d containers %d vessels %d\n", vol, cnt, containers, vessels);
    return cnt<= containers;

}

long long getMinContainerVolume(long long high, long long low, int containers, int vessels)
{
    long long mid, mn=INT_MAX;
    while(low <= high)
    {
        mid = (high+low)>>1;
        if(valid(mid, containers, vessels))
        {
            if(mid<mn)
                mn= mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return mn;
}

int main()
{
    int n, containers,vessels;
    int t;
    cin>>t;
    long long high=0;
    for(int tc=1; tc<=t; tc++)
    {
        scanf("%d %d", &vessels, &containers);

        for(int i=0; i<vessels; i++)
        {
            scanf("%lld", &vessel[i]);

            high += vessel[i];
        }

        printf("Case %d: ", tc);
        printf("%lld\n", getMinContainerVolume(high, 0, containers, vessels));



    }
    return 0;
}

