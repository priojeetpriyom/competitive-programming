#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cur=0;
    int n, s,d;

    cin>>n;
//    int nn = n;
    n--;
    cin>>cur>>d;
    cur++;

    while(n--) {
        cin>>s>>d;
        if(s>=cur) {
            cur = s+1;
        } else {
            int x = (cur-s)/d;
//                printf("s %d d %d x %d cur %d\n", s,d,x, cur);
            if(!( (cur-s) == d*x )) {
//                printf("aise\n");
                x++;
                cur = s + (d*x)+1;
            } else cur++;


        }

//        cout<<cur<<endl;

    }

    cout<<cur-1<<endl;



    return 0;
}


