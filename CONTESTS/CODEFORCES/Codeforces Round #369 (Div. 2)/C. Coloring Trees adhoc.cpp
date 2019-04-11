#include <bits/stdc++.h>
using namespace std;

struct node
{
    int row,col,cost;
    int operator<(const node& other) const
    {
        return cost > other.cost;
    }
};
priority_queue<struct node> pq;

int ara[101];
int p[101] [101];
int get_groups(int n) {
    int cnt=0;
    if(ara[0]!=0 && ara[1]==0)
        cnt=1;
    for(int i=1; i<n; i++)
        if(ara[i]!=0)
        if(ara[i]!= ara[i-1])
            cnt++;
    return cnt;
}

int main()
{
//    freopen("myOutput.txt","w",stdout);

    int n,m,k;
    scanf("%d %d %d",&n, &m,&k);

    for(int i=0; i<n; i++)
        scanf("%d",&ara[i]);

        struct node current_node;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int x;
            scanf("%d",&p[i] [j]);
            current_node.cost =  p[i][j];
            current_node.col=j;
            current_node.row =i;
            pq.push(current_node);
        }
    }
    int groups = get_groups(n);

    int total_cost=0;
    while(!pq.empty() && groups != k) {
            current_node = pq.top();
            pq.pop();

        if(groups>k) {
            if(ara[current_node.row]==0) {
                int x=INT_MAX,y=INT_MAX;
                if(current_node.row !=0 ) {
                    x = p[current_node.row] [ara [current_node.row] -1];
                }
                if(current_node.row!= n-1) {
                    y = p[current_node.row] [ara [current_node.row] +1];
                }
                if(y==x && x==INT_MAX) {
                    total_cost+=current_node.cost;
                    ara[current_node.row] = current_node.col+1;

                } else if(y<x) {
                    total_cost+= y;
                    ara[current_node.row] = ara[current_node.row+1];
                }else {
                    total_cost+= x;
                    ara[current_node.row] = ara[current_node.row-1];
                }
                groups = get_groups(n);
            }
        } else {
            if(ara[current_node.row]==0) {
//                printf("oka  ");
                if((current_node.row!=0 && (current_node.col!= ara[current_node.row -1 ] || ara[current_node.row -1 ]==0 )) || (current_node.row!=n-1 && (current_node.col!= ara[current_node.row +1 ] || ara[current_node.row +1 ] == 0))) {
                    total_cost+=current_node.cost;
                    ara[current_node.row] = current_node.col+1;
                    groups = get_groups(n);
                }

            }
        }
        printf("total cost %d current_cost %d groups %d current_row %d current_col %d ara_row %d\n",total_cost,current_node.cost,groups,current_node.row,current_node.col,ara[current_node.row]);
    }
    printf("%d\n",total_cost);
    return 0;
}
