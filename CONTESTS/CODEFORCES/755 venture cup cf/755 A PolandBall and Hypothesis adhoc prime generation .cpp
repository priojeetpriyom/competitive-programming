#include <bits/stdc++.h>
using namespace std;
bool gen[1000011];

void primeGen() {
    for(int i=2; i<=1000; i++) {
        if(!gen[i]) {
            for(int j = i*i; j<1000001; j+=i)
                gen[j] = true;
        }
    }
}

int main()
{
//        freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);
    primeGen();
    int n;
    cin>>n;

    for(int i = 1; i<1001; i++) {
        if(gen[(i*n)+1])
        {
            cout<<i;
            return 0;
        }
    }

    return 0;
}




