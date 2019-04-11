#include <bits/stdc++.h>
using namespace std;
bool prime_generate[100000];
map<string,bool> mp;
void sieve() {
    for(int i=3; i<1000000; i+=2) {
        if(!prime_generate[i]) {
            for(int j = i*i; j<1000000; j+=i)
                prime_generate[j] = true;
        }
    }

}

int main()
{
//    freopen("myOutput.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++) {
        int a,b;
        scanf("%d %d",&a,&b);

        printf("Case %d: ",i);
        long long cost = log10(a);
        int digit=0;
        while(a!=b) {
            cost+=a;
            if(a>b) {
                if()
                else if(prime_generate[a - getpower(digit)]) {
                   a =  prime_generate[a - getpower(digit);
                } else {

                }
            } else {

            }
        }
    }
    return 0;
}
