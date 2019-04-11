#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r,l,n;
    char str[1001];
    while(scanf("%d", &n)==1) {
        scanf("\n%s", str);
        r=0,l=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]== 'R')
                r++;
            else if(str[i]== 'L')
                l++;
        }
        //int diff = r-l;
        //if(diff>=0)
            printf("1 %d\n",r);
        //else
            //printf("%d 1\n",abs(diff)+1);
    }
    return 0;
}
