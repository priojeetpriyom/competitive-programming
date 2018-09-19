#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[300011];
    scanf("%s",str);
    long long cnt=0;
    for(int i= strlen(str)-1; i>=0;i--) {
        if((str[i]-'0') %4 ==0)
            cnt++;
        if(i!=0)
        {
            int num = (str[i-1]-'0')*10 + (str[i] - '0');
            if(num %4==0)
                cnt+=i;
        }
    }
    printf("%I64d\n",cnt);
    return 0;
}
