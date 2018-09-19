//#include <bits/stdc++.h>
//
//using namespace std;

//#include <stdio.h>
//#include <string.h>


struct node
{
    int r=0,g=0,b=0;
    int change=0;
//    r=g=b=change=0;


};

struct node tree[800100];

int full=2, partial=1, unchanged=0;
int n,m;
char s[200100];


void setNode(struct node &a, char c)
{

    if(c == 'R') a.r = 1;
    if(c == 'G') a.g = 1;
    if(c == 'B') a.b =1;

}

void addNodes(struct node &a, struct node &b, struct node &to)
{
    to.r = a.r + b.r;
    to.g = a.g + b.g;
    to.b = a.b + b.b;
    if(a.change == full && b.change == full) to.change = full;
    else if(a.change || b.change) to.change = partial;
}

void changeNode(struct node &a)
{
    int temp = a.r;
    a. r = a.g;
    a.g = a.b;
    a.b = temp;
    a.change = full;
}


struct node build(int b, int e, int node)
{
    if(b == e)
    {
        setNode(tree[node], s[b-1]);
        return tree[node];
    }

    int left = node<<1;
    int right = left+1;

    int mid = (b+e)/2;

    struct node l,r;
    l = build(b, mid, left);
    r = build(mid+1, e, right);

    addNodes(l, r, tree[node]);


    return tree[node];

}

void print_tree(int b, int e, int node)
{
//    printf("node %d b %d e %d r %d g %d b %d\n", node, b, e, tree[node].r, tree[node].g, tree[node].b);
    if(b == e)
    {
//        printf("c %c\n", s[b-1]);
//        setNode(tree[node], s[b-1]);
        return ;
    }

    int left = node<<1;
    int right = left+1;

    int mid = (b+e)/2;

//    struct node l,r;
    print_tree(b, mid, left);
    print_tree(mid+1, e, right);

//    addNodes(l, r, tree[node]);


//    return tree[node];

}


struct node query(int b, int e, int node) {
    return tree[node];

//    if(b>=s && e<=f) return tree[node];
//    if(b>f || e<s) return tree[0];
//    struct node ans;
//
//    int left =node<<1;
//    int right = left+1;
//    int mid = (b+e)/2;
//    struct node l,r;
//    l =query(b, mid, left, s, f) ; r = query(mid+1, e, right, s, f);
//
//
//    addNodes(l, r  , ans);
//    return ans;

};



struct node update(int b, int e, int node, int s, int f)
{
    if(b>f || e<s || tree[node].change == full) return tree[node];

    if(b >= s && e<=f && tree[node].change!= partial)
    {
//        if(tree[node].change == unchanged)
        {
//            printf("1 node %d b %d e %d r %d g %d b %d\n", node, b, e, tree[node].r, tree[node].g, tree[node].b);
            changeNode(tree[node]);
//            printf("2 node %d b %d e %d r %d g %d b %d\n", node, b, e, tree[node].r, tree[node].g, tree[node].b);

        }
        return tree[node];
    }

    int left = (node<<1);
    int right = left +1;
    int mid = (b+e)/2;


    struct node l, r;

//    if( ! (mid<s || b > f) )
        l = update(b, mid, left, s, f);
//    if(! (mid>=f || e<s))
        r = update(mid+1, e, right, s,f);


    addNodes(l, r, tree[node]);
//    printf("node %d b %d e %d l.r %d l.g %d l.b %d r.r %d r.g %d r.b %d t.r %d t.g %d t.b %d\n", node, b, e, l.r, l.g, l.b, r.r, r.g, r.b, tree[node].r, tree[node].g, tree[node].b);

    return tree[node];


}





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

//    cin>>n>>m;
    scanf("%d %d", &n, &m);
    scanf("\n%s", s);
//    cin>>s;
//    cout<<s<<endl;

    build(1, n, 1);
    print_tree(1, n, 1);
    int l,r;
//    struct node ans;
    while(m--)
    {
//        cin>>l>>r;
        scanf("%d %d", &l, &r);
        update(1, n, 1, l, r);
        struct node & ans=  tree[1];
//        cout<<ans.r<<" "<<ans.g<<" "<<ans.b<<endl;
        printf("%d %d %d\n", ans.r, ans.g, ans.b);
    }


    return 0;
}
