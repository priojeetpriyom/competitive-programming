//1122 - Digit Count dp backtracking 

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll dp[111] [111];
int key, len;
char str[111];
void toStr(int n, int depth)
{

    if(n==0)
    {
        if(depth==0) str[len++] = '0';
        return;
    }
    toStr(n/10, depth+1);
    str[len++] = (n%10) +'0';
}


ll rec(int len, int cnt)
{
    if(!len) return cnt;
    ll &ret= dp[len] [cnt];
    if(ret != -1) return ret;
    ret=0;
    for(int i=0; i<10; i++)
        ret+= rec(len-1, cnt+ (i==key));
    return ret;
}

ll calc()
{
    int track=0;
    ll ans=0;
    for(int i=1; i<len; i++)
    {
        for(int j=1; j<10; j++)
        {
            ans+= rec(i-1, j == key);
        }
//        printf("%d\n",ans);
    }
//    printf("pre_ans %lld str %s\n", ans, str);


    for(int j=1; j< str[0]-'0'; j++)
    {
        ans+= rec(len-1, j==key );
    }
    track = (str[0]-'0')==key;

    for(int i=1; i<len; i++)
    {
        for(int j=0; j< str[i]-'0'; j++)
        {
            ans+= rec(len-i-1, (j==key) +track);
        }
        track+= (key == (str[i]-'0'));
//        printf("i %d track %d ans %lld\n", i, track, ans);
    }




//    printf("\nstr %s, len %d str[len-1] %c key %d\n",str,len, str[len-1], key);
    ans+= (track );
    return ans;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    memset(dp, -1, sizeof dp);
    int a,b;
    ll ans[11];
    while(scanf("%d %d",&a, &b)==2 && a!=0)
    {
        len =0;
        toStr(b, 0);
        str[len] = '\0';
//        printf("b %s\n", str);
        for(int i=0; i<10; i++)
        {
            memset(dp, -1, sizeof dp);
            key = i;
            ans[i] = calc();
//            printf("%lld ", ans[i]);
        }
//        printf("\n");
        len =0;
        toStr(a-1, 0);
        str[len] = '\0';
//        printf("a %s\n", str);
        if(a!= 1)
        for(int i=0; i<10; i++)
        {
            memset(dp, -1, sizeof dp);
            key = i;
            ll x = calc();

//            printf("%lld ", x);
            ans[i] = max(0LL, ans[i] - x);
        }
//        printf("\n");

        for(int i=0; i<10; i++)
        {
            if(i>0) printf(" ");
            printf("%lld",ans[i]);
        }
        printf("\n");

//        len=0; toStr(0, 0);str[len] = '\0';cout<<len<<" "<<str<<endl; key=0; cout<<calc();

    }

//    printf("len %d str %s\n", len, str);
//    cout<<;




    return 0;
}
