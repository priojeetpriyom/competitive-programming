#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>
#include <string>
#include <stdlib.h>
//#define N 1000000

using namespace std;

int main()
{
    int holidays,tcase,total_days,running_day;
    char mnth[10],day[10];
    scanf("%d\n",&tcase);
    while(tcase--)
    {
        scanf("%s %s",mnth,day);
        if(strcmp(mnth,"JAN")==0)
            total_days=31;
        else if(strcmp(mnth,"FEB")==0)
            total_days=28;
        else if(strcmp(mnth,"MAR")==0)
            total_days=31;
        else if(strcmp(mnth,"APR")==0)
            total_days=30;
        else if(strcmp(mnth,"MAY")==0)
            total_days=31;
        else if(strcmp(mnth,"JUN")==0)
            total_days=30;
        else if(strcmp(mnth,"JUL")==0)
            total_days=31;
        else if(strcmp(mnth,"AUG")==0)
            total_days=31;
        else if(strcmp(mnth,"SEP")==0)
            total_days=30;
        else if(strcmp(mnth,"OCT")==0)
            total_days=31;
        else if(strcmp(mnth,"NOV")==0)
            total_days=30;
        else if(strcmp(mnth,"DEC")==0)
            total_days=31;
        if(strcmp(day,"SAT")==0)
            running_day=1;
        else if(strcmp(day,"SUN")==0)
            running_day=2;
        else if(strcmp(day,"MON")==0)
            running_day=3;
        else if(strcmp(day,"TUE")==0)
            running_day=4;
        else if(strcmp(day,"WED")==0)
            running_day=5;
        else if(strcmp(day,"THU")==0)
            running_day=6;
        else if(strcmp(day,"FRI")==0)
            running_day=7;
            holidays=0;
        for(int i=0;i<total_days;i++)
        {
            if(running_day==6 || running_day==7)
                holidays++;

            if(running_day==7)
                running_day=1;
            else running_day++;
        }
        printf("%d\n",holidays);
    }
    return 0;
}

