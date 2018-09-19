#include <bits/stdc++.h>
using namespace std;

char str[100005];
int main()
{
//    freopen("myOutput.txt","w",stdout);

    while(gets(str)) {
        int len =strlen(str);
        int cnt=0;
        for(int i=0; i<len; i++) {
            if((str[i]>='A' && str[i]<='Z')||(str[i]>='a' && str[i]<='z')) {
                cnt++;
                while((str[i]>='A' && str[i]<='Z')||(str[i]>='a' && str[i]<='z'))
                    i++;
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}

