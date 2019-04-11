#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


bool palindrom(int a, int b) {
    int n=0;
    int x=a;
    do {
        n = n*10 + (a%10);
        a/=10;

    } while(a>0);
    if(n<10 && x<10 ) n*=10;
//    printf("hh %d mm %d n_hh %d\n", x, b, n);

    return n==b;
}


int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int hh, mm;
    char c;
    cin>>hh>>c>>mm;
    int cnt=0;
    while(!palindrom(hh, mm) ) {
        mm++;
        if(mm>=60) hh++;
        mm%=60;
        hh%=24;
        cnt++;

    }
    cout<<cnt<<endl;


    return 0;
}


