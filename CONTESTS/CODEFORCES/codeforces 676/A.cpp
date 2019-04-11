#include <bits/stdc++.h>
using namespace std;


int main()
{

//    freopen("myInput.txt","r", stdin);
    //freopen("myOutput.txt","w",stdout);

    int n;
    scanf("%d",&n);
    int ara[101];
    int mx=INT_MIN, mn= INT_MAX,mx_i, mn_i;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ara[i]);
        if(ara[i]>mx)
        {
        	mx=ara[i];
        	mx_i=i;
        }
        if(ara[i]<mn)
        {
        	mn= ara[i];
        	mn_i = i;
        }
    }
    mx_i++;
    mn_i++;
    mx_i = min(n, mx_i);
    mn_i = min(n, mn_i);
    int dist = 0;
    dist = max(dist, abs(mn_i - n ));
    dist = max(dist, abs(mn_i-1));
    dist = max(dist, abs(mx_i - n ));
    dist = max(dist, abs(mx_i-1));
	//cout<<mn_i<<" "<<mx_i<<endl;
    printf("%d\n", dist);

    return 0;
}

