#include <stdio.h>

#include <string.h>
#include <algorithm>

using namespace std;
typedef long long ll;
#define MX 21

char str[MX], ans[MX];
ll fact[MX];
ll  nth;
int taken[MX];
int len;

ll calc(int pos)
{

    int dup[26] = {0};

    int cnt=0;
    for(int i=0; i<len; i++)
    {
        if(taken[i] || i==pos) continue;
        dup[str[i]-'a' ]++;
        cnt++;

    }
    ll res = fact[cnt];


    for(int i = 0; i<26; i++)
        if(dup[i]>1)
        {
            res/= fact[dup[i]];
        }
    return res;


}


int main()
{

    fact[0]=1;
    for(ll i=1; i<=20; i++)
        fact[i] = fact[i-1]*i;

    int t,i;
    scanf("%d", &t);
    for(int tc=1; tc<=t; tc++)
    {

        scanf("\n%s %lld", str, &nth);

        printf("Case %d: ",tc);

        len = strlen(str);
        sort(str, str+len);

        if(nth==1)
        {
            printf("%s\n", str);
            continue;
        }


        memset(taken, 0, sizeof taken);

        if(nth> calc(-1))
        {
            printf("Impossible\n");
        }
        else
        {
            int pos=0;
            while(nth)
            {

                int used[26]= {0};

                for(int i=0; i<len; i++)
                {
                    if(!taken[i])
                    {
                        ll res = calc(i);

                        while(res< nth )
                        {
                            nth-=res;
                            used[str[i]-'a' ] =1;
                            i++;
                            while( (taken[i] || used[ str[i]-'a' ]) && i<len)
                            {
                                i++;
                            }
                            res = calc(i);

                        }

                        ans[pos] = str[i];

                        taken[i]=1;


                        break;
                    }

                }
                ans[pos+1] = '\0';

                pos++;
                if(nth==1)
                {
                    for(int i=0; i<len; i++)
                        if(!taken[i])
                            ans[pos++] = str[i];
                    nth=0;
                }

            }

            ans[len] = '\0';
            printf("%s\n", ans);

        }



    }



    return 0;
}
