#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int bone[1000005];


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n,m,k;
    int pos=1;
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++)
    {
        int x;
        scanf("%d", &x);
        bone[x]=1;
    }
    int u,v;
    int hole = bone[pos];
    for(int i=0; i<k; i++)
    {
        scanf("%d %d", &u, &v);

        if(!hole)
        {
//            printf("i %d dhukese pos %d u %d v %d\n", i, pos, u, v);
            if(pos ==u) pos=v;
            else if(pos==v) pos= u;
        }
        if(bone[pos]) hole=true;
//        printf("pos %d hole %d\n", pos, hole);
    }
    cout<<pos;
    return 0;
}


