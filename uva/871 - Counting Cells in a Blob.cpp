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
int row,col;
char str[26] [26];

int counting_cells(int r,int c)
{
    queue <node> Q;
    int x[] = {-1,0,1,1,1,0,-1,-1};
    int y[] = {-1,-1,-1,0,1,1,1,0};
    struct node current_node;
    current_node.x=c;
    current_node.y=r;
    Q.push(current_node);
    int ct=0;
    while(!Q.empty())
    {
        ct++;
        current_node=Q.front();
        str[current_node.y] [current_node.x] = -1;
        for(int i=0; i<8; i++)
        {
            if(str[current_node.y+y[i]] [current_node.x+x[i]] == '1' && current_node.y+y[i]>= 0 && current_node.y+y[i]<row && current_node.x+x[i]>=0 && current_node.x+x[i]<col)
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
    return ct;
}


int main ()
{
    int t;
    scanf("%d",&t);
    getchar();
    getchar();
    int i=0;

    while(t--)
    {

        memset(str,0,sizeof(str));
        row=0,col=0;
        char c,temp[30];
        while(gets(temp))
            {
                if(temp[0]=='\0') break;
                int len = strlen(temp);
                temp[len] = '\0';
                for(int i=0;i<len;i++)
                    str[row] [i] = temp[i];
                if(col==0) col=len;
                row++;
                memset(temp,0,sizeof(temp));
            }
        int mx=0;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
            {
                if(str[i][j]=='1')
                {
                    int x = counting_cells(i,j);
                    mx=max(mx,x);

                }
            }

        printf("%d\n",mx);
        if(t>0) printf("\n");
    }
    return 0;
}

