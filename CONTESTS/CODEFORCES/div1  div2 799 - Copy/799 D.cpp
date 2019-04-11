#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, a,b, h,w;
vector<ll> vec;
vector<ll>:: iterator it;



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    cin>>a>>b>>h>>w>>n;
    int x;
    for(int i=0; i<n; i++) {
        scanf("%I64d", &x);
        vec.push_back(x);
    }

    sort(vec.begin(), vec.end());

    int cnt=0;

    x = ceil((double)a / h);
//    printf("x %d\n", x);
    while(x>1) {
        it = lower_bound(vec.begin(), vec.end(), x);
//        printf("x %d *it %d h %d\n", x, *it, h);
        if(!vec.size()) {
            printf("-1\n");
            return 0;
        }
        if(it == vec.end()) it--;
        cnt++;
        h *= *it;
        x = ceil((double)a / h);
//        printf("h_now %d x_now %d\n", h, x);
        *it=0;
        vec.erase(it);

    }

//    printf("x_after_a %d vec_size %d\n", x, vec.size());
//    for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
//    cout<<endl;

    x = ceil((double)b / w);

    while(x>1) {
        it = lower_bound(vec.begin(), vec.end(), x);
//        printf("x %d *it %d w %d\n", x, *it, w);
        if(!vec.size()) {
            printf("-1\n");
            return 0;
        }
        if(it == vec.end()) it--;
        cnt++;
        w *= *it;
        x = ceil((double)b / w);
//        printf("w_now %d x_now %d\n", w, x);
        vec.erase(it);

    }

    printf("%d\n", cnt);
    return 0;
}


