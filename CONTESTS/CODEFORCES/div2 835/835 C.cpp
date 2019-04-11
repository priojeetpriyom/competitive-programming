#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,q,c;

//ll ara[111] [111];

struct node
{

    ll fre[12];

    ll cnt=0;

};

struct node cum[111][111];

void merge_ara(int i, int j, int prev_i, int prev_j)
{

    for(int k=0; k<=10; k++)
    {
        cum[i][j].fre[k]+= cum[prev_i] [prev_j].fre[k];
    }
//    cnt+= cum[prev_i] [prev_j].cnt;



}

void sub_ara(ll temp[], ll arr[])
{

    for(int i=0; i<=10; i++)
        temp[i]-= arr[i];

}
void add_ara(ll temp[], ll arr[])
{

    for(int i=0; i<=10; i++)
        temp[i]+= arr[i];

}



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);


//    memset(ara, -1, sizeof ara);
    scanf("%I64d %I64d %I64d", &n, &q, &c);
    int x, y, s;

    for(int i=0; i<=100; i++)
    {
        for(int j=0; j<=100; j++)
        {

            memset(cum[i][j].fre,0, sizeof cum[i][j].fre);
        }
    }
//    int mx =0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d %d", &x, &y, &s);
//        mx = max(mx, max(x,y));
//        ara[x][y] = s;
        cum[x][y].fre[s]++;
//        cum[x][y].cnt++;
    }





    for(int i=1; i<=100; i++)
    {
        for(int j=1; j<=100; j++)
        {
            merge_ara(i,j, i,j-1);
        }
    }
//    for(int i=1; i<=mx; i++)
//    {
//        for(int j=1; j<=mx; j++)
//        {
//            printf("i %d j %d-> ",i,j);
//            for(int k=0; k<=10; k++)
//                printf("%d ", cum[i][j].fre[k]);
//            printf("\n");
//        }
//    }printf("\n\n");
    for(int j=1; j<=100; j++)
    {
        for(int i=1; i<=100; i++)
        {
            merge_ara(i,j, i-1, j);
        }
    }
//    for(int i=1; i<=mx; i++)
//    {
//        for(int j=1; j<=mx; j++)
//        {
//            printf("i %d j %d-> ",i,j);
//            for(int k=0; k<=10; k++)
//                printf("%d ", cum[i][j].fre[k]);
//            printf("\n");
//        }
//    }

    ll t, x1, y1, x2, y2;
    while(q--)
    {
        scanf("%I64d %I64d %I64d %I64d %I64d", &t, &x1, &y1, &x2, &y2);
        ll temp[12];
        for(int i=0; i<=10; i++)
        {
            temp[i] = cum[x2][y2].fre[i];
        }


        sub_ara(temp, cum[x2][y1-1].fre);
        sub_ara(temp, cum[x1-1][y2].fre);
        add_ara(temp, cum[x1-1][y1-1].fre);


        ll ans=0;

        for(int i=0; i<=10; i++)
        {
//            cout<<" i "<<i<<"-> "<<temp[i]<<",";
//            temp[i] = ;
            ans+= (temp[i] * ( (i+t) % (c+1) ) );
        }

        printf("%I64d\n", ans);


    }





    return 0;
}


