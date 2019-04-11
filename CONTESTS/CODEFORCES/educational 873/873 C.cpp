#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ara[111][111];




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m ,k;
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>ara[i][j];
        }
    }
    int score=0, rem=0;
//    int cum[111];
    for(int j=1; j<=m; j++) {
        int mx=0, ttl=0, mx_id=1;
        for(int i=1; i<=n-k+1; i++) {
            int cnt=0;
            for(int p =i; p<i+k; p++) {
                if(ara[p][j])
                    cnt++;
            }
            if(cnt>mx) {
                mx = cnt;
                mx_id = i;
            }
//            cum[i] = cnt;
        }

        for(int i=1; i<mx_id; i++)
        {
            if(ara[i][j])
                rem++;
        }
//        printf("j %d ttl %d mx %d\n", j, ttl, mx);
        score+= mx;
//        rem += (ttl-mx);
    }


    cout<<score<<" "<<rem<<endl;

    return 0;
}


