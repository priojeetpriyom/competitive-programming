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


int main()
{
    long long thenum;
    long long t,n,x;
    long long jar[100005];
    scanf("%lld",&t);
    for(long long i=1; i<=t; i++)
    {
        scanf("%lld %lld",&n,&thenum);
        MEM(jar,0);
        for(long long j=0; j<n; j++)
        {
            scanf("%lld",&x);
            if(x<=thenum)
            {
                jar[x] = x;
            }
        }
        long long cnt=0;
        long long mid = (thenum)/2;
        for(long long j=1; j<=mid; j++)
        {
            if((jar[j] + jar[thenum-j] == thenum) && (jar[j]!=jar[thenum-j]))
            {
                cnt++;
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
