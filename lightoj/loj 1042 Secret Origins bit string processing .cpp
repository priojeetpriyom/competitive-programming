#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;


//bool allOne()
//{
//
//    for(int i=s.size(); i>=0; i--)
//    {
//        if(s[i]=='0')
//            return false;
//    }
//    return true;
//}
//
//bool allZero()
//{
//
//    for(int i=s.size(); i>0; i--)
//    {
//        if(s[i]=='1')
//            return false;
//    }
//    return true;
//
//}

void print()
{
    int ans=0, pw=1;
    for(int i = s.size()-1; i>=0; i--)
        ans+= (s[i]-'0')*pw, pw<<=1;

    printf("%d\n", ans);

}

int main()
{
    char c;
    int t;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++)
    {
        int n;
        scanf("%d", &n);
        printf("Case %d: ", tc);

        bitset<32> bin(n);

        s = bin.to_string();
        for(int i=0; i<s.size(); i++)
            if(s[i]!='0')
            {
                s = s.substr(i);
                break;
            }
//        cout<<endl<<s<<endl;

//        if(allOne())
//        {
//            s.insert(1, "0", 1);
//            print();
//        }
//        else if(allZero())
//        {
//            s.pop_back();
//            print();
//        }
//        else
        {
            bool done = false;
            for(int i = s.size()-2; i>0; i--)
            {
                if(s[i]=='0' && s[i] != s[i+1])
                {
                    swap(s[i], s[i+1]);
                    done = true;


                    while(++i<s.size())
                    {
                        if(s[i]=='1')
                        {
                            for(int j = s.size()-1; j>i; j--)
                            {
                                if(s[j]=='0')
                                {
                                    swap(s[i], s[j]);
                                    break;
                                }
                            }
                        }
//                        i++;
                    }

                    break;
                }
            }
            if(!done)
            {
                s.insert(1, "0", 1);
                int i=1;
                    while(++i<s.size())
                    {
                        if(s[i]=='1')
                        {
                            for(int j = s.size()-1; j>i; j--)
                            {
                                if(s[j]=='0')
                                {
                                    swap(s[i], s[j]);
                                    break;
                                }
                            }
                        }
//                        i++;
                    }
            }
//            cout<<s<<endl;

            print();

        }


    }



    return 0;
}
