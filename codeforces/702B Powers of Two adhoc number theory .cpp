#include <bits/stdc++.h>
using namespace std;
int ara[100005];
unsigned int powers[33];
void generate_powers_of_two()
{
    unsigned int n=1;
    for(int i=0; i<32; i++)
    {
        powers[i]=n;
        n*=2;
    }
}

int main()
{
//    freopen("myOutput.txt","w",stdout);
    generate_powers_of_two();
    map<int,int> mp;
    int n,x;
    scanf("%d",&n);
    long long cnt=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);

        for(int k=0; k< 32; k++)
        {
            if(powers[k]>=x && mp[powers[k]-x])
            {
                cnt+= mp[powers[k]-x];
            }

        }
        mp[x]++;

    }
    printf("%I64d\n",cnt);
    return 0;
}

