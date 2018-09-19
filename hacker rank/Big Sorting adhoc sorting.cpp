#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string str [200100];

bool cmp(string s1, string s2) {
//    cout<<"s1 "<<s1<<" len "<<s1.length()<<" s2 "<<s2<<" len "<<s2.length()<<" returned "<<((s1.length() <= s2.length()) && (s1<s2))<<endl;
    return ((s1.length()< s2.length()) || (s1.length() == s2.length()) && (s1<s2));
}

int main()
{
//        freopen("out.txt", "w", stdout);

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>str[i];

    sort(str, str+n, cmp);

    for(int i=0; i<n; i++)
        cout<<str[i]<<endl;

    return 0;
}



