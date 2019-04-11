#include <bits/stdc++.h>

using namespace std;
//int ara[100001];
//long long a,b,c,d,e,f;

int main()
{
    //a=0,b=1,c=2,d=3,e=4,f=5;
    int n, m, ara[200011];
    char c;
    while(scanf("%d %d",&n, &m)==2)
    {
        n++;
        int l,r=1,x,len=1,lenDiff=1;
        ara[0] = -1;
        int diff[200011];
        diff[0]=0;
        for(int i=1; i<n; i++)
            {
                scanf("%d",&ara[len]);
                diff[i]= diff[i-1];
                if(ara[len]!= ara[len-1])
                    len++;
                else {
                    diff[i]++;
//                    diff[i-1]++;
                }
            }
//            for(int i=1;i<=len; i++)
//                printf("%d ",ara[i]);
//            printf("\n");
            for(int i=1;i<=len; i++)
                printf("%d ",diff[i]);
            printf("\n");
        len--;
        while(m--) {
            scanf("%d %d %d",&l, &r, &x);
            //r++;
//            if(l>len)
//              r=-1;
//            if(r>len)
//                r=len;
            int x=r;
            l= l- diff[l];
            r= r- diff[r];
            if(r<l) r=l;

            for(int p = l;p<=r; p++)
            {
                if(ara[p]!=x)
                {
                    printf("%d\n",p+diff[x]);
                    x= -1;
                    break;
                }
            }
            if(x!= -1)
                printf("-1\n");
        }

    }
    return 0;
}
