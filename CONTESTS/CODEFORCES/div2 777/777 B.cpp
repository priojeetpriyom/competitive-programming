#include <bits/stdc++.h>

using namespace std;

//typedef ll long long;

int sherlock1[1111], sherlock2[1111], mori1[1111], mori2[1111];
int main()
{
//   freopen("out.txt", "w", stdout);
    int n;
    cin>>n;
    string s;

    cin>>s;
    for(int i=0; i<n; i++)
    {
        sherlock1[s[i] - '0']++;
        sherlock2[s[i] - '0']++;
    }
    cin>>s;
    for(int i=0; i<n; i++)
    {
        mori1[s[i] - '0']++;
        mori2[s[i] - '0']++;
    }
    int mnFlick=INT_MAX, cnt=0;
    int nn=n, ss=0, mm=0;
    while(ss<10)
    {
        while(!sherlock1[ss] && ss<10)
            ss++;
        while((mm < ss  || mori1[mm]==0 ) && mm<10)
        {
            mm++;
        }
        if(ss==10)
        {
//            printf("broke!\n");
            break;
        }
        if(mm==10)
        {
//            printf("break ss %d mm %d sher %d mori %d\n",ss,mm,sherlock1[ss], mori1[mm]);
            while(ss < 10)
            {
                cnt+= sherlock1[ss];
                ss++;
            }
            break;
        }

        sherlock1[ss]--;
        mori1[mm]--;
//
//        printf("ss %d mm %d sher %d mori %d\n",ss,mm,sherlock1[ss], mori1[mm]);
//
//        for(int i=1; i<=10; i++)
//        {
//            printf("%d ",sherlock1[i]);
//        }
//        printf("\n");
//        for(int i=1; i<=10; i++)
//        {
//            printf("%d ", mori1[i]);
//        }
//        printf("\n");
//        nn--;
    }
    mnFlick = cnt;

    cnt=0;
    ss=0;
    for(int i=0; i<10; i++)
    {
        while(mori2[i]>0)
        {
            while(sherlock2[ss] ==0 && ss<10)
                ss++;
            if(i <= ss)
                break;


            if(ss==10)
            {
                for( ; i<10; i++)
                    cnt+=mori2[i];
            }

            while(sherlock2[ss]>0 && mori2[i]>0)
            {
                mori2[i]--;
                sherlock2[ss]--;
                cnt++;
            }

        }
//        printf("ss %d mm %d sher %d mori %d\n",ss,mm,sherlock1[ss], mori1[mm]);

//        for(int i=1; i<=10; i++)
//        {
//            printf("%d ",sherlock2[i]);
//        }
//        printf("\n");
//        for(int i=1; i<=10; i++)
//        {
//            printf("%d ", mori2[i]);
//        }
//        printf("\n");

    }
    printf("%d\n%d\n", mnFlick, cnt);




    return 0;
}
