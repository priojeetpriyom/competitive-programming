#include <bits/stdc++.h>

using namespace std;
int numRev(int n)
{
    int temp=0;
    while(n>0)
    {
        temp=temp*10+n%10;
        n/=10;
    }
    return temp;
}
char num1[10000],num2[10000],str[10000];
int main()
{
    char zero,one ,two,three,four;
    int tCase;
    scanf("%d",&tCase);

    while(tCase--)
    {
     getchar();
    char c[10];
    int temp=0;
    for(int i=0;i<5;)
    {
        c[0]=' ';
        scanf("\n%c",&c);
        if(c[0]!=' ' && c[0]!=NULL)
        {
            i++;
            if(temp==0)
                zero=c[0];
            else if(temp==1)
                one =c[0];

            else if(temp==2)
                two=c[0];

            else if(temp==3)
                three=c[0];

            else if(temp==4)
                four=c[0];
            temp++;
            //i++
        }
    }
    //cout<<zero<<" "<<one<<" "<<two<<" "<<three<<" "<<four<<" "<<endl;

        scanf("\n%s",&num1);
        scanf("\n%s",&num2);
        int n1=0,n2=0,power=1;
        int len1=strlen(num1),len2= strlen(num2);
        //cout<<num1<<"len "<<len1<<endl;
        for(int i=len1-1;i>=0;i--)
        {
            if(num1[i]== zero)
                temp=0;
            else if(num1[i]== one)
                temp=1;
            else if(num1[i]== two)
                temp=2;
            else if(num1[i]== three)
                temp=3;
            else if(num1[i]== four)
                temp=4;
            //printf("temp %d\n",temp);
            n1= n1 + temp*power;
            power=5*power;
        }
        //cout<<"n1 "<<n1<<endl;
        //n1=numRev(n1);
        power=1;
        for(int i=len2-1;i>=0;i--)
        {
            if(num2[i]== zero)
                temp=0;
            else if(num2[i]== one)
                temp=1;
            else if(num2[i]== two)
                temp=2;
            else if(num2[i]== three)
                temp=3;
            else if(num2[i]== four)
                temp=4;

            n2= n2 + temp*power;

            power=5*power;
        }
        //n2 = numRev(n2);
        int sum = n1+n2;
        //cout<<sum<<endl;
        //sum=numRev(sum);
        //cout<<sum<<endl;

        int len=0;
        while(sum>0)
        {
            if(sum%5==0)
                str[len++]=zero;
            else if(sum%5==1)
                str[len++]=one;
            else if(sum%5==2)
                str[len++]=two;
            else if(sum%5==3)
                str[len++]=three;
            else if(sum%5==4)
                str[len++]=four;
            sum/=5;
        }
        str[len]='\0';
        for(int i=len-1;i>=0;i--)
            printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}
