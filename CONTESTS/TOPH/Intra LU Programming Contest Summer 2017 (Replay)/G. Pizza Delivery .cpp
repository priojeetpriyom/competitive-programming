#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



vector < pair<int, pair<int, int> > >vec(100100);


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin>>n;

    for(int i=0; i<n; i++) {
        scanf("%d", & vec[i].second.first);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &vec[i].second.second);
//        vec[i].first = vec[i].second.first+ vec[i].second.second;
        vec[i].first = vec[i].second.first;
    }

    sort(vec.begin(), vec.begin()+n);


    int ans=vec[0].second.first+vec[0].second.second;
//    int prev = vec[0].first;
    int chef =vec[0].second.first;

    for(int i=1; i<n; i++) {
        chef+= vec[i].second.first;
        ans += max(0, chef - ans);
        ans += vec[i].second.second;

    }

    printf("%d\n", ans);




    return 0;
}
