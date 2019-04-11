#include <bits/stdc++.h>
#define N 5
#define ll long long
int ara[N];
using namespace std;

int main()
{
    int tCase;
    char str[81];
    scanf("%d",&tCase);
    while(tCase--)
    {
        scanf("\n%s",str);
        int len= strlen(str);
        int sum=0;
        for(int i=0;i<len;i++)
        {
            int j=1;
            while(str[i]== 'O')
            {
                sum+=(j++);
                i++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
