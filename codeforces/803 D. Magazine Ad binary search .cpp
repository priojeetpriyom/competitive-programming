#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


    int mx_diff = -1, k;


string s;
    vector<int> vec;

bool solve(int len) {

    int cnt=0, cur_pos=0;

    if(vec[0]> len) return false;
    for(int i=0; i<vec.size()-1 && cnt<=k; i++) {
        if(vec[i+1]-cur_pos> len) {
            cur_pos=vec[i];
//            if(len==10) printf("cur_pos %d\n", cur_pos);
            cnt++;
//            if(cur_pos == vec[vec.size()-2]) break;
//            else if(len==10) printf("cur_pos %d vec %d\n", cur_pos, vec[vec.size()-2]);
        }
    }
//    printf("len %d cnt %d\n", len, cnt);
    return cnt<=k;

}




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);


    int  len;
    cin>>k;
    cin.ignore();
    getline(cin, s);

    len = s.size();

    for(int i=0; i<len; i++)
    {
        if(s[i]==' ' || s[i]=='-')
        {
            vec.push_back(i+1);
            if(vec.size()>1) {
                mx_diff = max(mx_diff, vec[vec.size()-1] - vec[vec.size()-2]);
            }
//            printf("%d ", vec[vec.size()-1]);
        }
    }
    vec.push_back(len);
    vec.push_back(1e9);
//    printf("%d\n", vec[vec.size()-1]);

    int apprx, pos=0;
    vector<int> :: iterator it;
    int low=1, high=1e6, ans= 1e6;
    while(low<=high)
    {
        apprx = (low+high)>>1;
        if(apprx>=mx_diff && solve(apprx) ) {
            ans = min(ans, apprx);
            high = apprx-1;
        } else low = apprx+1;


    }
//    printf("\n");
    printf("%d\n", ans);



    return 0;
}


