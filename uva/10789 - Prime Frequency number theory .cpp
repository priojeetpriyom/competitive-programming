
#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n)
{
    if(n<2)
        return false;
    else if(n<4)
        return true;
    else if(n&1==0)
        return false;
    int root= sqrt(n)+2;
    for(int i=3; i<root; i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
bool prime_gen[2020];
int primes[6000000],len_mx;
int main()
{

    //int len_prime=1,cnt_power,mx;

    for(int i=4; i<2020; i+=2)
    {
        //primes[i]=INT_MAX;
        prime_gen[i]=false;
        // powers[i]=0;
    }
    for(int i=3; i<2020; i+=2)
    {
        //primes[i]=INT_MAX;
        prime_gen[i]=true;
        // powers[i]=0;
    }
    prime_gen[0]=false;
    prime_gen[1]=false;
    prime_gen[2]=true;
//    primes[len_prime++]=1;
//    primes[len_prime++]=2;
    for(int i=3; i<2020; i+=2)
    {
        if(prime_gen[i]== true && is_prime(i)==true)
        {
            //primes[len_prime++]=i;
            int x=i+i;
            while(x<2020)
            {
                prime_gen[x]=false;
                x+=i;
            }
        }

    }
    //printf("oka\n");
    int tCase;
    scanf("%d\n",&tCase);
    int j=1;
    while(tCase--)
    {
        char str[2020];
        int alphaNums[70];
        for(int i=0;i<70;i++)
            alphaNums[i]=0;
        scanf("%s",str);
        printf("Case %d: ",j++);
        int len_str=strlen(str);
        for(int i=0;i<len_str;i++)
        {
            if(str[i]>47 && str[i]<58)
                alphaNums[str[i]-48]++;
            else if(str[i]>64 && str[i]<91)
                alphaNums[str[i]-55]++;
            else if(str[i]>96 && str[i]<123)
                alphaNums[str[i]-61]++;
        }
//        if(is_prime(4))
//            printf("baler code koro tumi\n");
        bool printed=false;
        for(int i=0;i<62;i++)
            if(prime_gen[alphaNums[i]]==true)
            {
                if(i<10)
                    printf("%c",i+48);
                else if(i<36)
                    printf("%c",i+55);
                else
                    printf("%c",i+61);
                printed=true;
            }
        if(!printed)
            printf("empty");
        printf("\n");
    }

    return 0;
}

