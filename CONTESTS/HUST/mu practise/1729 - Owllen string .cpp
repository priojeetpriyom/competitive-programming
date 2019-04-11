#include <bits/stdc++.h>
using namespace std;

char str[100005];
int main()
{
//    freopen("myOutput.txt","w",stdout);
    int t,tcase;
    scanf("%d",&tcase);
    for(t =1; t<=tcase; t++) {
        scanf("\n%s",str);

            printf("Case %d: ",t);

        int len=strlen(str), cnt=INT_MAX;
        int chars[30] = {0};
        for(int i =0; i<len; i++) {

            chars[str[i]- 'a' ]++;

        }
        for(int i=0; i<26; i++)
            cnt = min(cnt,chars[i]);
            printf("%d\n",cnt);
    }

    return 0;
}

