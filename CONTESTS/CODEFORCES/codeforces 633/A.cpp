#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,sum;
    bool yes=false;
    scanf("%d %d %d",&a, &b, &sum);
    if(sum%a == 0 || sum%b==0 )
        yes=true;
    else if(a%2==0 &&b%2==0 && sum%2==1);
    else
    {
        while(sum>0)
        {
            sum-=a;
            if(sum%b==0)
            {
                yes=true;
                break;
            }
        }
    }
    if(yes)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
