#include<bits/stdc++.h>
using namespace std;

map<string, int> mp;
string s;

int main()
{
//    freopen("myOut.txt", "w", stdout);
    s = 'a';
    int len =1;
    for(int i=1; i<=83681; i++)
    {
//        if(s[len-1] == 'z')
//        {
            if(s[len-1] > 'z')
            {
//                string c = (char) (s.at(0)+1);
//                s.replace(0, 1, s[0]+1);
                bool expand = true;
//                s[len-2]++;
                for(int j = len-2; j>=0; j--) {
                    if((s[j]+1 )+ (len-j-1) <= 'z' ) {
                        s[j]++;
                        expand = false;
                        for(j = j+1; j<len; j++) {
                            s[j] = s[j-1]+1;
                        }
                        break;
                    }
                }
//                s[0]++;
                if(expand) {
                    s.resize(0);
                    len++;
                    for(int j=0; j<len; j++)
                        s+=('a'+j);
                }
//                else {
//
//                    for(int j=1; j<len; j++) {
//                        s[j] = s[j-1]+1;
////                        s.replace(j, 1, s.at(j)+1);
//                    }
//                }

            }

//        }
//            printf("sting %s val %d\n", s.c_str(), i);
            mp[s] = i;
            s[len-1]++;
//            s.replace(len-1, 1, s.at(len-1)+1);
    }

    while(cin>>s)
    {
        if(mp.find(s) == mp.end())
            cout<<0<<"\n";
        else
            cout<<mp[s]<<endl;
    }
    return 0;

}


