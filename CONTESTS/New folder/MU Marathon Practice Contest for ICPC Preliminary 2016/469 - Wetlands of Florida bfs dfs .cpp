char grid[100] [100];
bool visited[100] [100];
int start,endd,row=1,col=1,area;
struct node {
    int x,y;
};
struct node current_node;

void find_area()
{
    queue <struct node> Q;
    int y[] = {-1,-1,-1,0,1,1,1,0};
    int x[] = {-1,0,1  ,1,1,0,-1,-1};
    Q.push(current_node);
    //visited[current_node.y] [current_node.x]=true;
    area=0;
    while(!Q.empty())
    {
        current_node=Q.front();
        for(int i=0;i<8;i++)
        {
            if(grid[current_node.y+y[i]] [current_node.x+x[i]]== 'W' && visited[current_node.y+y[i]] [current_node.x+x[i]]== false && current_node.y+y[i]>0 && current_node.y+y[i]<row && current_node.x+x[i]>0 && current_node.x+x[i]<col )
            {
                visited[current_node.y+y[i]] [current_node.x+x[i]]= true;
                area++;
                struct node new_node;
                new_node.y=current_node.y+y[i];
                new_node.x=current_node.x+x[i];
                Q.push(new_node);
            }
        }
        Q.pop();
    }
}

int main() {
    int t,a=0,b=0;
    scanf("%d",&t);
    getchar();
    //getchar();
    current_node.y=0;
    current_node.x=0;
    while(t--)
    {
        row=1,col=1;
        int last_row,last_col;
        getchar();
        char c;
        while(gets(grid[row])) {
            //printf("%s\n",grid[row]);
            int len = strlen(grid[row]);
            if(len==0) break;
            row++;
            //printf("on\n");
    }
    last_row=row;
    col=strlen(grid[1]);
    int i;
    for(i=1;;i++)
        if(grid [i] [0]>48 && grid [i] [0]<58)
    {
        row=i;
        break;
    }
    for(;i<last_row;i++)
    {
        last_col= strlen(grid[i]);
        for(int j=0;j<last_col;j++)
        {
            if(j==0 || grid[i] [j]== ' ')
            {
                int x=0;
                int k=0;
                if(j!=0) k=j+1;
                while(k<last_col && grid[i] [k]!= ' ')
                {
                    x=x*10+ grid[i] [k]-48;
                    k++;
                }
                //printf("x %d\n",x);
                if(a==0)
                    a=x;
                else b=x;
            }
        }
        current_node.y=a;
        current_node.x=b;
       // printf("%d %d\n",current_node.y, current_node.x);
        find_area();
        //printf("on\n");
        printf("%d\n",area);
        a=0;
        current_node.x=0;current_node.y=0;
    }
    if(t>0) printf("\n");
    }
    return 0;
}
