#include <bits/stdc++.h>
using namespace std;
char grid [22] [22];
bool visited[22] [22];
int w,h,mx;
struct node {
    int x,y;
    int cnt;
};

int dir_y[] = {1,0,-1,0},dir_x[] = {0,1,0,-1};

struct node* current = new node();
void calc () {
    queue<struct node*> Q;
    Q.push(current);

    while(!Q.empty()) {
        current  = Q.front();
        Q.pop();

        int r= current->y, c = current->x , cost = current->cnt;
        for(int i=0; i<4; i++) {
//            printf("r %d c %d cnt %d\n",dir_y[i] + r,dir_x[i] + c,cost);
            if(dir_x[i] + c<w && dir_x[i] +c>=0 && dir_y[i] + r<h && dir_y[i] + r >=0 && grid[dir_y[i] + r] [dir_x[i] + c] == '.' && !visited[dir_y[i] + r][dir_x[i] + c]) {
                visited[dir_y[i] + r][dir_x[i] + c] = 1;

                struct node* newNode = new node();
                newNode->x = dir_x[i] + c;
                newNode->y = dir_y[i] + r;
                newNode->cnt = cost+1;
                Q.push(newNode);

//                if(cost+1 > mx)
//                    mx=cost+1;
            }

        }

    }
}

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for(int tcase=1; tcase<= t; tcase++) {
        scanf("%d %d",&w,&h);

        for(int i=0; i<h; i++) {
            scanf("\n%s",grid[i]);
        }

        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(grid[i] [j] =='@') {
//                    mx=0;
                    current->x = j;
                    current->y = i;
                    current->cnt=1;
                    memset(visited,0,sizeof(visited));
                    visited[i][j]=1;
                    calc();

                    break;
                }
            }
        }
        mx=0;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
               if(visited[i][j])
                    mx++;
            }}


        printf("Case %d: %d\n",tcase,mx);
    }

    return 0;
}
