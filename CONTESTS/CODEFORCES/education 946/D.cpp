#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 505

char str [MX][MX];
ll dp[MX][MX];
int n, m, k;
int sufLessons[MX] [MX];
int lastClass[MX];
int firstClass[MX];
ll rec(int day, int canMiss)
{
//    printf("day %d canMiss %d\n",day, canMiss);
    if(canMiss<0)
        return 1e9;
    if(day == n+1)
    {
        return 0;
    }
    ll &ret = dp[day] [canMiss];
    if(~ret)
        return ret;
    ret = 1e9;
//    int i, j;

    if(canMiss)
    {
        for(int i=max(firstClass[day],1); i<=m; i++)
        {
            for(int j=i; j<=lastClass[day]; j++)
            {
                ret= min(ret, rec(day+1, canMiss - (sufLessons[day][1]- sufLessons[day] [i] + sufLessons[day][j+1])) +(j-i+1));
//                 printf("day %d canMiss %d i %d j %d ret %lld\n",day, canMiss, i, j, ret);
            }
        }
        ret = min(ret, rec(day+1, canMiss - sufLessons[day][1]));

    }
    else
        ret= rec(day+1, canMiss)+ lastClass[day]-firstClass[day]+1;

//    for(int i=1; i<=m; i++)
//    {
//        ret = min(ret, rec(day+1, canMiss - (sufLessons[day][1]- sufLessons[day] [i]))+ (lastClass[day]-i+1));
//        ret = min(ret, rec(day+1, canMiss - (sufLessons[day] [i+1]))+ (i));
//
////        printf("day %d i %d ret %lld\n",day, i, ret);
//    }

//    printf("day %d canMiss %d ret %lld\n",day, canMiss, ret);
    return ret;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);
    memset(dp, -1, sizeof dp);

//    cin>>n>>m>>k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<=n; i++)
        scanf("\n%s", str[i]+1);
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
//        bool flag = 0;
        for(int j=m; j>0; j--)
        {
//            if(str[i][j] == '1')
//                flag=1;
            cnt+= (str[i][j]-'0');
            sufLessons[i][j] = (str[i][j]-'0') + sufLessons[i][j+1];
            if(str[i][j]=='1' && !lastClass[i])
                lastClass[i] = j;
            if(str[i][j]=='1')
                firstClass[i]=j;
        }
//        if(!lastClass[i])
//            lastClass[i]=m;
    }
//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=m; j++)
//            printf("%d ", sufLessons[i][j]);
//        printf("\n");
//    }

//    cout<<rec(1,k)<<endl;
    if(k>=cnt)
    {
        printf("0\n");
        return 0;
    }
    printf("%lld\n", rec(1, k));


    return 0;
}


