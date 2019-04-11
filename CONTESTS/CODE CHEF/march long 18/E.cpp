#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MX 100100


int pre[MX] [50];



void process(int val, int pos) {


    for(int i=0; (val>>i)>0; i++)
        pre[pos] [i] =( (val>>i) &1);



}

int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
//    scanf("%d", &t);
//    cin>>t;
    t=1;

    for(int tc=1; tc<=t; tc++)
    {
        memset(pre, 0, sizeof pre);
        int n, q;
        cin>>n>>q;

        for(int i=1; i<=n; i++) {
            int x;
            cin>>x;
            process(x,i);
//                printf("\n");
//            for(int j=0; j<40; j++)
//                printf("%d ", pre[i] [j]);
//                printf("\n");
            for(int j=0; j<40; j++)
                pre[i][j] += pre[i-1][j];
        }

//            for(int j=0; j<40; j++)
//                printf("%d ", pre[n] [j]);
//                printf("\n");

        while(q--)
         {
            int l,r;
            cin>>l>>r;
            int tot = r-l+1;
            int ans = (1LL<<31)-1;
//            cout<<"l "<<l<<" r "<<r<<endl;
            for(int i=0; i<40; i++) {
                int one = pre[r][i]- pre[l-1][i];
                int zero = tot-one;
                if(one>= zero)
                    ans = ans & ~(1<<i);
//            printf("i %d one %d zero %d tot %d\n",i, one, zero, tot);
            }
            cout<<ans<<endl;
         }
    }


    return 0;

}
