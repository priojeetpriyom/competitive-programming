#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin>>a>>b;

    int cnt=1;

    while(1) {
        if(cnt%2==1) {
            if(a<cnt) break;
            a-=cnt;
        } else {
            if(b<cnt) break;
            b-=cnt;
        }
        cnt++;
    }

//    printf("cnt %d\n", cnt);
    if(cnt%2==1) printf("Vladik\n");
    else printf("Valera\n");


    return 0;
}


