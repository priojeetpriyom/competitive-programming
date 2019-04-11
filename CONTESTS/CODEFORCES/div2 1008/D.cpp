#include<bits/stdc++.h>
using namespace std;


vector<int> pre [100100];
int a,b,c;

set<pair<int, pair<int, int> > >sset;

pair<int, pair<int, int> > gett(int i, int j, int k) {
    i = pre[a][i];
    j = pre[b][j];
    k = pre[c][k];
    if(k<i)
        swap(k, i);
    if(k<j)
        swap(k, j);
    if(j<i)
        swap(j, i);
    return make_pair(i, make_pair(j, k));
}

vector<int>  precomp() {
    for(int i=1; i<=100000; i++) {
        int root = sqrt(i);
        for(int j=1; j<=root; j++) {
            if(i%j==0) {
                pre[i].push_back(j);
                if(j != i/j)
                    pre[i].push_back(i/j);
            }
        }
//        if(i<100)
//        printf("i %d pre_i %d\n", i, pre[i].size());
    }
}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(false);

    precomp();

    int t;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++)
    {

        scanf("%d %d %d", &a, &b, &c);

//    divs.push_back(pre[a]);
//    divs.push_back(pre[b]);
//    divs.push_back(pre[c]);
        int lena = pre[a].size(), lenb = pre[b].size(), lenc = pre[c].size();
        long long ans=0;

        for(int i=0; i<lena; i++) {
            for (int j = 0; j < lenb; j++) {
                for (int k = 0; k < lenc; k++) {
                    pair<int, pair<int, int> > p = gett(i, j, k);
                    if (sset.find(p) == sset.end()) {
                        sset.insert(p);
                        ans++;
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }




    return 0;

}
