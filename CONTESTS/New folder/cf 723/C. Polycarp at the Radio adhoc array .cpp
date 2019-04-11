#include <bits/stdc++.h>
using namespace std;

    map<int,int> cnt;
int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int ara[2011];
//    memset(cnt, 0, sizeof(cnt));
    int n,m;
    scanf("%d %d",&n, &m);
    int avg = n/m;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ara[i]);
            cnt[ara[i]]++;
    }

    int change=0;
    for(int i=1; i<=m; i++)
    {
        if(cnt[i] > avg)
        {
                int x = cnt[i]-avg;
//                change+= (cnt[i]-avg);
                cnt[i] = avg;
                for(int j=0; x>0; j++)
            {
                if(ara[j] == i)
                    {
                        x--;
                        ara[j] *= (-1);
                    }
                }
            }

        }


    int cnt_pos=2010;
    for(int i=1; i<=m; i++)
        if(cnt[i]<avg)
        {
            cnt_pos = i;
            break;
        }

    for(int i=0; i<n; i++)
    {
        if(ara[i]>m)
        {

            if(cnt_pos!=2010) {
                change++;
                ara[i] = cnt_pos;
                cnt[cnt_pos]++;
                if(cnt[cnt_pos] == avg) {
                    bool update=false;
                    for(int j = cnt_pos+1; j<=m; j++) {
                        if(cnt[j] < avg) {
//                            printf("oka");
                            cnt_pos = j;
                            update=true;
                            break;
                        }
                    }
                    if(!update)
                        cnt_pos=2010;
                }
            }

        }
    }

    cnt_pos=2010;
    for(int i=1; i<=m; i++)
        if(cnt[i]<avg)
        {
            cnt_pos = i;
            break;
        }

    for(int i=0; i<n; i++) {
        if(ara[i]<0) {
            if(cnt_pos!= 2010) {
                change++;
                ara[i] = cnt_pos;
                cnt[cnt_pos]++;

                if(cnt[cnt_pos] == avg) {
                    bool update=false;
                    for(int j = cnt_pos+1; j<=m; j++) {
                        if(cnt[j] < avg) {
                            cnt_pos = j;
                            update=true;
                            break;
                        }
                    }
                    if(!update)
                        cnt_pos=2010;
                }

            } else {
                ara[i] *= (-1);
            }
        }

    }


    printf("%d %d\n",avg,change);

    for(int i=0; i<n; i++)
        printf("%d ",ara[i]);
    printf("\n");


    return 0;
}
