#include <bits/stdc++.h>
using namespace std;
char str[500];
int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int len;
    scanf("%d \n%s",&len,str);
    int mx =0,cnt,words=0;
    for(int i=0; i<len; i++) {
        cnt=0;
        if(str[i] == '(') {
            for( i+1; str[i]!= ')'; i++) {
                if(tolower(str[i])>='a' && tolower(str[i]) <='z') {
//                    printf("%c ",str[i]);
                    while(tolower(str[i+1])>='a' && tolower(str[i+1]) <='z')
                        i++;
                  words++;
//                    printf("%d\n",i);
                }

            }
//            printf("last i %d\n",i);

           }
        else if(tolower(str[i])>='a' && tolower(str[i]) <='z') {
            cnt=1;
            while(tolower(str[i+1])>='a' && tolower(str[i+1]) <='z')
            {
                i++;
                cnt++;
            }
            mx = max(mx,cnt);
        }

    }

    printf("%d %d",mx, words);

    return 0;
}

