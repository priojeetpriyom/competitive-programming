#include <bits/stdc++.h>
using namespace std;
long long p, q;
long long v;

struct node {
    long long sum=0, prop=0;
} tree[100010*4];

void update(long long node, long long beg, long long endd, long long xx, long long yy, long long zz) {
//    getchar();
//    printf("1beg %d end %d\n", beg, endd);
    if(beg > q || endd < p)
        return;

    if(beg >= p && endd <= q)
    {
        tree[node].sum += (v * (endd-beg+1));
        tree[node].prop += v;
        return;
    }
//    prlong longf("2beg %d end %d\n", beg, endd);
    long long left = node<<1;
    long long right = left+1;
    long long mid = (beg+endd)>>1;

    update(left, beg, mid, xx, yy, zz);
    update(right, mid+1, endd, xx, yy, zz);
    tree[node].sum = tree[left].sum + tree[right].sum + tree[node].prop * (endd-beg+1);
}

//void update(long long node, long long b, long long e, long long i, long long j, long long x)
//{ printf("1beg %d end %d\n", b, e);
//    if (i > e || j < b)
//        return;
//    if (b >= i && e <= j) //নোডের রেঞ্জ আপডেটের রেঞ্জের ভিতরে
//    {
//        tree[node].sum += ((e - b + 1) * x); //নিচে নোড আছে e-b+1 টি, তাই e-b+1 বার x যোগ হবে এই রেঞ্জে
//        tree[node].prop += x; //নিচের নোডগুলোর সাথে x যোগ হবে
//        return;
//    }
//    long long Left = node * 2;
//    long long Right = (node * 2) + 1;
//    long long mid = (b + e) / 2;
//    update(Left, b, mid, i, j, x);
//    update(Right, mid + 1, e, i, j, x);
//    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
//    উপরে উঠার সময় পথের নোডগুলো আপডেট হবে
//    বাম আর ডান পাশের সাম ছাড়াও যোগ হবে নিচে অতিরিক্ত যোগ হওয়া মান
//}

long long query(long long node, long long beg, long long endd, long long prop) {
    if(beg >= p && endd<= q)
    {
        return tree[node].sum + (prop * (endd-beg+1));
    }
    if(beg > q || endd < p)
        return 0;

    long long left = node<<1;
    long long right = left+1;
    long long mid = (beg+endd)>>1;

    long long x1 = query(left, beg, mid, prop + tree[node].prop);
    long long x2 = query(right, mid+1, endd, prop + tree[node].prop);

    return x1 + x2;
}

int main()
{
    long long t;
    scanf("%lld", &t);
        long long n,x, c;
    while(t--) {
        scanf("%lld %lld", &n, &c);
        for(long long i=0; i<c; i++) {
            scanf("%lld", &x);
            if(x==0) {
                scanf("%lld %lld %lld", &p, &q, &v);
//                prlong longf("oka\n");
                update(1, 1, n, p , q, v);
            } else {
                scanf("%lld %lld", &p, &q);
                printf("%lld\n", query(1,1,n, (long long)0));
            }
        }
        memset(tree, 0, sizeof(tree));
//        cout<<tree[1].sum;
//        for(long long i=1; i<16; i++)
//            prlong longf("%d ",tree[i].sum);
    }
    return 0;
}

