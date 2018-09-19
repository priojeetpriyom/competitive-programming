#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("myOutput.txt","w",stdout);
    //freopen("myInput.txt",")
    int n, a[1001],b[1001];
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n; i++)
            {
                scanf("%d",&a[i]);
                scanf("%d",&b[i]);
            }
//        for(int i=0;i<n; i++)
//
        for(int i=0; i<n; i++)
            for(int j = i+1; j<n; j++)
                if(a[i]> a[j])
                {
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                }
        for(int i=0; i<n; i++)
            for(int j = i+1; j<n; j++)
                if(b[i]> b[j])
                {
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                }
//        for(int i=0; i<n; i++)
//            printf("%d ",a[i]);
//            printf("\n");
//        for(int i=0; i<n; i++)
//            printf("%d ",b[i]);
//            printf("\n");


        int cnt =1,sum=0;
        for(int i= n-1; i>=0 && cnt>0; i--)
        {
            sum+=a[i];
            cnt+= b[i]-1;
        }
        printf("%d\n",sum);
    }
    return 0;
}


