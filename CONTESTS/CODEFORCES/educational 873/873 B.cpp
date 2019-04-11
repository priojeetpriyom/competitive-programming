#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
int len;

bool valid(int part) {
    if(!part) return true;
    int cnt=0;
    for(int i=0; i<part; i++) {
        cnt+= ( (s[i]=='1')? 1:-1 );
    }
    if(!cnt) return true;
//    printf("cnt %d part %d\n", cnt, part);
    for(int i=part; i<len; i++) {

        cnt= cnt- ( (s[i-part]=='1')? 1:-1 );
        cnt+= ( (s[i]=='1')? 1:-1 );
//        printf("i %d cnt %d\n", i, cnt);
        if(!cnt) return true;
    }

    return false;


}

int bin(int low, int high) {

    int mid = (high+low)/2;

    while(low<high-1) {
        mid = (high+low)/2;
        if(mid&1) mid--;
//        printf("high %d low %d mid %d\n", high, low, mid);
        if(valid(mid)) low = mid+1;
        else high = mid-1;
    }
    if(!valid(low)) low--;

    return low;

}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

//    int len;
    cin>>len>>s;
    if(valid(len)) {
        cout<<len<<endl;
        return 0;
    }
    cout<<bin(0, len)<<endl;



    return 0;
}


