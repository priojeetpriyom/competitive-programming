#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

int solve(int n)
 {
     int sum=0;
     while(n>0)
     {
         sum+= (n%10);
         n/=10;
     }
     return sum;
 }

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int k;
    cin>>k;

    int cnt=0;
    int n=18;
    while(cnt<k) {
        n++;
        if(solve(n)==10)
            cnt++;
    }

    cout<<n<<endl;


    return 0;
}


