#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myOut.txt", "w", stdout);
    int len, dist;
    char str[111];
    scanf("%d %d \n%s", &len, &dist, str);
    bool ok = true;
    for(int i=0; i< len; i++) {
        if(str[i] == 'G') {
            for(int j=i+dist; j<len; j+=dist) {
                if(str[j] == '#')
                    break;
                if(str[j] == 'T')
                {
                    printf("YES\n");
                    return 0;
                }
            }
            for(int j=i-dist; j>=0; j-=dist) {
                if(str[j] == '#')
                    break;
                if(str[j] == 'T')
                {
                    printf("YES\n");
                    return 0;
                }
            }
        break;
        }
    }
    printf("NO\n");
    return 0;
}
