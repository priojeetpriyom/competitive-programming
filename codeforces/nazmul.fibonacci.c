#include<stdio.h>
int fibo(int n)
{
    int i=1,sum=1,f1=0,f2=1;
    do{
        sum=f1+f2;
        f1=f2;
        f2=sum;
        }
    while (++i<n);
        return sum;
}
int main()
{
    int fibonacci,m;
    printf("enter the the nth fibonacci number :");
    scanf("%d",&m);
    fibonacci=fibo(m);
    printf("%dth fibonacci number is %d",m,fibonacci);

    return 0;
}
