#include <bits/stdc++.h>
using namespace std;

int n,t;
int ara[101], dp[4004] [21];

int rec (int dif, int cnt)
{

    if(cnt==n)
    {
//        printf("diff %d abs %d\n", dif, abs(dif));
        return (abs(dif) == 0);
    }

    int &ret = dp[abs(dif)] [cnt];

    if(ret!= -1)
        return ret;
    ret = INT_MIN;

    ret = max(ret, rec(dif+ara[cnt], cnt+1));
//        printf("1 returned %d cnt %d\n", dp[dif] [cnt], cnt);

    ret = max(ret, rec(dif-ara[cnt], cnt+1));
//        printf("2 returned %d cnt %d\n", dp[dif] [cnt], cnt);

    return ret;
}

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    scanf("%d", &t);
    getchar();
    while(t--)
    {
//        scanf("%d", &n);
//
//        for(int i=0; i<n; i++)
//            scanf("%d", &ara[i]);
        char str[100];
        n=0;
//        while((scanf("%d", &ara[n])) != '\n')
//            n++;


        gets(str);
//        printf("%s\n", str);
        int len = strlen(str);

        for(int i=0; i<len; i++)
        {
            if(str[i]!= ' ')
            {
//                printf("i %d ",i);
                if(str[i+1] != ' ' && str[i+2]!= ' ' && i+2<len)
                {
//                    printf("1\n");
                    ara[n++] = (str[i]-'0')*100 + (str[i+1]-'0')*10 + str[i+2]-'0';
                    i+=2;
                }
                else if(str[i+1] != ' ' && i+1!=len)
                {
//                    printf("1\n");
                    ara[n++] = (str[i]-'0')*10 + str[i+1]-'0';
                    i+=2;
                }
                else
                {
//                    printf("2\n");
                    ara[n++] = (str[i]-'0');
                    i++;
                }
            }
        }

//        for(int i=0; i<n; i++)
//            printf("%d ", ara[i]);
//        printf("\n");

        memset(dp, -1, sizeof(dp));
        if(rec(0,0))
            printf("YES\n");
        else
            printf("NO\n");

    }

    return 0;
}
