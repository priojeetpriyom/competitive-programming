#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//const int MX 100100;


string s;
ll cum[100100];
ll ans=0;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin>>t;

    cin.ignore();
    while(t--)
    {
        cin>>s;
        int len = s.size();
        ans= 0;
        cum[len-1]=1;
        for(int i=len-2; i>=0; i--)
        {
            if(s[i] == s[i+1])
            {
                cum[i] = cum[i+1] +1;
            }
            else
                cum[i]=1;

        }


        for(int i=0; i<len-1; i++)
        {
            if(cum[i]==2)
                ans++;
            if(len-i>=3)
            {
                if(cum[i]>=3)
                {
//                    printf("aise\n");
                    ll n = cum[i]-3+1;
                    ans += ((n* (n+1)) /2 );
//                    printf("1 i %d ans %lld\n", i , ans);
                    while(cum[i]!=1)
                    {
                        i++;
                        ans++;
                    }
//                    printf("2 i %d ans %lld\n", i , ans);
                    i--;
                }
                else
                {
//                    printf("3 i %d ans %lld\n", i , ans);

                    int l = i, r = i+cum[i+1]+1;
//                    printf("l %d r %d\n", l, r);
                    if(( r<len) && s[l]==s[r])
                    {
                        if( (s[l+1] == s[r-1])&& (cum[l+1]- cum[r-1]+1  == (r-l-1) ))
                        {
                            ans++;

                        }
                    }
                }

            }
//            printf("i %d ans %lld\n", i, ans);
//            while(cum[i]!=1)
//            {
//                i++;
//                ans++;
//            }
        }


        cout<<ans<<endl;
    }



    return 0;
}


