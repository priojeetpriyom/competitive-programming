
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main_ara[22], check_ara[22], len_ara, n, dp[21][21];

int rec(int pos_main, int pos_check) {
    if(pos_check == n+1 || pos_main==n+1) return 0;

    int &ret = dp[pos_main] [pos_check];
    if(ret!= -1) return ret;

    if(main_ara[pos_main] == check_ara[pos_check])
        ret = rec(pos_main+1, pos_check+1)+1;
    else
        ret = max(rec(pos_main, pos_check+1), rec(pos_main+1, pos_check));

    return ret;

}


int main()
{
//    freopen("out.txt", "w", stdout);
    cin>>n;
    cin.ignore();
    string s;
    bool main_input = true;
    while(getline(cin, s))
    {
        int len= s.size();
        if(len<=2)
        {
            n = atoi(s.c_str());
            getline(cin, s);
            len = s.size();
            main_input= true;
        }
//        cout<<s<<endl;
        len_ara=0;
        for(int i=0; i<len; i++)
        {

            if(s[i] >='0' && s[i]<='9')
            {
                if(main_input)
                {
//                    printf("aise i %d\n", i);
                    if(s[i+1] >='0' && s[i+1]<='9')
                    {
//                        main_ara[len_ara++] = atoi(s.substr(i,2).c_str());
                        main_ara[atoi(s.substr(i,2).c_str())] = ++len_ara;
                        i++;
                    }
                    else
//                        main_ara[len_ara++] = atoi(s.substr(i,1).c_str());
                        main_ara[atoi(s.substr(i,2).c_str())] = ++len_ara;
                }
                else
                {
                    if(s[i+1] >='0' && s[i+1]<='9')
                    {
                        check_ara[atoi(s.substr(i,2).c_str())] = ++len_ara;
                        i++;
                    }
                    else
                        check_ara[atoi(s.substr(i,1).c_str())] = ++len_ara;
                }
            }

        }
//        printf("printing\n");
//        for(int i=1; i<=n; i++)
//            printf("%d ", main_ara[i]);
//        printf("\n");
//        for(int i=1; i<=n; i++)
//            printf("%d ", check_ara[i]);
//        printf("\n");


        if(!main_input) {
            memset(dp, -1, sizeof dp);
            printf("%d\n", rec(1,1));
        }

        main_input = false;
//        printf("len_ara %d\n", len_ara);
//    cin.ignore();
        s.clear();
    }


    return 0;
}

