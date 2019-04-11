#include <bits/stdc++.h>
using namespace std;
int a[100001],b[100001];
int main()
{
//    freopen("myOutput.txt","w",stdout);
//    //freopen("myInput.txt",") ;;;
    int magic,n,cnt=0;
    scanf("%d %d",&n, &magic);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<n; i++)
        scanf("%d",&b[i]);
    while(magic>0)
    {
        for(int i=0; i<n; i++)
        {
            if(a[i]-b[i]> magic)
            {
                magic= -1;
                break;
            }
            if(a[i]>b[i])
            {
                magic = magic - (a[i] - b[i]);
                b[i]= a[i];
            }
        }
        if(magic != -1)
        {
            for(int i=0; i<n; i++)
                b[i]-= a[i];
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;

}

