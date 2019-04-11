#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int len;
    cin>>len;
    int f=0;
    for(int i=0; i<len; i++) {
        if(f==4) f=0;
        if(f<2) {
            printf("a");
            f++;
        } else if(f<4) {
            printf("b");
            f++;
        }
    }
    return 0;
}


