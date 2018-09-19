#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int d,mod,n;
long long ans[20] [20], mat[20] [20],matPw[20] [20];

void printMat(ll matt[][20], int r, int c, string s) {
    printf("\nprinting %s..\n",s.c_str());
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout<<matt[i][j]<<" ";
        }
        printf("\n");
    }
    printf("\n");
}




void setDiagonalOne(ll ara[][20], int i, int j) {
    while(i<=d && j<=d) {
        ara[i][j]=1;
        i++, j++;
    }
}



void matMul(ll mat1[][20], ll mat2[][20],ll answer[][20], int r1, int c1, int r2, int c2) {
    ll anss[20][20];
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            ll temp=0;
            for(int k=0; k<c1; k++) {
                temp += (mat1[i] [k] * mat2[k][j]);
            }
            anss[i][j] = temp % mod;
        }
    }

    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            answer[i][j] = anss[i][j];
        }}

//    memcpy(mat1, ans, sizeof ans);
}


void matBigMod(int pw) {
    while(pw>0) {
        if(pw&1) {
            matMul(ans, matPw,ans, d,d,d,d);
        }
        matMul(matPw,matPw,matPw, d,d,d,d);
        pw>>=1;
    }
}


int main()
{
//    freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    while(scanf("%d %d %d", &d, &n, &mod)==3 && d!=0) {
        memset(ans,0, sizeof ans);
        memset(matPw, 0, sizeof matPw);
        memset(mat, 0, sizeof mat);

        setDiagonalOne(ans, 0,0);
        setDiagonalOne(matPw, 1, 0);

        for(int i=0; i<d; i++)
            scanf("%lld", &matPw[0][i]);

        for(int i=0; i<d; i++)
            scanf("%lld", &mat[d-i-1] [0]);

        matBigMod(n-d);

//        printMat(mat, d,1,"InputMat");
        matMul(ans, mat,mat, d,d,d,1);
//        printMat(ans, d,d, "ans");
//        printMat(mat, d,1,"InputMat After mul");
        printf("%lld\n", mat[0][0]);
    }

    return 0;


}

