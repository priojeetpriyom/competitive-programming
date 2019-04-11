#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    char str[111];
    int len;
    while(scanf("%s", str)==1) {
        len = strlen(str);
        int cur_pos=-1, mx=0;
        for(int i=0; i<len; i++) {
            if( str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'Y') {
                mx = max(mx, (i-cur_pos));
                cur_pos = i;
            }
            else if(i==len-1)
            {
                mx = max(mx, (i+1-cur_pos));
                cur_pos = i+1;
            }
        }
        printf("%d\n", mx);
    }

    return 0;
}
