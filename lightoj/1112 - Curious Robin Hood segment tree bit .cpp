#include <bits/stdc++.h>
using namespace std;
int ara[100100], tree[100100];
int n;

void printTree() {
    printf("tree:\n");
    for(int i=0; i<=n; i++) {
        printf("%d ", tree[i]);
    }
    printf("\n\n");
}

void build() {
    for(int i=1; i<=n; i++) {
        int x = ara[i];
        int idx=i;
        while(idx<=n) {
            tree[idx]+=x;
            idx+= (idx & -idx);
        }
    }
}

void update(int idx, int val) {
    while(idx<=n) {
        tree[idx]+= val;
        idx+= (idx & -idx);
    }
}

int query(int idx) {
    int sum=0;
    while(idx!=0) {
        sum+= tree[idx];
        idx-= (idx & -idx);
    }
    return sum;
}


int main()
{
//        freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

int t;
    cin>>t;
    for(int tc=1; tc<= t; tc++) {
        int q;

        scanf("%d %d", &n, &q);

        for(int i=1; i<=n; i++)
        {
            scanf("%d", &ara[i]);
//            tree[i] = ara[i];
        }

        build();

        printf("Case %d:\n", tc);

        while(q--) {
//            printTree();
            int x, p,q;
            scanf("%d %d", &x, &p);
            p++;
            if(x==1) {
                x = (query(p) - query(p-1));
                update(p, -x);
                printf("%d\n", x);
            }else if(x==2) {
                scanf("%d", &q);
//                q++;
                update(p, q);
            } else {
                scanf("%d", &q);
                q++;
                printf("%d\n", query(q) - query(p-1) );
            }
        }
        memset(ara, 0, sizeof(ara));
        memset(tree, 0, sizeof(tree));
    }

    return 0;
}









