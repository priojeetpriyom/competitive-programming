
#include<bits/stdc++.h>
using namespace std;
int main ()
{
   int n;
    while(scanf("%d",&n)==1) {
        n--;
        vector<int> plusAra;
        int lenP=0,sumP=0;
        vector<int> minusAra;
        int lenM=0,sumM=0;
        char c;
        for(int i=0; i<n;i++) {
            scanf("\n%c",&c);
            int x;
            scanf("%d",&x);
            if(c=='+')
                {
                    plusAra.push_back(x);
                    sumP+=x;
                }
            else{

                minusAra.push_back(x);
                sumM+=x;
            }
        }
        sort(plusAra.begin(),plusAra.end());
        sort(minusAra.begin(),minusAra.end());
        if(sumP==sumM) {

        }
        bool dump=false;
        int cnt=0;
        while(sumP!=sumM) {
                int diff= abs(sumM-sumP);
            if(sumP>sumM) {
                for(int i= plusAra.size()-1; i>=0; i++) {
                    if(plusAra[i]<=diff) {
                        minusAra.push_back(plusAra[i]);
                        sumP-=plusAra[i];
                        sumM+=plusAra[i];
                        plusAra.erase(plusAra.begin()+i);
                        break;
                    }
                    if(i==0)
                    {
                        dump=true;
                        break;
                    }
                }
            }
            else {
                for(int i= minusAra.size()-1; i>=0; i++) {
                    if(minusAra[i]<=diff) {
                        plusAra.push_back(plusAra[i]);
                        sumM-=minusAra[i];
                        sumP+=minusAra[i];
                        minusAra.erase(minusAra.begin()+i);
                        break;
                    }
                    if(i==0)
                    {
                        dump=true;
                        break;
                    }
                }
            }
            if(dump)
                break;
                cnt++;
        }
        if(sumM==sumP)
            printf("%d\n",cnt);
        else
            printf("-1\n");

    }

    return 0;
}

