#include <bits/stdc++.h>
using namespace std;

struct node {
    int city, cost;
    int cnt;
};
vector<int > dist[5011],connection[5011];
int visited[5011][5011], ara[5011],len_ara=1;
int ara_mx[5011],len_mx;
int n,m,t;
int mx=INT_MIN;

void find_max() {
    ara_mx[0] =1;
    queue <struct node *> Q;
    struct node* current = new node();
    current->city = 1;
    current->cost=0;
    current->cnt=1;
    Q.push(current);

    while(!Q.empty()) {
        current = Q.front();
        Q.pop();
        int city = current->city;
        int cost = current->cost;
        ara[len_ara++] = city;
        for(int i=0; i<connection[city].size(); i++) {
//                printf("city %d to %d cost %d",city, connection[city] [i], )
            if(!visited[city] [connection[city][i] ] && cost + dist[city] [i] <=t ) {
//
                visited[city] [connection[city][i]] = true;
                struct node* newNode = new node();
                newNode->city = connection[city][i];
                newNode->cost = cost + dist[city] [i];
                newNode->cnt = current->cnt+1;
                Q.push(newNode);

//                printf("city %d from city %d cost %d total %d\n",newNode->city,city, dist[city] [i], newNode->cost );
            }
        }

        if(cost> mx){

                    mx = newNode->cnt;
                    for(len_mx =1; len_mx<len_ara; len_mx++)
                        ara_mx[len_mx] = ara[len_mx];
                    ara_mx[len_mx++] = newNode->city;
                }
                ara[len_ara--];

    }
}



int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);



    scanf("%d %d %d",&n, &m, &t);
    int u,v,x;
    for(int i=0; i<m; i++) {
        scanf("%d %d %d",&u, &v, &x);
        connection[u].push_back(v);
        dist[u].push_back(x);
        printf("u %d v %d dist %d len_1 %d\n",u,v,x,connection[1].size());
    }

//    for(int i=0; i<n; i++) {
//            printf("city %d-> ",i);
//        for(int j=0; j< connection[i].size(); j++) {
//            printf("%d, ",connection[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n\n");
//
//    for(int i=0; i<n; i++) {
//            printf("dist %d-> ",i);
//        for(int j=0; j< connection[i].size(); j++) {
//            printf("%d, ",dist[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n\n");


//    if(visited[1][2])
//        printf("BAAL\n");



    find_max();
    printf("%d\n",mx);
    for(int i=0; i<len_mx; i++)
        printf("%d ",ara_mx[i]);
    printf("\n");
    return 0;
}
