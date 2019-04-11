#include <bits/stdc++.h>
using namespace std;

char str[1000011];
int ara[30];
int main()
{
//    freopen("myOutput.txt","w",stdout);

    int tcase;
    scanf("%d",&tcase);
    while(tcase--) {

        scanf("\n%s",str);

        for(int i=0; i<26; i++)
            ara[i]=i;
        int r;
        scanf("%d",&r);

        while(r--) {
            getchar();
            char to,from;
            scanf("%c %c",&to,&from);
//            printf("to %c from %c\n",to,from);
            from-='A';
            to-='A';

            for(int i=0; i<26; i++) {
                if(ara[i] == from)
                    ara[i]=to;
            }

        }
        int len = strlen(str);

        for(int i=0; i<26; i++)
            ara[i]+='A';

        for(int i=0; i< len; i++) {
            if(str[i]>='A' && str[i]<='Z')
                str[i] = ara[str[i]-'A'];
        }
        printf("%s\n",str);
    }

    return 0;
}
