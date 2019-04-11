#include <bits/stdc++.h>
using namespace std;

long long to_decimal(char str[], int len) {
    long long pw=1,num=0;
    for(int i= len-1;i>=0; i--) {
        num+= pw * (str[i]-'0');
        pw*=2;
    }
    return num;
}

char* to_binary(long long n) {
    char* str,len=0;
    str =(char*) malloc(sizeof(char)*100);
    do{
        str[len++] = n%2 + '0';
        n/=2;
    }while(n>0);
    str[len] = '\0';

    for(int i=0; i<len/2; i++)
        swap(str[i],str[len-i-1]);

    return str;
}

int main()
{
//    freopen("myOutput.txt","w",stdout);
    int tcase;
    scanf("%d",&tcase);
    for(int t =1; t<=tcase; t++) {
        long long a,b;
        char* a_str,*b_str,or_str[100],and_str[100];

        scanf("%lld %lld",&a,&b);

        a_str = to_binary(a);
        b_str = to_binary(b);
//        printf("baal %sx %sy\n",a_str,b_str);
       int len_a= strlen(a_str);
        int len_b = strlen(b_str);

        if(len_b>len_a) {
            int x = len_b-len_a;
            for(int i= len_a-1; i>=0; i--) {
                a_str[i+x] = a_str[i];

            }
            while(--x>=0) {
                a_str[x] = '0';
            }
        }
//        printf("baal %sx %sy\n",a_str,b_str);
        for(int i=0; i<len_b; i++) {
            if(b_str[i]!=a_str[i]) {
                for( ; i<len_b; i++)
                    or_str[i]='1';
            }else
                or_str[i]=b_str[i];
        }
        or_str[len_b] = '\0';

        for(int i=0; i<len_b; i++) {
            if(b_str[i]!=a_str[i]) {
                for( ; i<len_b; i++)
                    and_str[i]='0';
            }else
                and_str[i]=b_str[i];
        }
        and_str[len_b] = '\0';
        a = to_decimal(or_str,len_b);
        b = to_decimal(and_str,len_b);
        printf("Case %d: %lld %lld\n",t,a,b);
    }

    return 0;
}
