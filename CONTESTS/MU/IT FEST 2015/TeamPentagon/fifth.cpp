#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#define MEM(a,b) memset((a),(b),sizeof(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define In freopen("In.txt", "r", stdin);
#define Out freopen("out.txt", "w", stdout);

using namespace std;
int ara[1000],maxx;
void recursion(int n,int pluss,int minuss,int sum,int i) {
    if(n==1) {
        ara[sum]++;
        if(sum>maxx) maxx=sum;
        //printf("sum %d\n",sum);
        sum=1;
        return;
    }
    if(pluss>0) {
        sum+=n;
        recursion(n-1,pluss-1,minuss,sum,i);
        //ara[sum]++;
    }
    if(minuss>0) {
        sum-=n;
        recursion(n-1,pluss,minuss-1,sum,i);
        //ara[sum]++;
    }
}

int main()
{
    int n,t;
    scanf("%d",&t);
    int mx;
    while (t--) {
        MEM(ara,0);
        mx=0;
        maxx=0;
        scanf("%d",&n);
        recursion(n,n-1,n-1,1,0);
        for(int i=1;i<=maxx;i++)
            if(ara[i]>mx) mx=ara[i];
        printf("%d\n",mx);
        //for(int i=1;i<=maxx;i++) printf("%d ",ara[i]);
//        printf("\n");
    }
    return 0;
}
