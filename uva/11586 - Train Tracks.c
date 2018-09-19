#include <stdio.h>
#include <string.h>

using namespace std;
int main()
{
    int t,i,l,m,f;
    char str[10010];
    scanf("%d",&t);
    gets(str);
    while (t--) {
        gets(str);
        l=strlen(str);
        m=f=0;
        for(i=0; i<l; i++) {
           if(str[i] == 'M') m++;
           else if (str[i] == 'F') f++;
        }
        if (f>1 && m>1 && m==f) printf("LOOP\n");
        else printf("NO LOOP\n");
    }
    return 0;
}
