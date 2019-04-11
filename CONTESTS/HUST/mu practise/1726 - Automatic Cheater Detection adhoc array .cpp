#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOutput.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--) {
        int d,s;
        char r;
        int q;

        int sus_c[12],sus_i[12];

        for(int i=0; i<11; i++){
            sus_c[i]=0;
            sus_i[i] = 0;
        }

        scanf("%d",&q);

        for(int i=0; i<q; i++) {
            scanf("%d %d \n%c",&d,&s,&r);

            if(s==1 && r=='c')
                sus_c[d]++;
            else if(s==0 && r == 'i')
                sus_i[d]++;
        }
        long long sum =0;

        for(int i=1; i<11; i++) {
            for(int j=i+1; j<11; j++) {
                sum+= (sus_i[i]*sus_c[j]);
            }
        }

        printf("%lld\n",sum);
    }

    return 0;
}

