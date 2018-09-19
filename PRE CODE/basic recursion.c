#include <stdio.h>
void recursion (int i)
{
    if (i==0) return;

    //i--;
    recursion(i-1);
    printf("%d\n",i);
}


int main()
{
    int n;
    scanf("%d",&n);
    recursion(n);
    return 0;
}
