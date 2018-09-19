#include <bits/stdc++.h>
using namespace std;

int maze[1010] [1010], n,m;


struct node{
    int row,col, cost=0;
};
bool operator<(const node& a, const node& b)
{
    return a.cost> b.cost;
}
void bfs(int cost[] [1010])
{
    priority_queue<node> Q;
    struct node currentNode;
    currentNode.row=0; currentNode.col=0;currentNode.cost = maze[0][0];
    Q.push(currentNode);
    int r[] ={1,-1,0,0}, c[]= {0,0,1,-1};
//    int cnt=0;
    while(Q.size())
    {
//        cnt++;
//        cout<<"cnt "<<cnt<<endl;
        currentNode = Q.top();
        Q.pop();

        for(int i= 0; i<4; i++)
        {
            struct node newNode;
            newNode.row = currentNode.row + r[i];
            newNode.col =currentNode.col +c[i];
            if( (newNode.row) <n && (newNode.row) >=0 && (newNode.col) <m && (newNode.col) >=0 && (currentNode.cost + maze[newNode.row] [newNode.col]) < cost [newNode.row ] [newNode.col ] )
            {

                cost [newNode.row ] [newNode.col ] = currentNode.cost + maze[newNode.row] [newNode.col];

                newNode.cost = cost [newNode.row ] [newNode.col ];
                Q.push(newNode);

            }
        }

    }

}
int main()
{

//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w",stdout);

    int t;
    scanf("%d", &t);
    while(t--)
//    for(int k=0; k<t; k++)
    {
//        cout<<k<<endl;
//        printf("t %d\n", t);
        int cost[1010] [1010];
        scanf("%d %d",&n, &m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                scanf("%d", &maze[i] [j]);
                cost[i] [j] = INT_MAX;
            }
//    for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<m; j++)
//                printf("%d ",cost[i] [j]);
//            printf("\n");
//        }
        bfs(cost);
        cost[0] [0] = min(cost[0][0], maze[0] [0]);
//        cout<<"k "<<k<<endl;
        printf("%d\n", cost[n-1] [m-1]);
    }


    return 0;
}


