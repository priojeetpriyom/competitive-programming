#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    set<int> sset;
    cin>>n;
    for(int i=1; i<=1001; i++) sset.insert(i);
    int x;
    while(n--) {
        cin>>x;
        if(sset.find(x) != sset.end())
          sset.erase(sset.find(x));
    }
    cout<< *sset.begin();
}
