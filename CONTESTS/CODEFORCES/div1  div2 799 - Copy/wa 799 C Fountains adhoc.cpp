#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node
{
    char type;
    int cost,beauty, id;
} ara[100100];

bool cmp(node a, node b)
{
    return a.cost<=b.cost;
}
int C_id[100100], D_id[100100];
int C[100100], D[100100];

int cnt_c[100100], cnt_d[100100], cum_c[100100], cum_d[100100];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n,c,d;

    scanf("%d %d %d", &n, &c, &d);
    ara[0].cost = -1;
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d", &ara[i].beauty, &ara[i].cost);
        scanf("\n%c", &ara[i].type);
//        ara[i].id = i;
    }
//    printf("oka\n");

    sort(ara, ara+n+1, cmp);


//    for(int i=1; i<=n; i++)
//    {
//        printf("i %d beauty %d cost %d type- %c\n", i, ara[i].beauty, ara[i].cost, ara[i].type);
//
//    }

    int mx_c=0, mx_d=0, mx_c_id=0, mx_d_id=0;
    int x=1;
    cum_c[0]=cum_d[0]=0;
    for(int i=1; x<=n; i++)
    {
//        printf("i %d x %d ara[x].cost %d\n", i, x, ara[x].cost);
//        printf("i %d mx_c %d mx_d %d\n", i, mx_c, mx_d);
        int f=0;
        if(ara[x].cost == i)
        {
            if(ara[x].type == 'C')
            {
//                printf("type_c i %d mx_c %d ara %d\n",i,mx_c, ara[x].beauty);
                if(ara[x].beauty > mx_c)
                {
                    mx_c =ara[x].beauty;
                    mx_c_id = x;
//                    printf("updated mx_c %d\n", mx_c);
                }
            }
            else
            {
//                printf("type_d i %d mx_d %d ara %d\n",i,mx_d, ara[x].beauty);
                if(ara[x].beauty > mx_d)
                {
                    mx_d =ara[x].beauty;
                    mx_d_id = x;
                }
            }
            f=1;
        }
        C[i] = mx_c;
        D[i] = mx_d;
        C_id[i] = mx_c_id;
        D_id[i] = mx_d_id;
        cum_c[i] = cum_c[i-1];
        cum_d[i] = cum_d[i-1];

        if(f)
        {
            while(ara[x].cost == i && x<=n)
            {
//                    printf("f dhukse\n");
//                if(ara[x].type=='C') cnt_c[ara[x].cost]++;
//                else cnt_d[ara[x].cost]++;
                cum_c[i] +=  (ara[x].type=='C');
                cum_d[i] +=  (ara[x].type=='D');
//                printf("x %d cum_c %d cum_d %d\n", x, cum_c[x], cum_d[x]);
                x++;
            }

        }
        if(x==n+1)
        {
//            printf("aise\n");
            for(i = i+1; i<= max(c,d); i++)
            {

                C[i] = mx_c;
                D[i] = mx_d;
                C_id[i] = mx_c_id;
                D_id[i] = mx_d_id;
                cum_c[i] = cum_c[i-1];
                cum_d[i] = cum_d[i-1];
            }
        }
    }

//    for(int i=1; i<=30; i++)
//    {
//        printf("i %d C_id %d D_id %d\n",i, C_id[i], D_id[i]);
//    }


//    for(int i=1; i<=n; i++)
//    {
//        printf("i %d beauty %d cost %d type- %c\n", i, ara[i].beauty, ara[i].cost, ara[i].type);
//
//    }

    int ans=0;
    C[0]=D[0]=0;
    for(int i=1; i<=n; i++)
    {
        int pick;
        pick = ara[i].beauty;
        int left_c=c,left_d=d;
        if(ara[i].type == 'C')
            left_c-= ara[i].cost;
        else
            left_d-= ara[i].cost;
//        printf("pick %d left_c %d left_d %d C %d D %d cum_c %d cum_d %d i %d\n", pick, left_c, left_d, C[left_c], D[left_d], cum_c[left_c], cum_d[left_d], i);
        if(left_c <0 || left_d<0) continue;
        if(max(C[left_c], D[left_d])==0) continue;
        int cc=C[left_c],dd=D[left_d];

        if(ara[i].type=='C')
        {
            if(C_id[left_c] == i) cc=  C[C_id[left_c]-1];
        }
        else if(D_id[left_d] == i) dd=  D[D_id[left_d]-1];
        if(max(cc, dd)==0) continue;
//        printf("pick %d cc %d dd %d\n", pick, cc, dd);
        pick+= max(cc,dd);

        if(pick > ans ) ans = pick;
    }

    printf("%d\n", ans);

    return 0;
}


