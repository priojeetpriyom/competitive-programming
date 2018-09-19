#include <bits/stdc++.h>
using namespace std;

#define N 100000000
int  primeGenerate[N/32 +1];

bool Check(int n, int pos)
{
    return (bool) (n & (1<<pos));
}
void setValue(int n)
{
    primeGenerate[n>>5] = (primeGenerate[n>>5] | (1<< (n&31)));
}

void sieve ()
{

    int root = sqrt(N)+1;
    for(int i= 3; i<root; i+=2)
    {
        if(!Check(primeGenerate[i>>5], i&31))
        {
//            printf("%d ",i);
            for(int j = i*i; j<= N; j+=i*2)
            {
                setValue(j);
            }
        }
    }
    puts("2");
    int cnt=1;
    for(int i=3; i<=N; i+=2)
        if(!Check(primeGenerate[i>>5], i&31))
            {
                cnt++;
                if(cnt%100 ==1)
                    printf("%d\n", i);

            }
}
int main()
{
    freopen("myOutput.txt","w",stdout);
//    freopen("myInput.txt","r", stdin);
//    for(int i=0; i<= N/32; i++)
//        printf("%d ",primeGenerate[i]);
    sieve();
    //printf("%d\n",(5>>2));
    return 0;
}

