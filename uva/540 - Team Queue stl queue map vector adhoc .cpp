#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
vector<int> vec[1001];
queue<int> Q;
int main()
{
//    freopen("myInput.txt","r",stdin);
//    freopen("myOutput.txt","w",stdout);

    int tcase;
    int n,x,k=1;
    while(scanf("%d",&tcase) && tcase!=0) {
        printf("Scenario #%d\n",k++);
        for(int t=0; t<tcase; t++) {
            scanf("%d",&n);

            while(n--) {
                scanf("%d",&x);
                mp[x]=t;
            }
    }

    char str[10];

    while(scanf("\n%s",str)==1 && strcmp(str, "STOP")!=0) {
        if(strcmp(str,"ENQUEUE")==0) {
            scanf("%d",&n);
            x=mp[n];
            if(vec[x].size()==0) {
                Q.push(x);
            }
            vec[x].push_back(n);

        } else {
            x = Q.front();
            printf("%d\n",vec[x][0]);
            vec[x].erase(vec[x].begin()+0);

            if(vec[x].size()==0)
                Q.pop();
        }
    }
        printf("\n");

        mp.clear();
        while(!Q.empty())
            Q.pop();
        for(int i=0; i<1001; i++)
            vec[i].clear();
    }




    return 0;
}


