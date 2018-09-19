#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);  cin.tie(0);


    int t;
    cin>>t;

    string s;
    cin.ignore();

    while(t--)
    {

        getline(cin, s);
        bool last;

        for(int i=0; i<s.size(); i++)
        {
            last= true;
            int j;
            for(j = i+1; j<s.size(); j++)
            {
                if(s[j] == ' ')
                {
                    last=false;
                    break;
                }
            }
            if(!last)
            {
                cout<<(char) toupper(s[i])<<".";
                i=j;
//                while(i<j){
//
//                    cout<<(char) tolower(s[i]);
//                    i++;
//                }
                cout<<" ";
            }
            else
            {
                cout<<(char) toupper(s[i]);
                i++;
                while(i<s.size())
                {
                    cout<<(char) tolower(s[i]);
                    i++;
                }
                cout<<endl;
            }
//            i=j;
        }







    }


    return 0;

}
