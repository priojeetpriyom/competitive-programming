#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string to_string_s(int n)
{
    char c[10];
    c[0] = n+'0';
    c[1] = '\0';
    string s(c);
    return s;
}

int main()
{
//    freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    int n;
    char str[10];
    int len;
    while(scanf("%d", &n)==1) {
        int x=1;
        map<string, int> mp;
        for(int i=1; i<=n; i++) {
            scanf("\n%s", str);
//            printf("%s\n",str);
            printf("Instruction %d: ",i);
            len = strlen(str);
            int x = str[0]-'0';
            int y = str[2] - '0';
            char operation = str[1];
            string s,s2;
            if(operation == '+') {
                s += "add "+to_string_s(x)+" to "+  to_string_s(y);
                s2 += "add "+to_string_s(y)+" to "+to_string_s(x);

                if(mp.find(s)!= mp.end()) {
                    cout<<"repeat step "<<mp[s]<<endl;

                } else if(mp.find(s2)!= mp.end()) {
                    cout<<"repeat step "<<mp[s2]<<endl;

                } else {
                    mp[s] = x;
                    mp[s2] = x;
                    cout<<s<<endl;
                    x++;
                }

            } else if(operation == '-') {
                s += "subtract "+to_string_s(y)+" from "+to_string_s(x);

                if(mp.find(s)!= mp.end()) {
                    cout<<"repeat step "<<mp[s]<<endl;

                } else {
                    mp[s] = x;
                    cout<<s<<endl;
                    x++;
                }


            } else if(operation == '*') {
                s += "multiply "+to_string_s(x)+" with "+to_string_s(y);
                s2 += "multiply "+to_string_s(y)+" with "+to_string_s(x);

                if(mp.find(s)!= mp.end()) {
                    cout<<"repeat step "<<mp[s]<<endl;

                } else if(mp.find(s2)!= mp.end()) {
                    cout<<"repeat step "<<mp[s2]<<endl;

                } else {
                    mp[s] = x;
                    mp[s2] = x;
                    cout<<s<<endl;
                    x++;
                }

            } else {
                s += "divide "+to_string_s(x)+" by "+to_string_s(y);

                if(mp.find(s)!= mp.end()) {
                    cout<<"repeat step "<<mp[s]<<endl;

                } else {
                    mp[s] = x;
                    cout<<s<<endl;
                    x++;

                }
            }
        }

        mp.clear();

    }

    return 0;


}



