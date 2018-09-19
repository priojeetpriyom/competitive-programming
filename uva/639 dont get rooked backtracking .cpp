#include <bits/stdc++.h>
using namespace std;
int n,maxRooks;
bool VISITED[5] [5];
bool isValid(int i, int j, bool visited[][5], char board[] [5])
{
    //printf("i %d j %d\n",i,j);
    //visited[i] [j]=true;
    for(int k=i; k<n; k++)
    {

        if(visited[k] [j]==true)
            return false;
        if(board[k][j] == 'X')
            break;
    }
    for(int k=i; k>=0; k--)
    {

//        else
//            //printf("%d %d %c\n",k, j, board[k] [j]);
        if(visited[k] [j]==true)
            return false;
        if(board[k][j] == 'X')
            break;
    }
    for(int k = j; k<n; k++)
    {

//        else
//            //printf("%d %d %c\n",i, j, board[i] [j]);
        if(visited[i] [k]==true)
            return false;
        if(board [i] [k] == 'X')
            break;
    }
    for(int k = j; k>=0; k--)
    {

//        else
//            //printf("%d %d %c\n",i, j, board[i] [j]);
        if(visited[i] [k]==true)
            return false;
        if(board [i] [k] == 'X')
            break;
    }
    return true;

}

void FindMaxRooks(char board[][5], int rooks, bool visited[][5], int i, int j)
{

    for(int m=0; m<n; m++)
    {
        for(int o=0; o<n; o++)
        {
            //printf("loop i %d j %d n %d\n",m, o,maxRooks);
            if(board [m] [o] == '.' && isValid(m,o,visited,board))
            {
//                printf("loop i %d j %d n %d visited %d\n\n",m, o,maxRooks,visited[2] [0]);
                if(rooks+1>maxRooks)
                    maxRooks = rooks+1;
                //printf("maxrooks %d ",maxRooks);
                //printf("m %d o %d\n",m,o);
                //makeVisited(m,o,visited, board);
                visited[m] [o] = true;
                FindMaxRooks( board, rooks+1, visited, i ,0);
                //printf("m %d o %d\n",m,o);
                //makeUnVisited(m,o,visited, board);
                visited[m] [o] = false;
                ////printf("\n");
//                for(i =0; i<n; i++)
//                {
//                    for(j=0; j<n; j++)
//                    {
//                        //printf("%d ",visited[i] [j]);
//                    }
//
//                }

            }
//            else if(i ==2)
//            {
//                //printf("b %c v %d j %d",board[i][j], visited[i] [j], j);
////            }
        }
        //m++;
        i++;
        //j=0;
        ////printf("i %d\n",i);
    }
    return;
}
int main()
{
        //freopen("myOutput.txt","w",stdout);
        //freopen("myInput.txt","r",stdin);
    //int n;
    char board[5] [5];
    int temp;
    while(scanf("%d",&n)==1 && n!=0)
    {
        bool visited[5] [5]= {false};
        VISITED[5] [5] = {false};
        maxRooks=temp=0;

        for(int i=0; i<n; i++)
            //{
                scanf("%s",board[i]);

                //cout<<n<<" "<<i <<endl;
            //}
        //m=0;
        FindMaxRooks(board,0,visited, 0, 0);
//        for(int i =0; i<n; i++)
//        {
//            ////printf("%s\n",board[i]);
//            for(int j=0; j<n; j++)
//            {
//                if(board[i] [j] == '.')
//                {
//                    memset(visited,0,sizeof(visited));
//                    maxRooks=0;
//                    FindMaxRooks(board,0,visited, i, j);
//                    if(maxRooks>temp)
//                        temp=maxRooks;
//                }
//            }
//            ////printf("\n");
//        }
        ////printf("\n\n");
        printf("%d\n", maxRooks);
    }

    return 0;
}

