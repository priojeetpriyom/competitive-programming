#include<bits/stdc++.h>

using namespace std;
typedef long long ll;



int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int t;
    cin>>t;

    string s;
    while(t--) {
        cin>>s;
        int ans=1;

        int len = s.size();

        for(int i=0; i<len; ) {
//            if(s[i] =='C') {
                while(s[i]=='C' && i<len) i++;
                while(s[i]=='E' && i<len) i++;
                while(s[i]=='S' && i<len) i++;

//            }

            if(i!=len) ans=0;
            break;
        }
        if(ans) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}

