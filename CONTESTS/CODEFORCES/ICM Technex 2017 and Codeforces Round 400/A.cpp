#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int n;
    string s,s1,s2, x;
    cin>>s1>>s2;
    cin>>n;
    cout<<s1<<" "<<s2<<endl;

    while(n--) {
        cin>>s>>x;
        if(s==s1)
            s1 = x;
        else if(s == s2)
            s2 = x;
    cout<<s1<<" "<<s2<<endl;

    }
}

