#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void matMul(vector<ll> mat1[10], vector<ll> mat2[10],vector<ll> ans[10], int r1, int c1, int r2, int c2) {

    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            long long sum=0;
            for(int k=0; k<r2; k++) {
                sum+= (mat1[i][k] * mat2[k] [j] );
            }
            ans[i].push_back(sum);
        }

    }

}


int main()
{
//    freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    int r1,r2,c1,c2,ansR,ansC,x;

    while(cin>>r1>>c1>>r2>>c2) {
        vector<ll> mat1[10], mat2[10],ans[10];
        for(int i=0; i<r1; i++)
        {
            for(int j=0; j<c1; j++) {
                scanf("%d", &x);
                mat1[i].push_back(x);
            }
        }
        for(int i=0; i<r2; i++)
        {
            for(int j=0; j<c2; j++) {
                scanf("%d", &x);
                mat2[i].push_back(x);
            }
        }
        ansR = r1, ansC = c2;
        matMul(mat1,mat2, ans,r1,c1,r2,c2);
        for(int i=0; i<ansR; i++)
        {
            for(int j=0; j<ansC; j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;


}

