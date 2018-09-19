#include <iostream>
#include <cstdio>
#define INT_MAX 1000000000
using namespace std;
int ara[25], n, timee, temp[25], len,mn,finalLength,finalAra[25],finalSum;
void findBestCollection(int i, int len, int sum)
{
    if(i == n && timee-sum <mn)
    {
        //printf("%d %d\n",sum,len);
        mn = timee-sum;
        finalLength=len;
        finalSum= sum;
        for(int j=0; j<len;j++)
            finalAra[j]= temp[j];
//        for(int j=0; j<len;j++)
//            printf("%d ",temp[j]);
//        printf("\n");
        return;
    }
    if(i==n)
        return;
    if(sum+ara[i]<=timee)
    {
        temp[len] =ara[i];
        findBestCollection(i+1,len+1,sum+ara[i]);
    }
    findBestCollection(i+1, len,sum);
}
int main()
{
    while(scanf("%d %d",&timee, &n)==2)
    {
        mn=INT_MAX;
        for(int i=0; i<n; i++)
            scanf("%d",&ara[i]);
        findBestCollection(0,0,0);
        for(int i=0; i<finalLength; i++)
        {
//            if(i>0)
//                printf(" ");
            printf("%d ",finalAra[i]);
        }
        printf("sum:%d\n",finalSum);
        //printf("\n");
    }
    return 0;
}

