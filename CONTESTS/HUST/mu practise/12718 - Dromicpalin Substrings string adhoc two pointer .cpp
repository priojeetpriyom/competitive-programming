#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myInput.txt","r",stdin);
//    freopen("myOutput.txt","w",stdout);

    int tcase;
    scanf("%d",&tcase);
    tcase++;
    for(int t=1; t<tcase; t++)
    {

        char str[1001];
        scanf("\n%s",str);
        printf("Case %d: ",t);

        int dist=1, len=strlen(str), palindroms=len;

        while(dist!= len)
        {
            int chars[28] = {0};
            int i=0, j= dist;
            for(int k=0; k<=j; k++)
                {
                    chars[str[k]-'a']++;
                }

            for( ; j<len; i++,j++)
            {

                bool isPalindrom=true;
                if((j-i) &1==0 )
                {
                    for(int k=0 ; k<26; k++)
                    {
                        if(chars[k]&1 !=0)
                        {
                            isPalindrom=false;
                            break;
                        }
                    }
                }
                else
                {
                    int cnt=0;
                    for(int k=0 ; k<26; k++)
                    {
                        if(chars[k]&1 !=0)
                        {
                            cnt++;
                            if(cnt>1)
                            {
                                isPalindrom=false;
                                break;
                            }
                        }
                    }
                }
                if(isPalindrom)
                    palindroms++;
                if(j!= len-1) {
                    chars[str[i] -'a']--;
                    chars[str[j+1] -'a']++;
                }
            }
            dist++;
        }
        printf("%d\n",palindroms);
    }
    return 0;
}

