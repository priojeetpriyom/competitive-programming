#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dp[1<<12], n;
char str[12];
int SET(int mask, int pos)
{
    return mask | (1<<pos);
}

int RESET(int mask, int pos)
{
    return mask & (~(1<<pos));
}
int CHECK(int mask, int pos)
{
    return mask & (1<<pos);
}

void print_mask(int mask)
{
    for(int i=0; i<12; i++)
    {
        printf("%d ", (bool)CHECK(mask, i));
    }
    printf("\n");
}

int rec(int mask)
{

    int &ret = dp[mask];
//    print_mask(mask);
//    printf("mask %d bit_count %d\n", mask, __builtin_popcount((unsigned int) mask));
    if(ret!=INT_MAX) return ret;
    for(int i=0; i<12; i++)
    {
//        if(i==3) {
//            printf("i %d check_i %d check_i+1 %d\n", i, CHECK(mask, i), CHECK(mask, i+1));
//        }
        if(CHECK(mask, i) && i>1 && CHECK(mask, i-1)&& !CHECK(mask, i-2))
        {
//            printf("on i %d\n", i);


            mask = RESET(mask, i);
            mask = RESET(mask, i-1);
            ret = min(rec(SET(mask, i-2)),ret );
            mask = SET(mask, i);
            mask = SET(mask, i-1);

        }
        if(CHECK(mask, i) && i<10 && CHECK(mask, i+1)&& !CHECK(mask, i+2))
        {

            mask = RESET(mask, i);
            mask = RESET(mask, i+1);
            ret = min(rec(SET(mask, i+2)),ret );
            mask = SET(mask, i);
            mask = SET(mask, i+1);

        }
    }
    if(ret == INT_MAX) ret = __builtin_popcount( (unsigned int)mask);
    return ret;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    int x,y; cin>>x>>y; cout<<RESET(x, y);
    cin>>n;
    char c;
    while(n--)
    {
        for(int i=0; i<(1<<12); i++) dp[i] = INT_MAX;
        int mask=0;
        for(int i=0; i<12; i++)
        {
            scanf("\n%c", &c);
            if(c=='o')
            {
//                printf("%d ", i);
                mask = SET(mask, i);
            }
        }
//        for(int i=0; i<12; i++) {
//            printf("%d ", (bool)CHECK(mask, i));
//        }
//        printf("\n");
//        printf("mask %d pop_count %d\n", mask, __builtin_popcount(mask));

        printf("%d\n", rec(mask));
    }

    return 0;
}





