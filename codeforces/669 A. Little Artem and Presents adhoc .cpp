#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w",stdout);
    int n,x;
    scanf("%d",&n);
    x = n/ 3;
    x *=2;
    if(n %3 !=0)
        x++;
    printf("%d\n",x);
    return 0;
}

