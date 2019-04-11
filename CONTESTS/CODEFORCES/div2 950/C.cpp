#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 200100

string s;
vector<int>can_zero, can_one;
vector<int> path[MX];
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>s;
    int len = s.size();
    char last='1';
    int len_path=1;
    for(int i=0; i<len; i++) {
        if(s[i]== '1') {
            if(can_one.size()==0)
            {
//                printf("ghapla\n");
                cout<<-1<<endl;
                return 0;
            }
            int pos=  can_one[can_one.size()-1];
            path[pos].push_back(i+1);
            can_zero.push_back(pos);
            can_one.pop_back();
        } else {
            if(can_zero.size()>0) {
                int pos = can_zero[can_zero.size()-1];
//                if(path[pos].size()<3) {
                    path[pos].push_back(i+1);
                    can_one.push_back(pos);
                    can_zero.pop_back();
                    continue;
//            }
            }
                path[len_path].push_back(i+1);
                can_one.push_back(len_path);
                len_path++;

        }
    }
//    for(int i=1; i<len_path; i++) {
//        for(int j=0; j<path[i].size(); j++)
//            printf("%d ", path[i][j]);
//        printf("\n");
//            }
//    for(int i=1; i<len_path; i++) {
//            if(path[i].size()==2) {
//                cout<<-1<<endl;
//                return 0;
//
//            }
//            }


    if(can_zero.size()) {
        cout<<-1<<endl;
    } else
        {
            cout<<len_path-1<<endl;
            for(int i=1; i<len_path; i++) {
                cout<<path[i].size();
                for(auto p: path[i])
                    cout<<" "<<p;
            cout<<endl;
            }
        }



    return 0;
}


