#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str [11] [21], temp[21];
    int n, giver, ara[11];
    bool newLine=false;
    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++)
            ara[i]=0;
        for(int i=0; i<n; i++)
        {
            scanf("\n%s",str[i]);
        }
        for(int k=0; k<n; k++)
        {
            scanf("\n%s", temp);
            for(int i=0; i<n; i++)
            {
                if(strcmp(str[i], temp)==0)
                {
                    giver=i;
                    break;
                }
            }
            int numOfTakers, given;
            scanf("%d %d",&given, &numOfTakers);
            if(numOfTakers!=0)
            {
                ara[giver] -= given-(given%numOfTakers);
                for(int i=0; i< numOfTakers; i++)
                {
                    scanf("\n%s",temp);
                    for(int j=0; j<n; j++)
                    {
                        if(strcmp(str[j],temp)==0)
                        {
                            ara[j]+= (given/numOfTakers);
                            break;
                        }
                    }
                }
            }
//            else
//                ara[giver] += 0;
        }
        if(!newLine)
            newLine=true;
        else
            printf("\n");

        for(int i=0; i<n; i++)
        {
            printf("%s %d\n",str[i], ara[i]);
        }
    }
    return 0;
}

