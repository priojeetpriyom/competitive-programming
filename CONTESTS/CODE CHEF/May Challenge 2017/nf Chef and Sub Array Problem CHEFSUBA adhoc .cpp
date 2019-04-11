#include<bits/stdc++.h>

using namespace std;




int vec[200100], id[100100], cum[100100];
int tree[200005<<2];
//int ;
        vector<int> ans(200100);


int build(int node, int beg, int endd) {
    if(beg == endd) {
        tree[node] = ans[beg];
        return tree[node];
    }
    int mid = (beg+endd)>>1;

    int left = (node<<1);
    int right = left+1;

    return tree[node] = max(build(left, beg, mid), build(right, mid+1, endd));
}

int query(int node, int beg, int endd, int q_beg, int q_end) {
//    printf("node %d beg %d endd %d q_beg %d q_end %d\n", node, beg, endd, q_beg, q_end);
//    getchar();
    if(beg>= q_beg && endd<= q_end) {
//        printf("returned %d\n" , tree[node]);
return tree[node];
    }
    if(endd < q_beg || beg > q_end) return 0;

    int mid = (beg+endd)>>1;
    int left = node<<1;
    int right = left+1;
    int l=0, r=0;
    if(mid>= q_beg)
        l = query(left, beg, mid, q_beg, q_end);
    if(mid < q_end)
        r = query(right, mid+1, endd, q_beg, q_end);
    return max(l,r);
}

int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n, k,p, x;

    scanf("%d %d %d", &n, &k, &p);
    {
        vec[0]= 0;
        int mx= -1, mx_idx;

        int firstCons=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &vec[i]);
            vec[i+n]  = vec[i];
//            if(i<=k)
//            {
//                ara[i]= vec[i] + ara[i-1];
//                mp[ara[i]]++;
//            }
        }
        for(int i=n+k; i>0; i--) {
            if(i>n) {
                ans[i]= ans[i+1] + vec[i];
            } else
                ans[i]= ans[i+1] + vec[i] - vec[i+k];
        }

//        for(int i=1; i<=n; i++) printf("%d ", ans[i]); printf("\n");

//        printf("aise\n");
        build(1, 1, n+n);

        char c;
        int cnt=1;

        while(p)
        {
            scanf("\n%c", &c);
//            ;

            if( c=='!')
            {
//                printf("p %d ! e aise\n",p);
                cnt++;

//                p--;
            }
            else if(c=='?')
            {
//                printf("cnt %d p %d\n", cnt, p);
                if(cnt>n)
                    cnt%= n;
//                cnt = max(cnt, 1);
                printf("%d\n", query(1, 1, n+n, cnt, cnt+n-k));
                c=0;
            }
            p--;
        }

    }


}

