#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int  n, ara[101][101], cumCol[101][101], cumRow[101][101];


//maximal sum uva 108

int main() {
    while(scanf("%d", &n)==1) {
        for(int i=1; i<=n; i++)
            cumCol[i][0] = cumRow[0] [i]=0;
        int mx=INT_MIN;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d", &ara[i] [j]);
                mx = max(mx, ara[i][j]);
                cumCol[i][j] = ara[i][j] + cumCol[i][j-1];
//                printf("%d ", cumCol[i][j]);
//                cumRow[i][j] = ara[i][j] + cumRow[i-1] [j];
            }
//            printf("\n");
        }

//        for(int i=1; i<=n; i++) {
//            for(int j=1; j<=n; j++) {
//
//                printf("%d ", cumCol[i][j]);
////                cumRow[i][j] = ara[i][j] + cumRow[i-1] [j];
//            }
//            printf("\n");
//        }




        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                for(int l = j; l<=n; l++) {
                    int sum = 0;
                    for(int k= i; k<=n; k++) {
                        sum+= (cumCol[k][l] - cumCol[k][j-1]);
//                        if(i==2 && j==1) {
//                            printf("r %d c %d sum %d\n", k,l,sum);
//                        }
                        mx = max(mx, sum);
                    }
                }
            }
        }



//        for(int i=1; i<=n; i++) {
//            int sum=0;
//            for(int j=1; j<=n; j++) {
//                sum+= ()
//            }
//        }

        printf("%d\n", mx);
    }
}
