#include <bits/stdc++.h>
using namespace std;

int sum[100010];
int main()
{
//    freopen("myOut.txt", "w", stdout);

    int n;
    char str[100010];
    scanf("\n%s",str);
    n = strlen(str);

    str[n] = -1;
    for(int i=0; i<n; i++)
    {
        if(str[i] == str[i+1])
            sum[i+1] = 1;
    }
//    for(int i=1; i<= n; i++)
//        cout<<sum[i]<<" ";
//    cout<<endl;

    for(int i=1; i<= n; i++)
        sum[i] += sum[i-1];

//    for(int i=1; i<= n; i++)
//        cout<<sum[i]<<" ";
//    cout<<endl;
    int m;
    cin>>m;
    while(m--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", sum[r-1] - sum[l-1]);
    }
    return 0;
}



