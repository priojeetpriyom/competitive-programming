#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int t,len;
    char c;

    cin>>t;
    while(t--) {
        cin>>len;
        int f=1, cnt=0;
        while(len--) {
            scanf("\n%c", &c);
            if(c=='H') cnt++;
            else if(c=='T') cnt--;
            if(cnt>1 || cnt<0) f=0;
        }
        if(f && !cnt) printf("Valid\n");
        else printf("Invalid\n");
    }

    return 0;

}

