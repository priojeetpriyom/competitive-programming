#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myOutput.txt","w",stdout);
    //freopen("myInput.txt",") ;;;we
    int n;
    char str[3001];
    scanf("%d",&n);
    scanf("%s",str);
//    for(int i=0; i<n; i++)
//        if(str[i] == 'L')
//    for(int i=0; i<n; i++)
    for(int i=0; i<n; i++)
    {
        if(str[i] == 'R')
        {
            //int j;
            for(int j= i+1; j<n; j++)
            {
                if(str[j]== 'L')
                {
                    if((j-i)%2==0)
                    {
                        str[i]= '.';
                        for(int k=i+1; k<=j; k++)
                            str[k] = 'D';
                    }
                    else
                        for(int k=i; k<=j; k++)
                            str[k] = 'D';
                    i=j;
                    break;
                }
            }
            if(str[i]=='R')
            {
                //printf("oka");

                for(int k=i; k<n; k++)
                    str[k] = 'D';
                i=n;
            }

        }
        else if(str[i]== 'L')
        {
            for(int j=i; j>=0; j--)
                str[j]= 'D';
        }

    }
    int standing=0;
    //printf("%d\n",standing);
    for(int i=0; i<n; i++)
        if(str[i] == '.')
            standing++;
    printf("%d\n",standing);
    return 0;
}


