#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 105


struct node
{
    int r,l, len;
    vector<ll> cum;

};
vector<node> chain(200100);
ll chainCum[200100], selfCum[200100];
int n, q;



ll subMin(int c, int from, int to)
{

    vector<ll> &cum  = chain[c].cum;
    int len = chain[c].len;

    ll diff = abs(cum[to-1] - cum[from-1]);
    return min(cum[len] -diff, diff);

}

ll chainMin(int from, int to)
{

    if(from>to)
    {
        ll sufDiff = abs(selfCum[to] - selfCum[from]), diff;
        if(from< to) {
            diff -= (selfCum[to] - selfCum[to-1]);
            sufDiff += (selfCum[from] - selfCum[from-1]);
        }
        else
        {
            diff -= (selfCum[from]- selfCum[from-1]);
            sufDiff += (selfCum[to] - selfCum[to-1]);
        }
        ll chainDiff = abs(chainCum[from-1] - chainCum[to-1]);
        return min(chainDiff+ diff, chainCum[n]-chainDiff + (selfCum[n] - sufDiff));
    }

    return (chainCum[from+n-1] - chainCum[to-1]) + (selfCum[from+n-1] - selfCum[to]);

}
ll chainLeft(int from, int to)
{

    if(from>to)
    {
        return (chainCum[from-1] - chainCum[to-1]) + (selfCum[from-1] - selfCum[to]);
    }
    ll chainCost = chainCum[from-1] + (chainCum[n] - chainCum[to-1]);
    ll selfCost = selfCum[from-1] + (selfCum[n] - selfCum[to]);

    return chainCost+selfCost;

}
ll chainRight(int from, int to)
{
    if(from<to)
    {
        return (chainCum[to-1] - chainCum[from-1]) + (selfCum[to-1] - selfCum[from]);
    }

    ll chainCost = chainCum[to-1] + (chainCum[n] - chainCum[from-1]);
    ll selfCost = selfCum[to-1] + (selfCum[n] - selfCum[from]);

    return chainCost+selfCost;


}



void pre()
{
//    printf("PRE\n");

    for(int i=1; i<=n; i++) // calculating cumulative distance for sub-chains
    {
        vector<ll> &vec = chain[i].cum;
        int len = vec.size();
        for(int j=1; j<len; j++)
        {
            vec[j] += vec[j-1];
        }

    }

    for(int i=1; i<=n; i++) // calculating self l-r cost
    {

        selfCum[i] = subMin(i, chain[i].l, chain[i].r);
        selfCum[i]+= selfCum[i-1];

        chainCum[i]+= chainCum[i-1];
//        printf("i %d l %d to r %d costL %lld costR %lld\n", i, l, r, costL, costR);

    }

}


ll goRight(int v1, int c1, int v2, int c2)
{
    ll cost=0; //, costL=0, costR=0;

    //goto self parent

//    int from = v1, to, par = chain[c1].r;
//    vector<ll> &cum1  = chain[c1].cum;
//    int len = chain[c1].len;


    cost = subMin(c1, v1, chain[c1].r);


    //find the distace between two chains

//    ll leftCost = chainLeft(c1, c2);
    ll rightCost = chainRight(c1, c2);

    //find the distance between entry point of c2 and the destination node
//    leftCost += subLeft(c2, chain[c2].r, v2);
    rightCost+= subMin(c2, chain[c2].l, v2);

    cost+= ( rightCost);

//    printf("goRight cost %lld\n", cost);

    return cost;




}


ll goLeft(int v1, int c1, int v2, int c2)
{
//    printf("GO LEFT\n");
    ll cost=0; //, costL=0, costR=0;

    //goto self parent

//    int from = v1, to, par = chain[c1].l;
//    vector<ll> &cum1  = chain[c1].cum;
//    int len = chain[c1].len;


    cost = subMin(c1, v1, chain[c1].l);
//    printf("self to par left %lld right %lld\n",subLeft(c1, v1, par), subRight(c1, v1, par));


    //find the distace between two chains

    ll leftCost = chainLeft(c1, c2);
//    ll rightCost = chainRight(c1, c2);

//    printf("c1 to c2 left %lld\n", leftCost);

    //find the distance between entry point of c2 and the destination node
    leftCost += subMin(c2, chain[c2].r, v2);
//    rightCost+= subRight(c2, chain[c2].l, v2);

    cost+= (leftCost);

//    printf("goLeft cost %lld\n", cost);

    return cost;
}


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout<<lim_int - ( (1LL)<<32)+1;

    int t;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++)
    {
        scanf("%d %d", &n, &q);

        for(int i=1; i<=n; i++)
        {
            vector<ll> &vec = chain[i].cum;
            vec.clear();
            vec.push_back(0);
            int x, y;
            scanf("%d", &x);
            chain[i].len = x;
            for(int j=0; j<x; j++)
            {
                scanf("%d", &y);
//                printf("aise\n");
                vec.push_back(y);
            }

        }

        for(int i=1; i<=n; i++)
        {
            int v1, v2,w;
            scanf("%d %d %d", &v1, &v2, &w);
            chain[i].r = v1;
            chain[ (i%n)+1].l = v2;
            chainCum[i] = w;
        }

        pre();


        while(q--)
        {
            int v1, c1, v2, c2;
            scanf("%d %d %d %d", &v1, &c1, &v2, &c2);
            printf("%lld\n", min(goLeft(v1, c1, v2, c2), goRight(v1,c1,v2,c2)));
        }


    }



    return 0;
}
