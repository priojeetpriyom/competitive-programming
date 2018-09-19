#include <bits/stdc++.h>
using namespace std;
//vector<int> vec;
vector <int> vec[10001];
bool visited[10001];
int n;
bool dfs(int pos) {


    int len= vec[pos].size();
    bool temp= true;
    for(int i =0; i<len; i++) {
        if(visited[ vec[pos] [i] ] || !temp)
            return false;
        visited[ vec[pos] [i] ] = true;
        temp = dfs( vec[pos] [i] );
        visited[ vec[pos] [i] ] = false;
    }
    return temp;
}

int main()
{
//    freopen("myOut.txt", "w", stdout);
    int t;
    scanf("%d", &t);

    for(int tt=1; tt<=t; tt++) {
        string s1, s2;
        scanf("%d", &n);
        getchar();
        map<string, int> mp;
        int ass=0, temp;
        for(int i=0; i<n; i++) {

            cin>>s1>>s2;
             if(!mp[s1]) {
                mp[s1] = ass++;
             }
             if(!mp[s2]) {
                mp[s2] = ass++;
             }
//            cout<<s1<<"___________"<<s2<<"."<<endl;
             temp = mp[s2];

             vec[temp].push_back(mp[s1]);
        }

        for(int i=0; i< n; i++) {
            if(!dfs(i)) {
                temp = -1;
                break;
            }
        }
        printf("Case %d: ",tt);
        if(temp == -1)
            printf("No\n");
        else
            printf("Yes\n");
        for(int i=0; i<ass; i++)
            vec[i].clear();
    }
    return 0;
}

