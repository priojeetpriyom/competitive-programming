#include<bits/stdc++.h>
using namespace std;

int city[100005], tower[100005],len_city,len_tower;

int main ()
{
//    scanf("%d",&t);
    scanf("%d %d",&len_city,&len_tower);

    for(int i=0; i<len_city; i++) {
        scanf("%d",&city[i]);
    }
    for(int i=0; i<len_tower; i++) {
        scanf("%d",&tower[i]);
    }

    int mx =0;
    if(city[0]>tower[0])
        mx = abs(city[0]-tower[0]);
    else
        mx = abs(tower[0]-city[0]);

    int k=0,prev_city=city[0];
    for(int i =0; i<len_city; i++) {
        if(city[i]>tower[k]) {
            mx = max(abs(tower[k] -prev_city),mx);
            int x =i;
            while(city[i]<= tower[k] + mx) {
                prev_city=city[i++];
            }
            k++;
            if(k==len_tower)
            {
                mx =max (abs(city[len_city-1]-tower[k-1]),mx);
                break;
            }
        }
    }
    printf("%d\n",mx);

    return 0;
}

