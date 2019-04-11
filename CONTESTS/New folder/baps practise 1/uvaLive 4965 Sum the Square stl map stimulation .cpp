#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
int power[11];
int main()
{
    int a,b;

    for(int i=0; i<10; i++)
        power[i] = i*i;

    while(scanf("%d %d", &a, &b)==2 && a!=0 && b!=0) {
//        mp[1] = 1;
        if(a==b) {
            printf("%d %d 2\n", a,b);
            continue;
        }
        int cnt=0;

    bool one =false;
        int x=a;
        if(a !=1)
        for(int i=0; i<100000; i++) {
//            if(x==1) {
//                mp[x] = (++cnt);
//                break;
//
            if(mp[x])
            {
                break;
            }
            else
                mp[x]= (++cnt);

//            printf("%d cnt %d\n",x,mp[x]);
            if(x==1)
            {
                one = true;
                break;
            }
            int sum=0;
            do{
                int temp = x%10;
                sum  += power[temp];
                x/=10;
            } while(x>0);

            x= sum;

        } else {
            cnt=1;
            mp[1] =1;
        }


//        printf("cnt %d\n", cnt);

    bool  match =false;
    int cnt2=1;
        if(mp[b]) {
            printf("%d %d %d\n",a,b,mp[b]+1);

        } else
        {
//            cnt++;
            x=b;int sum=0;
        for(int i=0; i<100000; i++) {
//            if(x==1)
//            {
//                cnt++;
//                if(mp[x])
//                break;
//            }


//                break;

//            printf("%d\n",x);
            sum=0;
            do{
                int temp = x%10;
                sum  += power[temp];
                x/=10;
            } while(x>0);

            cnt2++;

            if(sum==1) {
                if(one) {

                    match = true;

                }
                break;
            }
            if(mp[sum])
            {

                match =true;
                break;
            }

            x= sum;

//            if(i==100000)
//            {
//                match =false;
//            }
        }
        if(match)
         printf("%d %d %d\n",a,b,mp[sum]+cnt2);
         else
            printf("%d %d 0\n",a,b);
        }
        mp.clear();
    }
    return 0;
}

