#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pll;
#define MX 100100

char str[MX];


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;

    scanf("%d", &t);

    while(t--)
    {
        int n, a, l;

        scanf("%d %d", &n, &a);
        str[n+1] = '\0';
        if(a>=n) {
            l=1;
            for(int i=1; i<=n; i++)
                str[i] = 'a' + (i-1);
        }
        else if(a==1)
        {
            for(int i=1; i<=n; i++)
            {
                str[i] = 'a';
            }
            l = n;
        }
        else if(a==2)
        {
            l=1;
            str[1] = 'a';
            str[2] = 'a';
            str[3] = 'b';
            str[4] = 'b';
            str[5] = 'b';
            str[n+1] ='\0';
            if(n==2);
            else if(n==3)
            {
                l=2;
            }
            else if(n==4)
            {
//                swap(str[2], str[3]);
                l=2;
            }
            else if(n==5)
            {
                l=3;
            }
            else if(n==6)
            {
                str[3]='a';
                str[6]='b';
                l=3;
            } else if(n==7 || n==8) {
                str[1] = str[2] = str[3] = str[5] = 'a';
                str[4] = str[6] = str[7] = str[8] = 'b';
                str[n+1] = '\0';
                l=3;
            }

            else
            {
                char temp[] = "abaabb";
                int len_temp = 6;
                for(int i=1; i<=n;)
                {
                    for(int j = 0; j<6 && i+j<=n; j++)
                    {
                        str[i+j] = temp[j];
                    }
                    i+=6;
                }
                l=4;
            }
        }
        else
        {
            for(int i=1; i<=n;)
            {
                for(int j = 0; j<a && i+j<=n; j++)
                {
                    str[i+j] = 'a' + j;
                }
                i+=a;
            }
            l=1;
        }

        printf("%d %s\n", l, str+1);


    }


    return 0;
}

