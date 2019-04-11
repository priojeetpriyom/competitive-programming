#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



unordered_map<char, int> mp;


string s;
int len;
//int can_go(int i)
//{
//    int cnt=0;
//    while(s[i]== s[i+1])
//    {
//        cout<<s[i];
//        i++;
//        cnt++;
//    }
//    cout<<s[i];
//    cnt++;
//    if(cnt<2)
//    {
//        while(cnt<2)
//        {
//            i++;
//            cout<<s[i];
//            if(!mp[s[i] ]) cnt++;
//        }
//    }
//    return i;
//
//}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>s;

    mp['a'] =1;
    mp['e'] =1;
    mp['i'] =1;
    mp['o'] =1;
    mp['u'] =1;

    len = s.size();
    int prev_gap=0; //, prev_pass=1;
    if(len<3)
    {
        cout<<s<<endl;
    }
    else
    {
        cout<<s[0]<<s[1];

        for(int i=2; i<len; i++)
        {
            if(prev_gap)
            {
                cout<<s[i];
                prev_gap=0;
                continue;
            }
            int flag=0;

            if(mp[i]==1 || (s[i] == s[i-1] && s[i] == s[i-2]))
                flag=1;
            int cnt=0;
            for(int j=i; j>i-3; j--)
                if(!mp[s[j]])
                    cnt++;
                else break;
            if(cnt<3)
                flag=1;
//            printf("i %d cnt %d\n", i, cnt);
            if(!flag)
            {
                cout<<" ";
                prev_gap=1;
                // prev_pass=1;
            }
            else prev_gap=0;
            cout<<s[i];

        }
        cout<<endl;

    }



    return 0;
}


