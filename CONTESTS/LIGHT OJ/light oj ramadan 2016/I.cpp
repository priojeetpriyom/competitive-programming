#include <bits/stdc++.h>

using namespace std;

bool existance[100005];
int ara[100005];
int input[100005];
priority_queue<int> pq;
int main ()
{
    int t,n;

    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            int x;
            scanf("%d",&x);
            input[x] = i+1;
            pq.push(x);
        }
//        printf("oka");
        long long sum=0;
        int i=0;
        while(!pq.empty())
        {
            ara[i++] = pq.top();
            pq.pop();
//            printf("%d\n",i);
        }
//        printf("aise");
        for(i = 0; i<n; i++) {
//            printf("i %d ara %d\n",i,ara[i]);
            if(existance[ input[ara[i]]-1] || existance[input[ara[i]]+1 ]);
            else
            {
                sum+=ara[i];
                existance[input[ara[i]]]=1;
            }
        }

        printf("%lld\n",sum);
        if(t!=0) {
            memset(existance,0,sizeof(existance));
        }
    }


    return 0;
}


