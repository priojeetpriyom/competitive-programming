#include<bits/stdc++.h>
using namespace std;
int ara[200100], ans[200100];

int main()
{
//    freopen("myOut.txt", "w", stdout);
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        scanf("%d", &ara[i]);

    int i=0,l=0, r=n-1, p1=0, p2=0;
    while(l<=r) {
        if(i%2==0) {
            ans[r] = ara[l];
            ans[l] = ara[r];
            l++;
            r--;
        } else {
            ans[l] = ara[l];
            ans[r] = ara[r];
            l++;
            r--;
        }

        i++;
    }
    for(int i=0; i<n; i++)
        printf("%d ",ans[i]);
    return 0;

}

