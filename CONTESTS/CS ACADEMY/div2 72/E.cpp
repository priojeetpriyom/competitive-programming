#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//typedef unsigned long long ull;
#define MX 100100

vector<int> query[MX];
set<int> sorter;
unordered_map<int, int> mp;
ll tree[MX*10];
int lim;

void update(int idx, int val) {
    while(idx<= lim) {
        tree[idx]+=val;
        idx += (idx & -idx);
    }
}

ll Query(int idx) {
    ll sum=0;
    while(idx!=0) {
        sum+= tree[idx];
        idx-= (idx & -idx);
    }
    return sum;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin>>q;
    for(int i=1; i<=q; i++) {
        int x, l1, r1, l2, r2;
        cin>>x;
        query[i].push_back(x);
        if(x==3) {
            cin>>l1>>r1>>l2>>r2;
            query[i].push_back(l1);
            query[i].push_back(r1);
            query[i].push_back(l2);
            query[i].push_back(r2);
            sorter.insert(l1);
            sorter.insert(r1);
            sorter.insert(l2);
            sorter.insert(r2);
            continue;
        }

            cin>>l1>>r1;
            query[i].push_back(l1);
            query[i].push_back(r1);
            sorter.insert(l1);
            sorter.insert(r1);
    }
    int idx=0;

    for(auto i : sorter) {
        mp[i] = ++idx;
    }
//    idx--;
    lim = idx;
    for(int i=1; i<=q; i++) {
        for(int j=1; j< query[i].size(); j++) {
            query[i][j] = mp[ query[i][j] ];
        }
    }

    for(int i=1; i<=q; i++) {
    printf("i %d queryi0 %d\n", i, query[i][0]);
        int l1,r1, l2,r2;
        l1 = query[i][1];
        r1 = query[i][2];
        if(query[i][0]==1) {
            update(l1, 1);
//            update(r1+1, -1);
            printf("add 1to%d : %d\n",r1, Query(r1));
        } else if(query[i][0]==2) {
            update(l1, -1);
//            update(r1+1, 1);
            printf("rm 1to%d : %d\n",r1, Query(r1));
        }  else if(query[i][0]==3) {
            l2 = query[i][3];
            r2 = query[i][4];
            if(l1>l2 || (l1==l2 && r1>r2)) {
                swap(l1, l2);
                swap(r1, r2);
            }

                if(l1==l2 && r1==r2) {
                    cout<<0<<endl;
                } else if(l1>r2 || r1<l2) {
                    cout<<1<<endl;
                } else {
//                    printf("i %d ")
                    ll cnt = max(Query(min(l1, l2)-1), Query(idx)- Query(max(r1,r2)));
//                    cnt = max(cnt, )
                    if(cnt>0) {
                        cout<<2<<endl;
                    } else
                        cout<<-1<<endl;
                }
//        printf("i %d is query\n", i);
        }
//            printf("i %d l %d tree[l] %d\n",i, l1 , tree[l1] );


    }


    return 0;
}


