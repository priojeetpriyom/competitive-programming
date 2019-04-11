#include <stdio.h>
#include <cstring>
#include <climits>
int main()
{
    int t,i,k=0,flag,start,endd,character;
    char str[100100];
    scanf("%d",&t);
    while(k<t)
    {
        flag=0,start=0,endd=0,character=0;
        scanf("%s",str);
        int cnt=0;
        int len= strlen(str);
        int i;
        for(i=0;i<len;i++)
        {
            if(str[i]== '^')
            {


                if(flag==0 || character==0)
                {

                    //if(str[i+1]== '_')
                    flag=1;
                    int p=i-1;
                    for(int j=i+1;j<len;j++)
                        {
                            if(str[j]=='_')
                                {
                                    flag=1;
                                    p=j;
                                    break;
                                }
                                else flag=-1;
                        }
                        if(flag!=-1) {
                            start++;
                            while(str[p--]!= '^')
                                character++;
                        }

                }

                if((flag==1 && character!=0) ||  (flag==-1))
                {
                    if(i==10) printf("start %d character %d\n",start,character);//printf("oka %d\n",flag);
                    if(--start>=0 && --character>=0)
                    {
                        cnt++;
                        printf("%d ",i);
                    }
                    else
                    {
                        //start=0;
                        character=0;
                    }

                    if(str[i+1]== '_')
                    {
                        flag=0;
                        endd=0;
                        character=0;
                    }
                }
                else if(flag==-1) break;

            }
            else if(flag==1) character++;
        }
//        if(flag==-1)
//            for(;i<len;i++)
//                if(start-->0 && character-->0)
//                    cnt++;
//                else break;
        k++;
        printf("%d\n",cnt);
    }
    return 0;
}

