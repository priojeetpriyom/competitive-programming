#include <bits/stdc++.h>
using namespace std;

struct node {
    int val=-1;
    vector <int> index;
} dp[1002] [32]   ;

int t,n,w;
int d[31], v[31];
//ara<struct node > dp[1001] [31];
//int mx;
//vector<int> mx_seq;
vector<int> seq;
struct node rec(int time, int val, int cnt ) {
//    if(seq.size()>=1)
//    if(seq[0] ==1 && seq[1] ==7 && seq[2] == 8 && seq[3] == 12&& seq[4] == 17)
//    if(seq[0] ==1 )
//    if(time==253)
//    {
//        printf("=>time %d val %d cnt %d dist %d cost %d    ",time, val, cnt, d[cnt], 3*w*d[cnt]);
//    for(int i=0; i<seq.size(); i++)
//        printf("%d ",seq[i]);
//    printf("\n");
//    } else if(cnt==n)
//    {
//        printf("time %d val %d cnt %d dist %d cost %d    ",time, val, cnt, d[cnt], 3*w*d[cnt]);
//    for(int i=0; i<seq.size(); i++)
//        printf("%d ",seq[i]);
//    printf("\n");
//    }


    if(cnt == n) {
        struct node temp;
        temp.index = seq;
        temp.val = val;
//        if(val>mx)
//        {
//            mx = val;
//            mx_seq = seq;
//        }
        return temp;
    }


    struct node &ret = dp[time] [cnt];

//    if(ret.val!=-1)
//    {
//        printf("ada pada returned val %d\n", ret.val);
//        return ret;
//    }
struct node temp1;
    if(time - (3*w*d[cnt]) >=0)
    {
        seq.push_back(cnt);
        temp1 = rec(time - (3*w*d[cnt]), val+v[cnt] , cnt+1);
//        if(temp.val > ret.val)
//            ret = temp;
        seq.pop_back();

    }

    struct node temp2 = rec(time, val, cnt+1);
//
//        if(temp.val > ret.val)
//            ret = temp;

    return ret = (temp1.val>temp2.val)? temp1:temp2;

}


int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);
    bool blnLine =false;
    while(scanf("%d %d", &t, &w)==2) {
        if(blnLine) {
            printf("\n");
            for(int i=0; i<1001; i++) {
                for(int j=0; j<31; j++) {
                    dp[i][j].index.clear();
                    dp[i][j].val  = -1;
                }
            }
        }
        else
            blnLine = true;

        scanf("%d", &n);

        for(int i=0; i<n; i++)
            scanf("%d %d",&d[i], &v[i]);

//        mx=0;
        struct node temp = rec(t, 0, 0);
//        struct node temp = dp[t][0];


        printf("%d\n", temp.val);

        printf("%d\n", temp.index.size());

        for(int i=0; i< temp.index.size(); i++)
            printf("%d %d\n", d[temp.index[i]], v[temp.index[i]]);
    }

    return 0;
}
