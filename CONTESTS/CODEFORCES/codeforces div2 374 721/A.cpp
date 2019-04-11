#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int n;
    char str[101];
    int ara[100],len_ara=0,ttl=0;
    scanf("%d \n%s",&n,str);
    bool p=true;
    for(int i=0; i<n; i++) {
        if(str[i]=='B') {
//            p = false;
            int cnt=0;
            while(str[i]=='B' && i<n) {
                cnt++;
                i++;
            }
            ara[len_ara++] = cnt;

        }
    }
    if(len_ara==0)
    printf("0\n");
    else
    {
        printf("%d\n",len_ara);
        for(int i=0; i<len_ara; i++)
            printf("%d ",ara[i]);
        printf("\n");
    }

    return 0;
}
