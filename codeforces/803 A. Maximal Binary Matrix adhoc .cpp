#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int ara[111][111];

int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n,k;

    cin>>n>>k;
    if(k> n*n) return cout<<-1<<endl,0;
//    for(int i=1; i<=n && k>0; i++) {
//        if(i == n-1 && k%2==0) break;
//        ara[i][i] = 1;
//        k--;
//    }

    for(int i=1; i<=n; i++)
    {
        for(int j= i; j<=n; j++)
        {
            if(k>1)
            {
                ara[i][j] = ara[j][i]=1;

                k-= ((i==j) ? 1:2 );
//                printf("1 k %d i %d j %d\n",k,i,j);

            }else if(k==1) {
//                printf("2 k %d i %d j %d\n",k,i,j);
                if(j>i) {
                    ara[i+1][i+1] = 1;
                    k=0;
                } else {
                    ara[i][i]=1;
                    k=0;
                }
            }
            if(!k) break;
        }
        if(!k) break;
    }
//    printf("k %d\n", k);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("%d ", ara[i][j]);
        }
        printf("\n");
    }

    return 0;

}

