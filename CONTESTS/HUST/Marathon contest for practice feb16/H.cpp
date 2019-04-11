#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[111];
    int i;
    while(gets(str))
    {
        for(i=strlen(str)-2; i>=0; i--)
        {
            if(str[i]!=' ' && str[i]!= '?')
                break;
        }
        if(toupper(str[i]) == 'A' || toupper(str[i]) == 'E' || toupper(str[i]) == 'I' || toupper(str[i]) == 'O' || toupper(str[i]) == 'U' || toupper(str[i]) == 'Y')
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
