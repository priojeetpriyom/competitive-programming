#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int consucative(string s, int len, int k)
{
    int cnt=0;
    for(int i = len-1; i>=0; i--)
    {
        if(s[i] != '0')
            break;
        cnt++;
    }
//    printf("%s cnt %d\n",s.c_str(), cnt);
    return (cnt>=k);
}


int main()
{
    int n,k;
    string s;
    cin>>s>>k;
//    cout<<s<<"  "<<k<<endl;
    n = atoi(s.c_str());

    int pw = pow(10, k);
    int cnt=0;
    if(n<pw)
    {
        cout<<s.length()-1;
        return 0;
    }




    for(int i = s.length()-1; n>0; i = s.length()-1)
    {
//        cout<<s<<endl;
        if(consucative(s, s.length(), k))
        {
            break;
        }
        else
        {
            for(int i = s.length()-1; i>=0; i--)
            {
                if(s[i] != '0')
                {
                    cnt++;
//                    printf("oka1\n");
                    s.erase(i, 1);
//                    printf("oka2 %s\n", s.c_str());
                    n  = atoi(s.c_str());
                    break;
                }
            }
        }
    }

    if(n==0)
        cnt+= s.length() -1;

    cout<<cnt;
    return 0;
}
