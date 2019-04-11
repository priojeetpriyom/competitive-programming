#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w", stdout);
    long long amountLeft,distress=0;
    int n;
    scanf("%d %I64d",&n,&amountLeft);
    while(n--) {
        char c;
        int x;
        scanf("\n%c %d",&c, &x);
//        printf("oka");
        if(c=='+') {
            amountLeft+=x;
        }
        else
        {
            if(x>amountLeft)
                distress++;
            else
                amountLeft-=x;
        }

    }
    getchar();
    printf("%I64d %I64d\n",amountLeft,distress);
    return 0;
}

