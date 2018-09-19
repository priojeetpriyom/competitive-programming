
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 110
#define MOD 1000000007


//ll dp [MX] [MX] [3];
//int n, k,d;
//
//ll rec(int left, int sum, int is_greater) {
//    if(sum==0)
//        return is_greater;
//    if(sum<0 || !left)
//        return 0;
//
//    ll &ret= dp[left] [sum] [is_greater];
//    if(~ret)
//        return ret;
//    ret=0;
//
//    for(int i = k; i>=1; i--)
//        ret+= rec(left-1, sum-i , is_greater | (i>=d));
//    if(ret>= MOD)
//        ret%=MOD;
//    return ret;
//}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
//    memset(dp, -1, sizeof dp);


    int a, b, c, d;

    cin>>a>>b>>c>>d;

    int n=50, m=50;

    char str[55] [55];

    for(int i= 1; i<= 25; i++) {
        for(int j = 1; j<= 25; j++) {
            str[i][j] = 'A';
        }
    }

    for(int i= 1; i<= 25; i++) {
        for(int j = 26; j<= 50; j++) {
            str[i][j] = 'B';
        }
    }

    for(int i= 26; i<= 50; i++) {
        for(int j = 1; j<= 25; j++) {
            str[i][j] = 'C';
        }
    }

    for(int i= 26; i<= 50; i++) {
        for(int j = 26; j<= 50; j++) {
            str[i][j] = 'D';
        }
    }

    a--,b--,c--,d--;



    for(int i= 1; i<= 25; i+=2) {
        for(int j = 1; j<= 24; j+=2) {
            if(b) {
                str[i][j] = 'B';
                b--;
            }
        }
    }

    for(int i= 1; i<= 25; i+=2) {
        for(int j = 27; j<= 50; j+=2) {

            if(a) {
                str[i][j] = 'A';
                a--;
            }
        }
    }

    for(int i= 26; i<= 50; i+=2) {
        for(int j = 1; j<= 24; j+=2) {

            if(d) {
                str[i][j] = 'D';
                d--;
            }
        }
    }

    for(int i= 26; i<= 50; i+=2) {
        for(int j = 27; j<= 50; j+=2) {

            if(c) {
                str[i][j] = 'C';
                c--;
            }
        }
    }


    cout<<n<<" "<<m<<endl;

    for(int i=1; i<=n; i++){
        str[i][m+1] = '\0';
        cout<<str[i]+1<<endl;
    }

    return 0;
}


