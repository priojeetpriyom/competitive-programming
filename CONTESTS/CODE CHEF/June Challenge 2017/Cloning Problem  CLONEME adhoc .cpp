#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cnt_ara[1111], vis[1111], v=1, ara[100100];


int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);


    int t;
    scanf("%d", &t);
    int n,q;
    int a,b,c,d, len;
    while(t--) {

        scanf("%d %d",&n, &q );


        for(int i=1; i<=n; i++) {
            scanf("%d", &ara[i]);
        }


        while(q--) {
            v++;
            scanf("%d %d %d %d", &a, &b, &c, &d);


            vector<int> temp (ara+a, ara+b+1), temp2(ara+c, ara+d+1);
            sort(temp.begin(), temp.end());
            sort(temp2.begin(), temp2.end());
            int diff=b-a, len = temp.size();


            for(int i=0; i<len; i++) {
                if(vis[ temp[i] ] == v) {
                    cnt_ara[ temp[i] ]++;

                } else {
                    vis[ temp[i] ] = v;
                    cnt_ara[ temp[i] ] =1;
                }
            }

            for(int i = 0; i<len; i++) {
                if(vis[ temp2[i] ] && cnt_ara[ ara[i] ] ) {
                    cnt_ara[ ara[i] ]--;
                    diff--;
                }
            }

            if(diff<2) printf("YES\n");
            else printf("NO\n");
        }

    }


    return 0;
}





