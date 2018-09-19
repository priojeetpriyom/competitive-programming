#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main ()
{
    int i,j,l,r,t,len,m,n,ct,k;
    long long left[10000],right[10000];
    scanf("%d",&t);
    char p[10],pos;
    while(t--)
    {
        l=0,r=0,ct=0;
        i=0,j=0;
        scanf("%d %d",&len,&m);
        //getchar();
        len*=100;
        //printf("len %d\n",len);
        while(m--)
        {
            scanf("%d",&n);
            getchar();
            scanf("%s",p);
            pos=p[0];
            if(pos== 'l') left[i++] = n;
            else right[j++] = n;
        }
        k=0;
        while(k<i)
        {
            if(left[k] <= len) left[l++] = left[k];
            k++;
        }
        r=0,k=0;
        while(k<j)
        {
            if(right[k]<=len) right[r++] = right[k];
            k++;
        }
        ct=0;
        pos= 'l';

        i=l-1,j=r-1;
        int sum=0;

        while(i>=0 || j>=0)
        {
            sum=0;
            if(pos == 'l')
            {

                while (i>=0)
                {
                    if(sum + left[i]< len)
                    {
                        sum+=left[i--];
                    }
                    else if(sum + left[i]== len)
                    {
                        i--;
                        break;
                    }
                    else break;

                }

                ct++;
                pos='r';

            }
            else if(pos == 'r')
            {

                while (j>=0)
                {

                    if(sum + right[j]< len)
                    {
                        sum+=right[j--];

                    }
                    else if(sum + right[j]== len)
                    {

                        j--;
                        break;
                    }
                    else break;
                }
                ct++;
                pos='l';

            }
        }
            printf("%d\n",ct);
    }
        return 0;
    }
