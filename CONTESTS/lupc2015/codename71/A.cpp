//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>
//#incldu
using namespace std;

int main()
{
    int t,l,a,b;

    char str [101] [300];
    scanf("%d",&t);
    getchar();
    int i=1,row,col,endd,flag,x,y;
    t++;
    while(i<t)
    {
        stack <int> Q;
        scanf("%d",&l);
        getchar();
        row=0,col=0,flag=0;
        int j=0,len;
        getchar();
        //if(i!=t-1)getchar();
        while(l--)
        {
            gets(str[row]);
            //printf("%d %d\n",j,l);
            row++;
            j++;
            //printf("ok\n");
        }
        printf("STORY %d\n",i++);
        int c=0;
        //printf("shes\n");
//        j=0;
//        while(j<row)
//			printf("1 %s\n",str[j++]);

        for(j=1; j<row; j++)
            {
            	if(str[j] [0]== 'C')
            	c++;
            }
            //printf("baal c %d\n",c);
        j=0;
        len= strlen(str[j]);
        int k;
        flag=0;
        for(k=0; k<len; k++)
        {
            if(str[j] [k]== 34) flag++;
            if(flag==1 && str[j] [k]!= '"')
            {
                printf("%c",str[j] [k]);
            }
            else if(flag==2)
            {
                printf("\n");
                break;
            }
            //printf("baal %c",str[j] [k]);

        }
        //printf("\nxxxxxxx  %c\n",str[j] [k+1]);
        a=0,b=0;
        for(; k<len; k++)
        {
            if(str[j] [k]>= '0' && str[j] [k]<= '9')
            {
                y=0;
                int m=k;

                while(str[j] [m] != ' ' && m<len)
                {
                    y=y*10+ str[j] [m] -48;
                    m++;
                }
                k=m;
                if(a==0) a=y;
                else b=y;
                //printf("x %d\n",y);

            }


        }
        Q.push(b-1);
        Q.push(a-1);
        //printf("ball\n");
        int x;
        while(!Q.empty())
        {
            //printf("oka x %d\n%s\n",Q.front()+1,str[Q.front()]);
            x=Q.top();
            Q.pop();
            //printf("c %d\n",c);
            if(str[x] [0] == 'C' )
            {
                //printf("ok\n");
                c--;
                len=strlen(str[x]);
                flag=0;
                for(k=0; k<len; k++)
                {
                    if(str[x] [k]== '"') flag++;
                    if(flag==1 && str[x] [k]!= '"')
                    {
                        printf("%c",str[x] [k]);
                    }
                    else if(flag==2)
                    {
                        printf("\n");
                        break;
                    }
                }
                a=0,b=0;
                for(; k<len; k++)
                {
                    if(str[x] [k]>= '0' && str[x] [k]<= '9')
                    {
                        y=0;
                        int m=k;
                        while(str[x] [m] != ' ' && m<len)
                        {
                            y=y*10+ str[x] [m] -48;
                            m++;
                        }
                        k=m;
                        if(a==0) a=y;
                        else b=y;
                        //printf("y %d\n",y);

                    }


                }
                //printf("b %d a %d\n",b,a);
                Q.push(b-1);
                Q.push(a-1);
            }
            else if(c==0)
            {
                len=strlen(str[x]);
                flag=0;
                //if(a==4)
                //printf("aise x %d %c\n",x,str[x] [len-3]);
                if(str[x] [len-3] == 'P')
                {
                    for(k=0; k<len; k++)
                    {
                        if(str[x] [k]== '"') flag++;
                        if(flag==1 && str[x] [k]!= '"')
                        {
                            printf("%c",str[x] [k]);
                        }
                        else if(flag==2)
                        {
                            printf("\n");
                            break;
                        }
                    }
                    break;
                }
                //
            }

            //Q.pop();

        }
    }
    return 0;
}
