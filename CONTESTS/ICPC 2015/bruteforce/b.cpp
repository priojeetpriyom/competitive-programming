#include <stdio.h>
#include <cstring>
int main()
{
    int t,i,n;
    char str[1010] [15],mom[15];
    scanf("%d\n",&t);
    i=1;
    t++;
    //getchar();
    while(i<t)
    {
        scanf("%d\n",&n);
        //getchar();
        int j=0;
        while(j<n)
        {
            scanf("%s",str[j++]);
        }
        //printf("ok\n");
        scanf("%s",mom);
        printf("Case %d:\n",i);
        int len = strlen(mom);
        for(int m=0;m<n;m++)
            {
                int k=0;
                for(int p=0;p<len;p++)
                    {
                        if(mom[p]!= str[m] [p])
                            {
                                k++;
                        if(k>1)
                            {
                                k=-1;
                                break;
                            }
                            }
                    }
                    if(k!=-1)
                        printf("%s\n",str[m]);
            }
        i++;
    }
    return 0;
}
