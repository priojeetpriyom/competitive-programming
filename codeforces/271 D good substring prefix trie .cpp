#include <bits/stdc++.h>

using namespace std;

set<string> uset;
string s;

bool good[200];

struct node {
    node *next[27];

    node() {
        memset(next, 0, sizeof next);
    }


};


int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
//    cout<<s<<endl;
    string temp;
            cin>>temp;
    for(int i=0; i<26; i++)
        {
            good[i+'a'] = temp[i]-'0';
        }





//    for(int i = 'a'; i<= 'z'; i++)
//        cout<<good[i]<<" "; cout<<endl;
    int k;
    cin>>k;

    int len = s.size();
    int ans=0;
    node *root = new node();

    for(int i=0; i<len; i++) {
        node *cur = root;
        int cnt = 0;
        int j;
//    printf("aise\n");

        for(  j =i; j<len && cnt+(!good[ s[j] ])<=k ; j++ ) {
            char c = s[j]-'a';
            cnt += (!good[s[j]]);
            if(cur->next[c] == NULL) {

                ans++;
                cur->next[c] = new node();
            }
                cur = cur->next[c];
//        printf("i %d j %d ans %d\n", i, j, ans);
        }

    }
//    for(unordered_set<string>:: iterator it=uset.begin(); it!= uset.end(); it++) cout<<*it<<","; cout<<endl;

    cout<<ans<<endl;


    return 0;
}

