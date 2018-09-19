#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ara[1111] [1111], cols[1111] [1111], rows[1111][1111];
int main()
{
    //    freopen("out.txt", "w", stdout);


    int n;
    int t;
    cin>>t;

    while(t--)
    {
        cin>>n;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d", &ara[i][j]);
                cols[i][j] = rows[i][j] = 1;
            }
        }



        for(int i=1; i<=n; i++) {
            for(int j=2; j<=n; j++) {
                if(ara[i][j] == ara[i][j-1])
                    cols[i][j] = cols[i][j-1] +1;
            }
        }


        for(int j=1; j<=n; j++) {
            for(int i=2; i<=n; i++) {
                if(ara[i][j] == ara[i-1] [j])
                    rows[i][j] = rows[i-1][j]+1;
            }
        }

//        for(int i=1; i<=n; i++) {
//            for(int j=1; j<=n; j++) {
//                printf("%d,%d  ", rows[i][j], cols[i][j]);
//            }
//            printf("\n");
//        }


        int mx = 1;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(cols[i][j] == rows[i+ cols[i][j]-1][j] && (i+ cols[i][j]-1) <=n)
                    mx = max(mx, cols[i][j]);
            }
        }
        cout<<mx<<endl;
    }

    return 0;
}


