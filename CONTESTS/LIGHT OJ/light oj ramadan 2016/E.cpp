#include <bits/stdc++.h>

using namespace std;
char bin[100];

long long xtod(string str, long long base)
{
    long long n=1,num=0;
    for(int i =str.length()-1; i>=0; i--)
    {
        int x;
        if(str[i]=='A')
            x=10;
        else if(str[i]=='B')
            x=11;
        else if(str[i]=='C')
            x=12;
        else if(str[i]=='D')
            x=13;
        else if(str[i]=='E')
            x=14;
        else if(str[i]=='F')
            x=15;
        else
            x = str[i]-'0';

        num+=(n*x);
        n*=base;
    }
    return num;
}

void stringRev(char str[],int len) {
    int half = len/2;
    //printf("%s len %d\n",bin,len);
    for(int i=0; i<half; i++)
        swap(bin[i],bin[--len]);
}

void dtox(long long n, long long base) {
    int i=0;
    while(n>0)
    {
        int x =(n%base);
        if(x>9)
            bin[i++] = (x-10)+'A';
        else
            bin[i++] = x +'0';
        n/=base;
    }
    if(i==0)
        bin[i++] ='0';
    bin[i]='\0';
    stringRev(bin,strlen(bin));
}

int main ()
{
    long long s,e;
    string str;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>str>>s>>e;

        s=xtod(str,s);


//        printf("%lld\n",s);


        dtox(s,e);



        printf("%s\n",bin);

        }

    return 0;
}


