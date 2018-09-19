#include<stdio.h>
int factor(int n)
{
    int i,sum=1;
    for(i=1;i<=n;i++){
        sum*=i;
    }
    return sum;
}
int main ()
{
    int factorial,m;
    printf("Enter the number that you want calcutale it's factorial:");
    scanf("%d",&m);
    factorial=factor(m);
    printf("the factorial of %d is : %d",m,factorial);
    return 0;
}
