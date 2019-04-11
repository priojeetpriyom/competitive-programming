#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int get_next(int n) {

    string s;

    do {
        s+= (n%10)+'0';
        n/=10;
    }while(n>0);

    reverse(s.begin(), s.end());
    for(int  i=0; i<s.size(); i++) {
        if(s[i]> '0') {
            int j = i;
            while(j>=0 && s[j]=='9') {
                j--;
            }
            if(j<0) {
//                cout<<s<<endl;
                string t;
                t +='1';
                s = t+s;
//                printf("aise\n");
            } else s[j]++;

            for(j = max(j+1,1 ); j<s.size(); j++)
                s[j]='0';
        }
        break;
    }
//    cout<<s<<endl;
    return atoi(s.c_str());


}



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;

    cin>>n;

    cout<<get_next(n) - n;

    return 0;
}


