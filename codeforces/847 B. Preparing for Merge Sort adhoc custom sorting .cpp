#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef unsigned long long ull;
//#define MX 200100;

const int MX = 200100;

int ara[MX], tails[MX], tails_len=0;

vector<int> ans[MX];



int get_pos(int val) {

    if(tails_len==0) {
        tails[++tails_len] = val;
        return 1;
    } else if(tails[1] < val) {
        tails[1] = val;
        return 1;
    }

    int low = 1, high= tails_len, mid = (low+high)>>1;

    while(low<high) {
        mid= (high+low)>>1;
//        printf("low %d high %d tail\n", low, high, tails[mid]);
        if(val> tails[mid]) {
            high = mid;
        } else low = mid+1;
    }
//    printf("val %d pos %d tail_pos %d\n", val, high, tails[high]);

    if(tails[high] > val) {
        tails[++tails_len] = val;
        return tails_len;
    } else {
        tails[high] = val;
        return high;
    }



}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int n;

    scanf("%d",&n);

    for(int i=1; i<=n; i++) {
        scanf("%d", &ara[i]);
    }


    for(int i=1; i<=n; i++) {
        ans[get_pos(ara[i])].push_back(ara[i]);
    }

    for(int i=1; i<=tails_len;i++ ) {
        for(int j=0; j< ans[i].size(); j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }



    return 0;
}

