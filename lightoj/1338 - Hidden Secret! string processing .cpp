#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

string process(string s)
 {
     string temp = s;
     s.clear();
      int len = temp.size();
     for(int i=0; i<len; i++) {
        temp[i] = tolower(temp[i]);
        if(temp[i]>='a' && temp[i]<='z') s+=temp[i];
     }

     sort(s.begin(), s.end());
//     cout<<s<<endl;
     return s;
 }

int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);


    int t;
    scanf("%d", &t);
    string s1, s2;
    cin.ignore();
    for(int tc=1; tc<=t; tc++) {
        getline(cin, s1);
        getline(cin, s2);
//        cout<<s1<<endl<<s2<<endl;
        s1 = process(s1);
        s2 = process(s2);
        if(s1 == s2)   printf("Case %d: Yes\n", tc);
        else printf("Case %d: No\n", tc);
    }




    return 0;

}

