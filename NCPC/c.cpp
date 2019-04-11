#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, r, j, l[2010], cur_l, cur_d, cur_sdlen; int crnr, cur_cnt, cnt;
    char d[2010];
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d %d", &n, &r);
        for(j = 0; j < n; j++)
            scanf("%d", &l[j]);
        for(j = 0; j < n; j++)
            scanf("\n%c", &d[j]);
        cnt = 0;
        crnr = 0;

        for(j = 0; j < n; j++){
            cur_l = l[j];
            cur_d = d[j];
            cur_sdlen = cur_l;
            while(cur_d == d[j+1]){
                cur_sdlen = cur_sdlen + l[j];
                j++;
            }
            if(crnr == 1)
                crnr = 2;
           cout<<"sdlen "<<cur_sdlen<<endl;
           cur_sdlen = cur_sdlen-crnr;
            cur_cnt = cur_sdlen/(r*2);
            if(cur_cnt*(r*2) != cur_sdlen)
                cur_cnt++;
            cnt = cnt + cur_cnt;
            cout<<cnt<<" "<<cur_cnt<<" "<<crnr<<" "<<j<<endl;
            if((cur_cnt*r*2)-cur_sdlen <= r && (cur_cnt*r*2)-cur_sdlen != 0){
                crnr = 1;
                cout<<"cr "<<(cur_cnt*r)-cur_sdlen<<endl;
            }
            else
                crnr = 0;
//            cur_l = l[j];
//            cur_d = d[j];
        }
        printf("%d\n", cnt);
    }
}
