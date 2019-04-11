/*
    algo:
    idea:

*/
#include <iostream>

#define LIM 100100
using namespace std;

int ara[LIM>>5];

bool Check(int n) {
    int bit = ara[n>>5];
    int pos = n&31;
    return ((bit>>pos)&1);
}

void Set(int n) {
    int &bit = ara[n>>5];
    int pos = n&31;

    bit = bit | (1<<pos);
}

void bit_sieve(int lim) {

    // int rt = sqrt(lim);

    for(int i=2; i*i<=lim; i++) {
        if(!Check(i)) {
            for(int j = i*i; j<=lim; j+=i) {
                Set(j);
            }
        }
    }

    for(int i=2; i<=100; i++)
        if(!Check(i))
            cout<<i<<endl;

}

int main()
{
//    FAST_READ

    bit_sieve(100);

    return 0;
}
