/*
    IDEA: use a bit to store from 1 any_pos how many indices are still alive. then we can use a b_search to compute the right indice

    complexity: N q (logN)^2
*/
/*
    algo:
    idea:

*/
//
//
//#include<stdio.h>
//#include<string.h>

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 2000100
//#define mod 1000000007
//int tree[MX*4];
int tree_bit[MX];
int t, tc;
int ara[MX];

int lim;
void update_bit(int idx, int val) {
    while(idx<= lim) {
        tree_bit[idx]+=val;
        idx += (idx & -idx);
    }
}

int query_bit(int idx) {
if(!idx)
 return 0;
    int sum=0;
    while(idx!=0) {
        sum+= tree_bit[idx];
        idx-= (idx & -idx);
    }
    return sum;
}

int b_search(int low, int high, int mid, int inp) {


    while(low<=high) {
        mid = (high+low)>>1;
        int cnt =  query_bit(mid);
//        printf("mid %d cnt %d\n", mid, cnt);
        if(cnt == inp && query_bit(mid) - query_bit(mid-1)>0)
        {

            return mid;
        }
        else if(cnt >= inp)
            high = mid-1;
        else low = mid+1;

    }

}



int main()
{
//freopen("output.txt", "w", stdout);

//    process[0]= {1,2,3};

//    cout<<process[0].id<<" "<<process[0].at<<" "<<process[0].bt<<endl;

    scanf("%d", &t);
//    memset(ncr, -1, sizeof ncr);
//    memset(dp, -1, sizeof dp);
//        for(int i=1; i<MX; i++)
//        {
//            dist[i] = 1<<30;
//        }
    for( tc=1; tc<=t; tc++)
    {
//        memset(tree, 0, sizeof tree);
        memset(tree_bit, 0, sizeof tree_bit);
//    len=0;
//        memset(dist, -1, sizeof dist);
//        memset(vis, 0, sizeof vis);
        int n,q;
        scanf("%d %d", &n, &q);
//        int start;        scanf("%d %d", &n, &q);
        lim=n + q+50;
//        scanf("\n%s", str+1);
//        str[0]=1;
//        n = strlen(str)-1;
//        cout<<n<<" "<<str<<endl;
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &ara[i]);
                update_bit(i, 1);
//            update(1, 1, lim, i, i);
        }
//        for(int i =n+1; i<=lim; i++)
//            update(1, 1, lim, 1e9, i);
//        printf("PRINT STARTS\n\n");
//        print(1, 1, lim);

//        build(1, 1, n);
//        scanf("%d", &q);
//        wildcard.clear();
        char c;

        printf("Case %d:\n", tc);
        int cur_size = n, cur_end= n;
        while(q--)
        {
//            int x, y;
//            cin>>x>>y;
//            cout<<query(1, 1, lim, x, y);
//            continue;
            scanf("\n%c", &c);
            int pos;
            if(c=='c')
            {
                scanf("%d", &pos);
//                int offset= query(pos);
//                printf("pos %d offset %d\n", pos, offset);
                if(pos>cur_size)
                {
                    printf("none\n");
                    continue;
                }
                cur_size--;
//                int offset = query_bit(pos);
//                int available = query(1, 1, lim, pos+offset, lim);
                int available = b_search(1, cur_end, 0, pos);
//                printf("pos %d available %d\n", pos, available);
                printf("%d\n", ara[available]);
//                update(1, 1, lim, 1e9, available);

                update_bit(available, -1);
//                for(int i=1; i <=cur_end; i++)
//                    printf("%d ", query_bit(i) -query_bit(i-1));
//                    printf("\n");
            }
            else
            {
                cur_size++;
//                int offset= query(n);
//                printf("offset_for_%d : %d\n", n, offset);
                scanf("%d", &ara[++cur_end]);
                update_bit(cur_end, 1);
//                update(1, 1, lim, cur_end, cur_end);
//                cur_end++;
//                printf("inserted %d at %d\n", ara[cur_end-1], cur_end-1);
            }
//            printf("%s\n", grid[i]+1);
        }

    }
//    printf("\n");


    return 0;
}
