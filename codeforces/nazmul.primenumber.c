#include<stdio.h>
int is_prime(int n)
{
    int i;
    for(i=2;i<n;i++){
        if(n%i==0)
            return 1;


    }
        return 2;
}
int main ()
{
    int prime,m;
    printf("Enter the number that you want check wheather it's prime or not:");
    scanf("%d",&m);
    prime=is_prime(m);
    if (prime==1)
        printf("the number is not prime");
    else if(prime==2)
        printf("the number is prime");
    return 0;
}
