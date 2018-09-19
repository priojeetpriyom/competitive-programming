/*
  idea: if we pre calculate all possible outcomes all queries it will take
  (1<<13)^2 complexity. then we can answer each query in O(1) time

*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)

#define cin0(n, ara) for(int i=0; i<n; i++) {cin>>ara[i];}
#define cini0(i, n, ara) for(int i=0; i<n; i++) {cin>>ara[i];}

#define cin1(n, ara) for(int i=1; i<=n; i++) {cin>>ar[i];}
#define cini1(i, n, ara) for(int i=1; i<=n; i++) {cin>>ar[i];}



#define MX 500100
#define double long double
#define mod 1000000007
#define mod2 1000000009

vector<int> query[1<<13] [105];
ll cost[15], fre[1<<13];


int can[1<<13][105];
int ans[MX];

int get_decimal(char str[], int len);


void pre_process(int n);

int get_cost(int i, int j, int n);

int main()
{
//    double time = clock();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n, m ,q;

//    memset(dp, -1, sizeof dp);
    scanf("%d %d %d", &n, &m, &q);

    for(int i=0; i<n; i++)
        scanf("%lld", &cost[i]);

    char str[100];
    for(int i=0; i<m; i++) {
        scanf("\n%s", str);
        int num = get_decimal(str, strlen(str));
        fre[num]++;
//        cout<<"num "<<num<<" fre "<<fre[num]<<endl;
    }

    int k;
    for(int i=0; i<q; i++) {
        scanf("\n%s %d", str, &k);
        int num = get_decimal(str, strlen(str));
        query[num] [k].push_back(i);
    }

    pre_process(n);

    for(int i=0; i<q; i++) {
        printf("%d\n", ans[i]);
    }


//    cout<<(clock()-time)/CLOCKS_PER_SEC;

    return 0;
}
void pre_process(int n) {

    for(int i=0; i<(1<<n); i++) {
        int sum=0;
        for(int j=0; j<(1<<n); j++) {
            sum= get_cost(i, j, n);
            if(sum>100)
                continue;
            can[i] [sum]+= fre[j];
        }

        sum=0;
        for(int k=0; k<=100; k++) {
            sum+= can[i][k];
            for(int q : query[i][k])
                ans[q] = sum;
        }
    }
}

int get_cost(int a, int b, int n) {
    int sum=0;
    for(int i=0; i<n; i++)
        if((a&(1<<i))==(b&(1<<i)))
            sum+= cost[i];
//    cout<<"a "<<a<<" b "<<b<<" cost "<<sum<<endl;
    return sum;
    }

int get_decimal(char str[], int len) {
    int num=0;
    for(int i=0; i<len; i++)
        if(str[i]=='1')
            num = num | (1<<i);

    return num;
}
