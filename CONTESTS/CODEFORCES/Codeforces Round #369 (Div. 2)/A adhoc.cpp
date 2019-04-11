#include <bits/stdc++.h>
using namespace std;

char str [1010] [10];
int main()
{
//    freopen("myOutput.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("\n%s",str[i]);
    bool oka=false;

    for(int i=0; i<n; i++) {
        for(int j=0; j<4; j++) {
            if(str[i] [j] == 'O' && str[i] [j+1] == 'O') {
               str[i] [j] = '+';
               str[i] [j+1] = '+';
               oka=true;
               break;

            }

        }
        if(oka)
            break;
    }
    if(oka) {
        printf("YES\n");
        for(int i=0; i<n; i++)
            printf("%s\n",str[i]);
    } else
        printf("NO\n");


    return 0;
}
