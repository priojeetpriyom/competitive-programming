#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int n;
    scanf("%d",&n);
    int pattern[101];

    for(int i=0; i<n; i++)
        scanf("%d",&pattern[i]);

    char str[111];

    gets(str);
    bool yes = true;
    for(int j=0; j<n; j++) {
        gets(str);

    int len = strlen(str);
    int cnt=0;

    for(int i=0; i<len; i++)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y') {
                cnt++;

        }
    }
    if(cnt!= pattern[j])
        yes = false;
    }

    if(yes)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
