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
        if(i==0) {
            if(ara[i]&1 || ara[i+1]&1 )
                carry = 1;

            continue;
        }
        if(ara[i]&1) {
            if(i != n-1 && ara[i+1]&1) {
                if(ara[i]==1 && carry==1)
                    carry=0;
                else
                    carry =1;
            }
            else if(carry==1)
                carry=0;
            else carry =1;
        } else {
            if(i != n-1 && ara[i+1]&1) {
                    carry =1;
            }

        }
    }
    if(carry ==1 )
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
