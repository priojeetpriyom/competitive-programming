#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void printMat(vector<ll> mat[10], int r, int c) {
    printf("\nprinting MATRIX..\n");
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout<<mat[i][j]<<" ";
        }
        printf("\n");
    }
    printf("\n");
}


int id=0;
void matMul(vector<ll> mat1[10], vector<ll> mat2[10],vector<ll> ans[10], int r1, int c1, int r2, int c2) {
    vector<ll> vec[10];
//printf("aise ID %d r1 %d c1 %d r2 %d c2 %d\n", id,r1,c1,r2,c2);
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            long long sum=0;
            for(int k=0; k<r2; k++) {
//                printf("starting ");
//                cout<<"mat1 "<<mat1[i][k]<<" mat2 "<<mat2[k][j]<<endl;
                sum+= (mat1[i][k] * mat2[k] [j] );
//                printf("i %d j %d k %d sum %lld\n",i,j,k,sum);
            }
//            printf("putting value ");
            vec[i].push_back(sum);
//            printf("done\n");
        }

    }
//    printf("printing ans\n");
//    printMat(vec, r1,c2);
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            ans[i][j] = vec[i][j];
        }
    }
}

void getMod(vector<ll> mat[10], int r, int c, int mod) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            mat[i][j] %= mod;
        }
    }
}

long long matBigMod(vector<ll> mat[10], vector<ll> ans[10],vector<ll> pwMat[10], int r, int c, int pw, int mod) {
    while(pw>0) {
//        printf("staring seqMat\n");
//        printMat(pwMat,2,2);
        if(pw&1) {
//                printf("aise pw %d\n", pw);
//        printMat(ans, 2, 1);
            matMul(pwMat, ans, ans, r,c,2,2);
//            printMat(ans,2,1);
            getMod(ans,2,2, mod);
        }
        matMul(pwMat, pwMat, pwMat, r,c,r,c);
        getMod(pwMat,r,c,mod);
        pw>>=1;
    }
}


int main()
{
//    freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    ll n,m;

    while(cin>>n>>m) {
        vector<ll> matSeq[10], mat[10],ans[10], pwMat[10];

        mat[0].push_back(1);
        mat[1].push_back(0);
        matSeq[0].push_back(1);
        matSeq[0].push_back(1);
        matSeq[1].push_back(1);
        matSeq[1].push_back(0);
        ans[0].push_back(1);
        ans[0].push_back(0);
        ans[1].push_back(0);
        ans[1].push_back(1);
        pwMat[0].push_back(1);
        pwMat[0].push_back(1);
        pwMat[1].push_back(1);
        pwMat[1].push_back(0);
        matBigMod(matSeq, ans, pwMat, 2,2,n, (1<<m));
        id=1;
//        printMat(ans, 2,2);
//        printMat(mat, 2,1);
        matMul(ans, mat, ans, 2,2,2,1);
        cout<<ans[1][0]<<endl;
        for(int i=0; i<2; i++) {
            mat[i].clear();
            ans[i].clear();
            matSeq[i].clear();
            pwMat[i].clear();
        }
    }

    return 0;


}

