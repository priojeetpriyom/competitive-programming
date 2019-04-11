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

int ara[10] [10];
int s_r,s_c,g_r,g_c;

struct node {
    int x,y;
};

void find_shortest_distance()
{
    int y[] = {-2,-2,1,-1,2,2 ,-1, 1};
    int x[] = {-1,1 ,2,2 ,1,-1,-2,-2};
    queue <node> Q;
    struct node current_node;
    current_node.y= s_r;
    current_node.x=s_c;
    Q.push(current_node);
    ara[s_r] [s_c] = 0;
    while(!Q.empty())
    {
        current_node=Q.front();
        for(int i=0;i<8;i++)
        {
            if(current_node.y+y[i]>=1 && current_node.y+y[i]<9 && current_node.x+x[i]>=1 && current_node.x+x[i]<9 && ara[current_node.y] [current_node.x]+1<ara[current_node.y+y[i]] [current_node.x+x[i]])
            {
                struct node new_node;
                new_node.y= current_node.y+y[i];
                new_node.x= current_node.x+x[i];
                ara[current_node.y+y[i]] [current_node.x+x[i]]= ara[current_node.y] [current_node.x]+1;
                Q.push(new_node);

            }
        }
        Q.pop();
    }
    printf("To get from %c%d to %c%d takes %d knight moves.\n",s_r+96,s_c,g_r+96,g_c,ara[g_r] [g_c]);
}

int main ()
{
    char temp[6];
    while(gets(temp))
    {
        s_r=temp[0]-96;
        s_c=temp[1]-48;
        g_r=temp[3]-96;
        g_c=temp[4]-48;
        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                ara[i] [j] = INT_MAX;
        find_shortest_distance();
    }
    return 0;
}


