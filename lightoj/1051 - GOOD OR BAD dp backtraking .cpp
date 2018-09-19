#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 51


char str[MX];
int len;
int dp[MX] [3] [5];
//int vow[150];

int rec(int pos, int v, int c) {
    if(v>=3 || c>=5)
        return 1;
    if(pos == len)
        return 2;
    int &ret = dp[pos][v] [c];

    if(~ret)
        return ret;

    if(str[pos] =='?') {
        ret = rec(pos+1, v+1, 0) | rec(pos+1, 0, c+1);
    } else if(str[pos])
        ret = rec(pos+1, v+1, 0);
    else
        ret = rec(pos+1, 0, c+1);

    return ret;

}



int main()
{

    int t,i;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++)
    {
        memset(dp, -1, sizeof dp);
        scanf("\n%s", str);
        len  = strlen(str);
        for(i=0; i<len; i++) {
            if(str[i]=='?')  ;
            else if(str[i]=='A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
                str[i]==1;
            else
                str[i]=0;
        }
        printf("Case %d: ",tc);

        if(rec(0, 0 , 0)==1)
        {
            printf("BAD\n");
            continue;
        }
        else if(rec(0, 0, 0)==2)
        {
            printf("GOOD\n");
        }
        else
            printf("MIXED\n");


    }



    return 0;
}
