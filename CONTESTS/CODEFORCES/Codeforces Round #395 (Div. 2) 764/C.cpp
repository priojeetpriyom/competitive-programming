#include<bits/stdc++.h>
using namespace std;
int colors[200100], connection[200100] [3], diff[200100];
vector<int> vec[200100];
int main()
{
//    freopen("myOut.txt", "w", stdout);
    int n;
    cin>>n;

    for(int i=1; i<n; i++)
    {
        scanf("%d %d", &connection[i][0], &connection[i][1]);
        vec[connection[i][0]].push_back(connection[i][1]);
        vec[connection[i][1]].push_back(connection[i][0]);
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &colors[i]);
    }
    for(int i=1; i<=n; i++)
    {
        int l = vec[i].size(), x=0;
        for(int j=0; j<l; j++)
        {
            if(colors[i] != colors[vec[i][j]])
                x++;
        }
        diff[i] = x;
    }
//    for(int i=1; i<=n; i++)
//        printf("%d ", diff[i]);
//    printf("\n");
    int node=0;
    int cnt=0;
    for(int i=1; i<n; i++)
    {
        if(colors[connection[i][0] ] != colors[ connection[i][1] ])
        {
            if(node==0)
            {
                if(diff[connection[i][0]] > diff[connection[i][1]])
                {
//                    printf("%d %d\n", diff[connection[i][0]] , diff[connection[i][1]] );
                    node = connection[i][0];
                }
                else
                    node = connection[i][1];
                continue;
            }
            if(node == connection[i][0] || node == connection[i][1])
                continue;

            cnt++;
                break;
        }
    }
    node = max(1, node);
    if(cnt>0)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n%d\n", node);
    }
    return 0;

}

