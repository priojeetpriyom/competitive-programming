#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>
//#define INT_MAX;

using namespace std;
int countries[22] [22],cost[22];
int start,endd,row=1,col=1,conquers;
struct node {
    int y,dist;
};
//int current_x;

int find_minimum_conquer()
{
    struct node current_node;
    queue <node> Q;
    current_node.y=start;
    current_node.dist=0;
    Q.push(current_node);
    while (1)
    {
        current_node=Q.front();
        for(int j=1;j<21;j++)
        {
//            if(countries [current_node.y] [j]== endd)
//            {
//
//            }
            if(countries[current_node.y] [j] == 1)
            {

                struct node new_node;
                new_node.y=j;
                new_node.dist=current_node.dist+1;
                //printf("going from %d to %d cost %d\n",current_node.y,j,new_node.dist);
                //if(current_node.y==19) printf("dist at 19 %d\n",current_node.dist);
                if(j==endd) return current_node.dist+1;
                Q.push(new_node);
            }
        }
        //if(current_node.y== -1) break;
        Q.pop();
    }
}

int main() {
    int tcase=0,n;
    char temp[40];
    while(gets(temp))
    {
        tcase++;
        int len=strlen(temp);
        row=1,col=1;

        for(int i=0;i<len;i++)
        {

            if(temp[i]==' ' || i==0)
            {
                int j=0;
                if(i!=0) j=i+1;
                int x=0;

                while(temp[j]!= ' ' && j<len)
                {
                    x= x*10 + (temp[j]-'0');

                    j++;

                }
                //printf("x %d\n",x);
                if(x>row)
                {
                    countries[row] [x] = 1;
                    countries[x] [row] = 1;
                }
            }
        }

        row++;
        for(int a=2;a<20;a++)
        {

            gets(temp);
            len=strlen(temp);
        for(int i=0;i<len;i++)
        {

            if(temp[i]==' ' || i==0)
            {
                int j=0;
                if(i!=0) j=i+1;
                int x=0;
                while(temp[j]!= ' ' && j!=len)
                {
                    x= x*10 + (temp[j]-'0');
                    //printf("x %d temp %c len %d\n",x,temp[j],len);
                    j++;
                }
                if(x>row)
                {
                    countries[row] [x] = 1;
                    countries[x] [row] = 1;
                }
            }
        }
        row++;
        }


//        for(int i=1;i<20;i++)
//        {
//            printf("%d-> ",i);
//            for(int j=1;j<21;j++)
//                if(countries[i] [j]==1)
//                    printf("%d ",j);
//                printf("\n");
//        }
        //printf("first part ok\n");

        for(int i=0;i<21;i++)
            {
            for(int j=0;j<21;j++)
                if(countries[i] [j] != 1)
                countries[i] [j] =-1;
            cost[i] =INT_MAX;
            }

    int n;
    scanf("%d",&n);

    printf("Test Set #%d\n",tcase);
    while(n--)
    {
        scanf("%d %d",&start,&endd);
        //printf("ok\n");
        conquers=find_minimum_conquer();

        if(start<10) printf(" ");
        printf("%d to ",start);

        if(endd<10) printf(" ");
        printf("%d: ",endd);

//        if(conquers<10)
//            printf(" ");
        printf("%d\n",conquers);
    }
    //printf("shesh\n");
    getchar();
    }
    return 0;
}

