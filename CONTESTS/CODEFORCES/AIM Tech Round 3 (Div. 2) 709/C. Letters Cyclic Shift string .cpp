#include <bits/stdc++.h>
using namespace std;

char str[101000];

int main()
{
//    freopen("myOutput.txt","w",stdout);
    scanf("\n%s",str);

    int len = strlen(str);
    bool changed=false;
    for(int i=0; i<len; i++) {
        if(changed)
        {
            if(str[i] == 'a') {
                break;
            } else {
                str[i]-=1;
            }
        }
        else if(str[i]!= 'a') {
            changed=true;
            str[i]-=1;
        }
        else if(i==len-1)
            str[i] = 'z';

    }
    printf("%s\n",str);
    return 0;
}
