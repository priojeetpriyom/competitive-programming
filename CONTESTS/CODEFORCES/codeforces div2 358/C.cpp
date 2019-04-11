#include <bits/stdc++.h>

using namespace std;
struct node {
    int lim,num, dist=INT_MAX;
    vector<int> connectedNodes;
    vector<int> distance;
};
struct node vec[100005];
int main ()
{
    int n,x,y;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&x);
        vec[i].lim = x;
    }

    for(int i=1; i<n; i++)
    {
        scanf("%d %d",&x, &y);
        vec[i+1].connectedNodes.push_back(x);
        vec[i+1].distance.push_back(y);
        vec[x].connectedNodes.push_back(i+1);
        vec[x].distance.push_back(y);

        //printed just inputed data here

        printf("vec i %d dist %d\n",vec[i+1].connectedNodes[vec[i].connectedNodes.size()-1],vec[i+1].distance[vec[i].distance.size()-1]);
        printf("vec x %d dist %d\n",vec[x].connectedNodes[vec[i].connectedNodes.size()-1],vec[x].distance[vec[i].distance.size()-1]);
    }

        //printed all data here

//    for(int i=1; i<=n ;i++) {
//        printf("%d lim => %d\n",i,vec[i].lim);
//        for(int j=0; j< vec[i].connectedNodes.size(); j++) {
//            printf("connected %d distance %d\n",vec[i].connectedNodes[i], vec[i].distance[j]);
//        printf("\n");
//        for(int j=0; j< vec[i].connectedNodes.size(); j++) {
//            printf("%d ",vec[i].distance[i]);
//        printf("\n");
//
//        }
//    }
//    }

    queue<struct node*> Q;
    int cnt=1;
    vec[1].dist=0;
    Q.push(&vec[1]);
    struct node* currentNode;

    while(!Q.empty()) {

        currentNode = Q.front();
        Q.pop();
        for(int i=0; i< currentNode->connectedNodes.size(); i++) {
            struct node* newNode;
            newNode = &vec[currentNode->connectedNodes[i]];
//            printf("newnode dist %d currentNode dist %d dist[i] %d ",newNode->dist,currentNode->dist, currentNode->distance[i]);
            if(newNode->dist != INT_MAX ){
                continue;
            }

                newNode->dist = currentNode->dist+currentNode->distance[i];

//                printf("newDist %d\n",newNode->dist);

//            vec[currentNode->connectedNodes[i]] = newNode;
            if(newNode->dist<= newNode->lim)
            {
                    cnt++;
                    Q.push(newNode);
//                    printf("reachable node %d\n",newNode->lim);
                }

//            if(! newNode->endIt)

        }
//        printf("\n");
//        printf("coler %d cnt %d\n", currentNode.dist, cnt);
    }
    printf("%d\n",n-cnt);
}


