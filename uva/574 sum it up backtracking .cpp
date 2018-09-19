#include <bits/stdc++.h>
using namespace std;
int sum;
int ara[20];
bool full;
void findSum(int temp[], int tempSum, int i, int n, int len)
{
    //printf("%d %d %d\n",i,tempSum,sum);
    if(tempSum == sum)
    {
        full=true;
        for(int j=0; j<len; j++)
            {
                if(j>0)
                    printf("+");
                printf("%d",temp[j]);

            }
        printf("\n");
        return;
    }
    if(i>=n || tempSum>sum)
        return;

    temp[len]=ara[i];

    findSum(temp, tempSum+ara[i], i+1, n, len+1);
    int k=0;
    while(ara[i+k+1]== ara[i+k])
        k++;
    findSum(temp, tempSum,i+1+k,n,len);

}
int main()
{
    int n;
    int temp[20];
    while(scanf("%d %d",&sum, &n)==2 && n!=0)
    {
        full=false;
        for(int i=0; i<n; i++)
            scanf("%d", &ara[i]);
        sort(ara, ara+n);
        for(int i=0; i<n/2; i++)
            swap(ara[i],ara[n-i-1]);
//        for(int i=0; i<n; i++)
//            printf("%d ", ara[i]);
        printf("Sums of %d:\n",sum);
        findSum(temp, 0,0,n, 0);
        if(!full)
            printf("NONE\n");
    }
    return 0;
}
