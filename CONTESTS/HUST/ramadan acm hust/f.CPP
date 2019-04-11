
#include<bits/stdc++.h>
using namespace std;
int main ()
{
   int n;
   int changes[102];
    while(scanf("%d",&n)==1) {

        while(n--) {
            int one,five,ten,tweenty,fifty,require;
            scanf("%d %d %d %d %d %d",&require,&one,&five,&ten,&tweenty,&fifty);
            memcset(changes,0,sizeof(changes));
            int gathered=0;

            if(require>=50) {
                int x = require/50;
                if(x>=fifty)
                    fifty-=x;
                else
                    x=fifty;
                require-= (x*50);
                changes[50]+=x;
            }
            if(require>=20) {
                int x = require/20;
                if(x>=tweenty)
                    tweenty-=x;
                else
                    x=tweenty;
                require-= (x*20);
                changes[20]+=x;
            }
            iif(require>=10) {
                int x = require/10;
                if(x>=ten)
                    ten-=x;
                else
                    x=ten;
                require-= (x*10);
                changes[10]+=x;
            }
            if(require>=5) {
                int x = require/5;
                if(x>=five)
                    five-=x;
                else
                    x=five;
                require-= (x*5);
                changes[5]+=x;
            }
            if(require>=1) {
                int x = require;
                if(x>=one)
                    one-=x;
                else
                    x=one;
                require-= (x);
                changes[1]+=x;
            }

            if(require!=0) {
                if(five!=0) {
                    require=5-require;
                }

//                for(int i=require; i>0; i--)
//                {
//                    int x =require;
//                    for(int j=i;j>0;j--) {
//                            int temp=changes[i];
//                        while(changes[i]>0 && require>=i) {
//                        {
//                            x-=changes[i];
//                            changes[i]--;
//                        }
//
//                    }
//
//                    }
//                }

            if(require==1) {
                if(changes[i]>=1)
                {
                    changes[i]--;
                }

            }
            if(require==2) {


            }if(require==3) {


            }if(require==4) {


            }

            }


        }
    }

    return 0;
}

