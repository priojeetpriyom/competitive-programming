#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int main()
{
//    freopen("myOut.txt", "w", stdout);

    int n;
    cin>>n;
    int x,ara[102];
    for(int i=1; i<=n; i++) {
        cin>>x;
        ara[x] =i;
    }

    for(int i=1; i<=n; i++)
        printf("%d ",ara[i]);
    return 0;
}



