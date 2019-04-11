#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


vector<pair<int, int > > b(200100);
vector<int> a(200100), ans(200100);


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int m;
    scanf("%d", &m);
    int x;

    for(int i=0; i<m; i++) {
        scanf("%d", &a[i]);
//        printf("%d, ", a[i]);
    }
    for(int i=0; i<m; i++) {
        scanf("%d", &b[i].first);
        b[i].second = i;
    }

    sort(b.begin(), b.begin()+m);
    sort(a.begin(), a.begin()+m);

//    for(int i=0; i<m; i++) {
//
//        printf("%d, ", a[i]);
//    }

    for(int i=0; i<m; i++)
        ans[ b[i].second ] = a[m-i-1];


    for(int i=0; i<m; i++)
        printf("%d ", ans[i]);

    printf("\n");



    return 0;
}


