#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int n, k;
    char str[111];
    int pass[102];
    memset(pass,0,sizeof(pass));
    scanf("%d %d",&n,&k);
    int len_match;
    for(int i=0; i<n; i++) {
        scanf("\n%s",str);
        pass[strlen(str)]++;
    }

    scanf("\n%s",str);
    len_match = strlen(str);

    int time_min=1,time_max;

    for(int i=1; i<len_match; i++) {
        time_min += pass[i];
    }

    time_max = time_min + pass[len_match]-1;

    time_min = time_min + (time_min/k - (time_min%k==0))*5;
    time_max = time_max + (time_max/k - (time_max%k==0))*5;

    printf("%d %d\n",time_min,time_max);


    return 0;
}
