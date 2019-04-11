#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


//struct node {
//    int price, cnt=0;
//};

int n, x, y, m;
vector<int> vec , p;
set<pair<int, int> > sset[5];
//struct node cnt[100100];
bool used[200100];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        p.push_back(x);
//        cnt[x]+=2;
//        mp[x]+=2;
    }

//sset[0].i
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        vec.push_back(x);
    }


    for(int i=0; i<n; i++) {
        scanf("%d", &x);

        sset[vec[i]].insert(make_pair(p[i], i));
        sset[x].insert(make_pair(p[i], i));

    }
//    cout<<typeid(sset[x]).name();

//    for(int i=1; i<=3; i++) {
//        sort(vec[i].begin(), vec[i].end() );
//    }

    scanf("%d", &m);

    while(m--) {
        scanf("%d", &x);

//        while(vec[x].size() && mp[ vec[x][0] ]<=0) {
//            vec[x].erase(vec[x].begin());
//        }


            if(!sset[x].size()) {
                printf("-1 ");
                continue;
            }

            set<pair<int, int> >:: iterator temp = sset[x].begin();
            pair<int, int > temp_p = *temp;

            while(used[temp_p.second] && temp!= sset[x].end()) {
                sset[x].erase(temp);
                temp =sset[x].begin();
                temp_p = *temp;
            }


        if(!sset[x].size()) {
            printf("-1 ");
        } else {
            printf("%d ", temp_p.first);
            used[temp_p.second] =1;
//            cout<<
        }
    }
        printf("\n");

    return 0;
}


