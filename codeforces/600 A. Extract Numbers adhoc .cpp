#include <bits/stdc++.h>
//#include <iostream>
//#include <cstdio>
//#include <string.h>
//#include <math.h>
//#include <algorithm>
//#include <stack>
//#include <queue>
//#include <climits>
//#include <string>
//#include <stdlib.h>
//#define N 1000000
#define ll long long

using namespace std;

int main()
{
    char str_num[100100],str_ltr[100100],str[100100],temp[100100];
    int len_str,len_num,len_ltr;
    bool ltr,first_time;
    while(scanf("%s",str)==1)
    {
        len_str=strlen(str);
        str_num[0]='"',str_ltr[0]='"';
        len_num=len_ltr=1;
        first_time=true;
        for(int i=0; i<len_str; i++)
        {
            int j=i,j_temp=0;
            ltr=false;
            while(str[j]!= ',' && str[j]!= ';' && j<len_str)
            {
                temp[j_temp++]=str[j];
                if(str[j]=='.')
                    ltr=true;
                else if((str[j]>= 'A' && str[j]<='Z'))
                    ltr=true;
                else if((str[j]>= 'a' && str[j] <= 'z'))
                    ltr=true;
                j++;
            }
            i=j;
            temp[j_temp]='\0';
            if(ltr== true || j_temp==0)
            {
//                if(len_ltr==1 && j_temp==0 && first_time==true);
//                    //first_time=false;
//                else
//                    if(len_ltr!=1 || j_temp==0)
//                {
//                    if(str_ltr[1]==',' && len_ltr>2)
//                        str_ltr[len_ltr++]=',';
//                    else if()
//                    first_time=false;
//                }
                for(j=0; j<j_temp; j++)
                {
                    str_ltr[len_ltr++]=temp[j];
                }
                str_ltr[len_ltr++]=',';

            }
            else if(temp[0]=='0' && j_temp>1)
            {

                for(j=0; j<j_temp; j++)
                {
                    str_ltr[len_ltr++]=temp[j];
                }
                //if(len_ltr!=1 && str_ltr[1]!= ',')
                   str_ltr[len_ltr++]=',';
            }
            else
            {
                if(len_num!= 1)
                    str_num[len_num++]=',';
                for(j=0; j<j_temp; j++)
                {
                    str_num[len_num++] = temp[j];
                }
            }
        }
        if(str[len_str-1]==',' || str[len_str-1]==';')
            str_ltr[len_ltr++]=',';
        str_ltr[len_ltr-1]= '"';
        str_num[len_num++]='"';
        str_ltr[len_ltr]= '\0';
        str_num[len_num]='\0';
        //printf("len_ltr %d\n",len_ltr);
        if(len_num==2)
            printf("-\n");
        else
            printf("%s\n",str_num);
        if(len_ltr==1)
            printf("-\n");
//        else if(len_ltr==3 && str_ltr[1]==',')
//            printf("%c%c\n",34,34);
        else
            printf("%s\n",str_ltr);
    }
    return 0;
}
