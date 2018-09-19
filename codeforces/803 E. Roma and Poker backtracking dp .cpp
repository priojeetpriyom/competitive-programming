#include<bits/stdc++.h>

using namespace std;


int dp[1001] [1001];
string s;;
int len;
int k;
vector<char> path;

void rec(int pos, int cnt)
{
//    printf("pos %d cnt %d last %c\n", pos, cnt, (path.size())? path[path.size()-1]:65 );
    if(pos == len && abs(cnt) == k)
    {
        for(int i=0; i<len; i++) printf("%c", path[i]);
        printf("\n");
        exit(0);
    }
    if( len-pos < k- abs(cnt) || abs(cnt)==k) return ;

    int &ret = dp[pos] [cnt];

    if(ret != -1) return;
    ret =1;

    if(s[pos] == '?')
    {
        path.push_back('L');
        rec(pos+1, cnt-1);
        path.pop_back();
        path.push_back('W');
        rec(pos+1, cnt+1);
        path.pop_back();
        path.push_back('D');
        rec(pos+1, cnt);
        path.pop_back();
    }
    else if(s[pos] == 'L')
        {
        path.push_back('L');
            rec(pos+1, cnt-1);
        path.pop_back();
        }
    else if(s[pos] == 'W')
        {
        path.push_back('W');
            rec(pos+1, cnt+1);
        path.pop_back();
        }
    else
        {
        path.push_back('D');
            rec(pos+1, cnt);
        path.pop_back();
        }


}


int main()
{
    memset(dp, -1, sizeof dp);
    cin>>len>> k;
    cin.ignore();
    cin>>s;
//    cout<<s<<endl;

    rec(0,0);
    printf("NO\n");

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);


}

