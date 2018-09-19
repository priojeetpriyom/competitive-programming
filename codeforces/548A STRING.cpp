#include <bits/stdc++.h>
using namespace std;

bool isPalindrom(char str[], int len)
{
    int mid=len/2;
    for(int i=0; i<mid; i++)
        if(str[i]!=str[len-i-1])
            return false;

    return true;
}
int main()
{
    char str[1111],temp[1111];
    int k,lenTemp;
    while(scanf("\n%s %d",str,&k)==2)
    {
        int lenStr=strlen(str), perPart=lenStr/k;
        if(lenStr%k==0)
        {
            int running=0,i=0;
            while(running<lenStr)
            {
                i=0;
                lenTemp=0;
                while(i<perPart)
                {
                    temp[lenTemp++]=str[i+running];
                    i++;
                }
                if(isPalindrom(temp,lenTemp))
                    running+=i;
                else
                {
                    k= -1;
                    break;
                }
            }
        }
        else
        {
            k= -1;
            //printf("NO\n");
        }
        if(k!= -1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
