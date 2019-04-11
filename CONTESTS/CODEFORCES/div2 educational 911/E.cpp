#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 200100


int ara[MX], vis[MX];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;

//    cin>>n>>k;
    scanf("%d %d", &n, &k);

    for(int i=1; i<=k; i++)
    {
//        cin>>ara[i];
        scanf("%d", &ara[i]);
        vis[ara[i] ]=1;
    }

    int cnt=0;
    stack<int> S;
    for(int i=1; i<=k; i++)
    {
        S.push(ara[i]);
        while(S.size()>0 && S.top() == cnt+1)
        {
            cnt++;
            S.pop();
        }
    }
    stack<int> pre(S);
    if(S.size()>1)
    {
        int mx = S.top();
        S.pop();
        while(!S.empty())
        {
            if(S.top()<mx)
            {
//                cout<<-1<<endl;
                printf("-1\n");
                return 0;
            }
            mx = max(mx, S.top());
            S.pop();
        }
    }

    for(int i=1; i<=k; i++)
//        cout<<ara[i]<<" ";
        printf("%d ", ara[i]);

    if(pre.size()>=1)
    {
        while(!pre.empty())
        {
            for(int i = pre.top()-1; i>0; i--)
            {
                if(!vis[i])
                {
//                    cout<<i<<" ";
                    printf("%d ",i);
                    vis[i]=1;
                } else
                    break;

            }
            pre.pop();

        }
    }
//    else
//    {
        for(int i = n; i>0; i--)
        {
            if(!vis[i])
//                cout<<i<<" ";
                printf("%d ", i);
        }
//    }



    return 0;
}


