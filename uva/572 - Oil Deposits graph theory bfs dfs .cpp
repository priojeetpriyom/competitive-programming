#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

struct node
{
    int x,y;
};
int ct=0,row,col;
char str[101] [101];

void find_deposit_groups(int r,int c)
{
    queue <node> Q;
    int x[] = {-1,0,1,1,1,0,-1,-1};
    int y[] = {-1,-1,-1,0,1,1,1,0};
    int pocket=1;
    struct node current_node;
    current_node.x=c;
    current_node.y=r;
    Q.push(current_node);
    while(!Q.empty())
    {
        current_node=Q.front();
        str[current_node.y] [current_node.x] = -1;
        for(int i=0; i<8; i++)
        {
            if(pocket==100) return;
            if(str[current_node.y+y[i]] [current_node.x+x[i]] == '@' && current_node.y+y[i]>= 0 && current_node.y+y[i]<row && current_node.x+x[i]>=0 && current_node.x+x[i]<col)
            {
                struct node next_node;
                next_node.y=current_node.y +y[i];
                next_node.x=current_node.x+x[i];
                Q.push(next_node);
                str[next_node.y] [next_node.x]=-1;
            }

        }
        Q.pop();
    }
}


int main ()
{

    while(1)
    {
        ct=0;
        scanf("%d %d",&row,&col);
        getchar();
        if(row==0) return 0;
        memset(str,0,sizeof(str));
        for(int i=0; i<row; i++)
            {
                scanf("%s",str[i]);
                str[i] [col]='\0';
            }

        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
            {
                if(str[i][j]=='@')
                {
                    find_deposit_groups(i,j);
                    ct++;
                }
            }

        printf("%d\n",ct);
    }
    return 0;
}

