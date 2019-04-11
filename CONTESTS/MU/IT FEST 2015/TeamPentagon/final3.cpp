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
    int t,n,x1,x2,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&x1,&x2);
        int total = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&m);
            if(i>=x1 && i<=x2)
                total += m;
        }
        printf("%d\n",total);
    }
    return 0;
}
