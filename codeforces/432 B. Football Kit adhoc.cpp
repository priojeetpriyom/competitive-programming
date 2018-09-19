#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myOutput.txt","w",stdout);
    //freopen("myInput.txt",")
    int n;
    int HOME[100001],AWAY[200001],home,away,awayOrder[200001];
    scanf("%d",&n);
    for(int i=0; i<100001; i++)
    {
        HOME[i]=0;
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&home, &AWAY[i]);
        HOME[home]++;
        //AWAY[away]++
    }
//    for(int i=0; i<n; i++)
//    {
//        printf("home %d away %d\n",HOME[AWAY[i]], AWAY[i]);
//    }
    for(int i=0; i<n; i++)
    {
        printf("%d %d\n",n-1+(HOME[AWAY[i]]), n-1-(HOME[AWAY[i]]));
    }
    return 0;
}


