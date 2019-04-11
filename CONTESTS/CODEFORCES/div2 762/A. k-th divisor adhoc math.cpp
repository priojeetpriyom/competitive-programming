#include <bits/stdc++.h>
using namespace std;


long long ara[100000], lenAra=0;
int main()
{
//        freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    long long n,k;
    cin>>n>>k;
    int root = sqrt(n)+1;
    long long cnt=0, num;
    for(int i=1; i<root; i++) {
        if(n%i == 0) {
            ara[lenAra++] = i;
            if(i != n/i) {
                ara[lenAra++]  = n/i;
            }
        }
    }
//    printf("len %lld\n", lenAra);
    sort(ara, ara+lenAra);
    if(k>lenAra)
        cout<<-1;
    else
        printf("%lld\n", ara[k-1]);

    return 0;
}








