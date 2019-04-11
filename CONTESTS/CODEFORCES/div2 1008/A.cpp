#include<bits/stdc++.h>
using namespace std;

bool is_vowel(char c ) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    process[0]= {1,2,3};

//    cout<<process[0].id<<" "<<process[0].at<<" "<<process[0].bt<<endl;


    // while(1) {
      string s;
      cin >> s;
      int f=1;
      for (int i = 0; i < s.size(); i++) {
          if (is_vowel(s[i]) || s[i]=='n')
              continue;
          else if (i == s.size() - 1 || !is_vowel(s[i + 1])) {
              cout << "NO" << endl;
              f=0;
              break;
          }
      }
      if(f)
      cout << "YES" << endl;
    // }
    return 0;
}
