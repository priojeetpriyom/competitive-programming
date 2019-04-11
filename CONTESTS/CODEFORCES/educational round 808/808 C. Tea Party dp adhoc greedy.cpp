#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

    int ans[100100];

    vector <pair<int, pair<int, int> > > vec;

    bool cmp(pair<int, pair<int, int> >  a, pair<int, pair<int, int> > b) {
        return a.second.first < b.second.first;
    }



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
int n,w;
    cin>>n>>w;
    int check=0, cum=0, x;
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        vec.push_back(make_pair(x, make_pair(i, round((double) x/2))));
//        cum+=x;
        w -= round((double) x/2);
    }
    if(w<0) {
        printf("-1\n");
        return 0;
    }

    sort(vec.begin(), vec.end());

    for(int i = vec.size()-1; i>=0; i--) {
        if(w>= vec[i].first - vec[i].second.second) {
            w-= vec[i].first - vec[i].second.second;
            vec[i].second.second = vec[i].first;
        } else{

            vec[i].second.second += w;
             break;
        }
    }
    sort(vec.begin(), vec.end(), cmp);

    for(int i=0; i<n; i++) printf("%d ", vec[i].second.second);
    printf("\n");
    return 0;
}


