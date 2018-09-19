#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    char str[111];
    while(scanf("%s",str)==1)
    {
        int len =strlen(str),j=0,len1;
        len1=len;
        if(str[0]== '-')
        {
            len--;
            j=1;
        }
        //printf("len %d\n",len);
        if(len<19)
        {
            n=0;
            for(; j<len1;j++)
            {
                n=n*10+str[j]-48;
            }
                if(str[0]== '-')
                    n=abs(n)-1;
            //cout<<"n "<<n<<endl;

            if(n<= 127)
                printf("byte\n");
            else if( n<= 32767)
            {
                printf("short\n");
            }
            else if(n<= 2147483647)
            {
                printf("int\n");
            }
            else if(n<= 9223372036854775807)
            {
                printf("long\n");
            }
        }
        else if(len>20)
            printf("BigInteger\n");
        else
        {
            char strLong[30] = {"9223372036854775807"};
            //char strnegativeLong[30] = {"-9223372036854775808"};
            j=0;
            int lenStrLong= strlen(strLong);
            if(str[0] == '-')
            {
                j=1;
                strLong[lenStrLong-1]='8';
            }
            bool bigInt= false;
            int k=0;
            for(; j<20; j++)
            {
                if(str[j]>strLong[k])
                {
                    bigInt=true;
                    break;
                }
                else if(str[j]<strLong[k])
                    break;
                k++;
            }
            if(bigInt)
                printf("BigInteger\n");
            else
                printf("long\n");
        }
    }
    return 0;
}
