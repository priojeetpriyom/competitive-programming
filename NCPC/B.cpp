#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int, string> mp;
map<string, int> months;
int main()
{
//    freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    mp[1*31 + 13] = "Pohela Falgun";
    mp[1*31 + 14] = "Valentine's Day";
    mp[1*31 + 21] = "International Mother Language Day";
    mp[2*31 + 8] = "International Women's Day";
    mp[2*31 + 21] = "International Color Day";
    mp[2*31 + 26] = "Bangladesh Independence Day";
    mp[3*31 + 1] = "April Fools Day";
    mp[3*31 + 14] = "Pohela Boishakh";
    mp[4*31 + 1] = "May Day";
    mp[5*31 + 19] = "Father's Day";
    mp[6*31 + 18] = "Mandela Day";
    mp[7*31 + 20] = "World Mosquito Day";
    mp[9*31 + 31] = "Halloween";
    mp[10*31 + 19] = "World Toilet Day";
    mp[11*31 + 10] = "Human Rights Day";
    mp[11*31 + 16] = "Victory Day of Bangladesh";
    mp[11*31 + 25] = "Christmas Day";


    mp[15*31 + 13] = "Pohela Falgun";


    months["January"] = 0;
    months["February"] = 1;
    months["March"] = 2;
    months["April"] = 3;
    months["May"] = 4;
    months["June"] = 5;
    months["July"] = 6;
    months["August"] = 7;
    months["September"] = 8;
    months["October"] = 9;
    months["November"] = 10;
    months["December"] = 11;





    int t;
    cin>>t;
    string  month;
    int day;
    cin.ignore();
    for(int tc=1; tc<=t; tc++) {
        cin>>month>>day;

        int num = months[month]*31 + day+1;

        printf("Case %d: ", tc);
//        if(mp.find(num) != mp.end()) {
//            cout<<mp[num]<<endl;
//        } else
//            {

                for(; ; num++) {
                    if(mp.find(num) != mp.end()) {
                        cout<<mp[num]<<endl;
                        break;
        }
                }
//            }
    }

    return 0;


}

