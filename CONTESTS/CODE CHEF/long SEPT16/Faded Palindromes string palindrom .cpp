#include <bits/stdc++.h>
using namespace std;

char str[12346];
int main()
{
//    freopen("myOutput.txt","w",stdout);

    int tcase;
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("\n%s",str);
        int len = strlen(str),len_half=len/2 + (len&1!=0);
        bool print=true;
        for(int i=0; i<len_half; i++) {
            if(str[i]== str[len-i-1]) {
                if(str[i] == '.') {
                    str[i] = str[len-i-1] = 'a';
                }
            } else if(str[i] == '.')
                str[i] = str[len-i-1];
                else if(str[len-i-1]=='.')
                    str[len-i-1] = str[i];
                else
                {
                    printf("-1\n");
                    print=false;
                    break;
                }
        }
        if(print)
            printf("%s\n",str);
    }
    return 0;
}


