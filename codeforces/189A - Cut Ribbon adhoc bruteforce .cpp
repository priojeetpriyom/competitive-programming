#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,mx=1;
//int ara[5];
bool found;
//void calc(int x,int cnt)
//{
//    if(x<0 || found)
//        return;
//
//    calc(x-a, cnt+1);
//    calc(x-b,cnt+1);
//
//    if(x%c ==0)
//    {
////        printf("cnt %d x %d\n",cnt, x);
//        mx = max(cnt+ (x/c),mx);
//        found=true;
//        return;
//    }
//
//
//}

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);


    int cnt=1;
    scanf("%d %d %d %d",&n, &a, &b, &c);
    if(a>b)
        swap(a,b);
    if(a>c)
        swap(a,c);
    if(b>c)
        swap(b,c);
    int sum=0;
    for(int i=n/a; i>=0; i--) {
        for(int j=(n- i*a)/b; j>=0; j--) {
            sum = n - (i*a + j*b);

            if(sum>=0 && sum % c ==0) {
                mx = max(mx,i+j+ (sum/c));
//                found = true;
                ;
            }
        }
//        if(found) break;
    }
    printf("%d\n", mx);

    return 0;
}
