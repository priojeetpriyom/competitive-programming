

#include <bits/stdc++.h>




using namespace std;
typedef long long ll;
ll k;
bool sear(ll key, ll ara[], int len){
    int i=0;
    for(int high = len/2;high>0; high= high/2) {

        if(ara[i+high] <= key)
            i += high;

    }

    return key == ara[i];
}
int x, len;
void gen(int ara[], ll sum[], ll s , int i) {

    sum[len++] =s;
    if(i== x)
        return;
    gen(ara, sum, s+ara[i], i+1);
    gen(ara, sum, s+ara[i]+ara[i], i+1);
    gen(ara, sum, s, i+1);
}

bool calc(ll suma[], ll sumb[], int lena, int lenb) {
    sort(sumb, sumb+lenb);


    for(int i=0; i<lena; i++) {
        if(binary_search(sumb, sumb+lenb, k-suma[i]))
            return true;
    }
    return false;
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++) {
        int n;
        scanf("%d %lld", &n, &k);
        int ara[20];
        ll sumA[60000], sumB[60000];
        int lena, lenb;


        for(int i=0; i<n/2; i++)
        {
            scanf("%d", &ara[i]);
        }
        len=0;
        x = n/2;
        gen(ara, sumA,0,0);
        lena  = len;
        len=0;

        for(int i=n/2; i<n; i++)
        {
            scanf("%d", &ara[i - n/2]);
        }

        x = n-x;
        gen(ara, sumB,0, 0);
        lenb=len;




        printf("Case %d: ", tc);

        if(calc(sumA, sumB, lena, lenb))
           printf("Yes\n");
        else
            printf("No\n");
    }


    return 0;
}



