#include <bits/stdc++.h>

using namespace std;

//typedef ll long long;

int main() {
//   freopen("out.txt", "w", stdout);
    int n, x;
    cin>>n>>x;
    n%=6;
    int ara[5] = {0,1,2};

    for(int i=0; i<n; i++) {
        if(i%2==0) {
            swap(ara[0], ara[1]);
        } else
            swap(ara[1], ara[2]);
    }

    printf("%d\n", ara[x]);

    return 0;
}
