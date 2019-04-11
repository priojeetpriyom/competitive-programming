#include <bits/stdc++.h>
using namespace std;
char chessBoard[8] [9];
int visited[8] [9], tCase;
int z;
int semiKnight1x[70], semiKnight2x[70], semiKnight1y[70], semiKnight2y[70];
int lenSemiKnight1, lenSemiKnight2;
struct node {
    int x,y;
};
bool bfs(int x, int y)
{
    struct node currentNode, newNode;
    queue <struct node> Q;
    currentNode.x=x;
    currentNode.y=y;
    Q.push(currentNode);
    while(!Q.empty())
    {
        //printf("aka\n");
        currentNode= Q.front();
//        if(visited[currentNode.x] [currentNode.y] == 1 &&z==1 && chessBoard[currentNode.x] [currentNode.y] != '#')
//        {
////            printf("%d %d\n",currentNode.x, currentNode.y);
////            return true;
//        }
        visited[currentNode.x] [currentNode.y] = z+1;
        if(z==0)
        {
            semiKnight1x[lenSemiKnight1]=currentNode.x;
            semiKnight1y[lenSemiKnight1++]=currentNode.y;
        }
        else {
            semiKnight2x[lenSemiKnight2]=currentNode.x;
            semiKnight2y[lenSemiKnight2++]=currentNode.y;
        }
        if(currentNode.y+2<8)
        {
           if(currentNode.x+2<8 && visited[currentNode.x+2] [currentNode.y+2]==0)
            {
                newNode.x= currentNode.x+2;
                newNode.y= currentNode.y +2;
                Q.push(newNode);
            }
            if(currentNode.x-2>=0 && visited[currentNode.x-2] [currentNode.y+2]==0)
            {
                newNode.x= currentNode.x-2;
                newNode.y= currentNode.y +2;
                Q.push(newNode);
            }
        }
        if(currentNode.y-2>=0)
        {
           if(currentNode.x+2<8 && visited[currentNode.x+2] [currentNode.y-2]==0)
            {
                newNode.x= currentNode.x+2;
                newNode.y= currentNode.y -2;
                Q.push(newNode);
            }
            if(currentNode.x-2>=0 && visited[currentNode.x-2] [currentNode.y-2]==0)
            {
                newNode.x= currentNode.x-2;
                newNode.y= currentNode.y -2;
                Q.push(newNode);
            }
        }
        Q.pop();
    }
    return false;
}
int main()
{
    bool x;

    scanf("%d", &tCase);
    while(tCase--) {
        z=0, lenSemiKnight1=0, lenSemiKnight2=0;
        x=false;
        for(int i=0; i<8;i++)
            {
                scanf("\n%s",chessBoard[i]);
                for(int j=0;j<8; j++)
                    visited[i] [j]=0;
            }
//        for(int i=0;i<8; i++)
        for(int i=0; i<8;i++)
            for(int j=0;j<8; j++)
            {
                if(chessBoard[i] [j] == 'K') {
                    x=bfs(i,j);
                    for(int i=0; i<8;i++)
                        for(int j=0;j<8; j++)
                            visited[i] [j]=0;

                    if(z==1)
                        break;
                    z++;
                }
            }
            for(int i=0;i<lenSemiKnight1; i++)
            {
                for(int j=0; j<lenSemiKnight2; j++)
                {
                    if(semiKnight1x[i] == semiKnight2x[j] && semiKnight1y[i] == semiKnight2y[j] && chessBoard[semiKnight1x[i]] [semiKnight1y[i]] != '#')
                    {
                        x=true;
                        break;
                    }
                }
            }
        if(x)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
