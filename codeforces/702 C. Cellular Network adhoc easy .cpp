#include <bits/stdc++.h>
using namespace std;

int city[100001],tower[100001];
//int dist[100001];

int main()
{
//    freopen("myInput.txt","r",stdin);
//    freopen("myOutput.txt","w",stdout);

    int cities,towers,dist=INT_MIN;

    scanf("%d %d",&cities, &towers);

    for(int i=0; i<cities; i++)
        scanf("%d",&city[i]);

    for(int i=0; i<towers; i++)
        scanf("%d",&tower[i]);

//    sort(city,city+cities);
//    sort(tower,tower+towers);

    if(towers==1) {
        printf("%d\n",max(abs(city[0]-tower[0]),abs(city[cities-1]- tower[0])));
        return 0;
    }

    for(int c=0,t=0; c<cities; c++) {
        int a = abs(city[c]-tower[t]), b = abs(city[c] - tower[t+1]);
        int x=min(a,b);

        while(a>=b && t!= towers-2) {
                t++;
            a = abs(city[c]-tower[t]), b = abs(city[c] - tower[t+1]);
            x = min(x,min(a,b));
        }
        dist = max(dist, x);
    }
    printf("%d\n",dist);

    return 0;
}


