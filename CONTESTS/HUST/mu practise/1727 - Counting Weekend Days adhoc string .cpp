#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOutput.txt","w",stdout);

    map<string, int>mp;

    mp["JAN"] =31;
    mp["FEB"] = 28;
    mp["MAR"] = 31;
    mp["APR"] = 30;
    mp["MAY"] = 31;
    mp["JUN"] = 30;
    mp["JUL"] = 31;
    mp["AUG"] = 31;
    mp["SEP"] = 30;
    mp["OCT"] = 31;
    mp["NOV"] = 30;
    mp["DEC"] = 31;

////    mp["SUN"] = 0;
////    mp["MON"] = 1;
////    mp["TUE"] = 2;
////    mp["WED"] = 3;
////    mp["THU"] = 4;
////    mp["FRI"] = 5;
////    mp["SAT"] = 6;
//
//
//    mp["SUN"] = 1;
//    mp["MON"] = 2;
//    mp["TUE"] = 3;
//    mp["WED"] = 4;
//    mp["THU"] = 5;
//    mp["FRI"] = 6;
//    mp["SAT"] = 0;


    int tcase;
    scanf("%d",&tcase);

    while(tcase--)
    {
        string mnth,start_day;
        cin>>mnth>>start_day;

//        int starting_day = mp[start_day];
        int total_days = mp[mnth] ;
        int vacation_days = (total_days/7)*2;
        total_days%=7;
        if(start_day == "SUN")
        {
            if(total_days == 6)
                vacation_days+=1;
        }
        else if(start_day == "MON")
        {
            if(total_days == 5)
                vacation_days+=1;
            else if(total_days==6)
                vacation_days+=2;

        }
        else if(start_day == "TUE")
        {
            if(total_days == 4)
                vacation_days+=1;
            else if(total_days>=5)
                vacation_days+=2;

        }
        else if(start_day == "WED")
        {
            if(total_days == 3)
                vacation_days+=1;
            else if(total_days>=4)
                vacation_days+=2;

        }
        else if(start_day == "THU")
        {
            if(total_days == 2)
                vacation_days+=1;
            else if(total_days>=3)
                vacation_days+=2;

        }
        else if(start_day == "FRI")
        {
            if(total_days == 1)
                vacation_days+=1;
            else if(total_days>=2)
                vacation_days+=2;

        }
        else if(start_day == "SAT")
        {
            if(total_days >= 1)
                vacation_days+=1;

        }
        printf("%d\n",vacation_days);
    }

    return 0;
}
