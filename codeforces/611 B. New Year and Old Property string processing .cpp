#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll ara[100100];

string get_str(ll num)
{
    string ans;
    while(num>0)
    {
        ans+= (num&1) +'0';
        num>>=1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int solve(string aa, string bb)
{
    int len_a=aa.size(), len_b = bb.size();
    int cnt=0;
    string str;
//    printf("len_a %d len_b %d\n", len_a, len_b);
//    printf("a %s b %s\n", aa.c_str(), bb.c_str());
    if(len_a < len_b)
    {
        for(int i=0; i<len_a; i++) str+='1';
        str[1]='0';
        for(int i=2; i<len_a; i++)
        {
            if(str >= aa)
                cnt++;
            swap(str[i], str[i-1]);
        }
        if(str >= aa)
            cnt++;
//        printf("cnt_a %d\n", cnt);

        len_a++;

        while(len_a <len_b)
        {
            cnt+= (len_a-1);
            len_a++;
        }

    }
//     else {
//        str = aa;
//    }
    str.clear();
for(int i=0; i<len_a; i++) str+='1';
        str[1]='0';

    for(int i=2; i<len_a; i++)
    {
        if((str.size()>aa.size() || str>=aa) && str <= bb)
            {
                cnt++;

//                printf("str %s b %s\n", str.c_str(), bb.c_str());
            }
        swap(str[i], str[i-1]);
    }
    if((str.size()>aa.size() || str>=aa) && str <= bb)
        cnt++;
    return cnt;
}

int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ll a,b;
    cin>>a>>b;
    if(a==1)
    {
        if(b==1) {
            cout<<0<<endl;
            return 0;
        }
        else a++;
    }

    string str_a, str_b;
    str_a = get_str(a);
    str_b =get_str(b);

    cout<<solve(str_a, str_b);
    return 0;
}
