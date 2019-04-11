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

struct node {
    int x,y,z;
    //int dist= INT_MAX;
};

struct node current_node,end_node;
char str [30] [30] [31];
int cost [30] [30] [30];

void find_minimum_time(int floor,int row,int col)
{
    int x[] = {0,1,0,-1,0,0};
    int y[] = {-1,0,1,0,0,0};
    int z[] = {0,0,0,0,1,-1};
    queue <struct node> Q;
    Q.push(current_node);
    cost[current_node.z] [current_node.y] [current_node.x] =0;
    while(!Q.empty())
    {
        current_node=Q.front();
        int i;
        for(i=0;i<6;i++)
        {
            if((str [current_node.z+z[i]] [current_node.y+y[i]] [current_node.x+x[i]] == '.' || str [current_node.z+z[i]] [current_node.y+y[i]] [current_node.x+x[i]] == 'E')&& cost[current_node.z] [current_node.y] [current_node.x]+1< cost[current_node.z+z[i]] [current_node.y+y[i]] [current_node.x+x[i]] && current_node.z+z[i]>=0 && current_node.z+z[i]<floor && current_node.y+y[i]>=0 && current_node.y+y[i]<row && current_node.x+x[i]>=0 && current_node.x+x[i]<col)
            {
                //printf("current_node %d %d %d\n",current_node.z+z[i],current_node.y+y[i],current_node.x+x[i]);

                struct node new_node;
                new_node.x=current_node.x+x[i];
                new_node.y=current_node.y+y[i];
                new_node.z=current_node.z+z[i];
                cost[current_node.z+z[i]] [current_node.y+y[i]] [current_node.x+x[i]] = cost[current_node.z][current_node.y] [current_node.x]+1;
                Q.push(new_node);

            }
            //else if(str [current_node.z+z[i]] [current_node.y+y[i]] [current_node.x+x[i]]== 'E') break;
        }
//        if(str [current_node.z+z[i]] [current_node.y+y[i]] [current_node.x+x[i]] == 'E')
//        {
//            cost[current_node.z+z[i]] [current_node.y+y[i]] [current_node.x+x[i]] = cost[current_node.z][current_node.y] [current_node.x]+1;
//        }
        Q.pop();
    }
    if(cost[end_node.z] [end_node.y] [end_node.x]== INT_MAX)
        printf("Trapped!\n");
    else
        printf("Escaped in %d minute(s).\n",cost[end_node.z] [end_node.y] [end_node.x]);
}

int main ()
{
    int floor,row,col;
    while(1)
    {
        scanf("%d %d %d",&floor,&row,&col);
        getchar();
        if(floor==0 && row==0 && col==0) break;
        for(int k=0; k<floor; k++)
            for(int i=0; i<row; i++)
                scanf("%s",str[k] [i]);

//        for(int k=0; k<floor; k++)
//            for(int i=0; i<row; i++)
//                printf("%s\n",str[k] [i]);
        //int w=-1;
        for(int k=0; k<floor; k++)
        {
            for(int i=0; i<row; i++)
            {
                for(int j=0; j<col; j++)
                {
                    if(str [k] [i] [j] == 'S')
                    {
                        current_node.x=j;
                        current_node.y=i;
                        current_node.z=k;
                        //current_node.dist=0;
                    }
                    else if(str [k] [i] [j] == 'E')
                    {
                        end_node.x=j;
                        end_node.y=i;
                        end_node.z=k;
                    }
                    cost [k] [i] [j] = INT_MAX;

                }
                //if(w==1) break;
            }

            //if(w==1) break;
        }
//        printf("start %d %d %d\n",current_node.z,current_node.y,current_node.x);
//            printf("end %d %d %d\n",end_node.z,end_node.y,end_node.x);
        find_minimum_time(floor,row,col);

    }
    return 0;
}

