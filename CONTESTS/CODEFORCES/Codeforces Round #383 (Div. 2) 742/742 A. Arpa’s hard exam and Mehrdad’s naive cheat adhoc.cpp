

#include <bits/stdc++.h>
using namespace std;
//vector<int> vec;

int main()
{
//    freopen("myOut.txt", "w", stdout);
    int ara[] = {8,4,2,6};
    int n;
    scanf("%d", &n);
    if(n==0) {
        printf("1\n");
        return 0;
    }
    n--;
    printf("%d\n", ara[n%4]);
    return 0;
}

