#include <bits/stdc++.h>
using namespace std;
int ara[200011];

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &ara[i]);
    int carry=0;
    for(int i=0; i<n; i++) {
        if(ara[i]==0)
        {
            if(carry==1)
                break;
            continue;

        }

        ara[i]-=carry;
        carry=0;
        if(ara[i]&1) {
            carry =1;
        }


    }
    if(carry ==1 )
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
