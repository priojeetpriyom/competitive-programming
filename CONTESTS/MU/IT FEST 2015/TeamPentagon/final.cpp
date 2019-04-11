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

int res(int x)
{
    int total = 0;
    while(x!=0)
    {
        int tmp = x%10;
        total += tmp;
        x/= 10;
    }
    return total;
}

int main()
{

    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int x = res(n);
        n = n - x;
        if(n>9)
        {
            n = res(n);
        }
        n -= 5;
        printf("%c\n",64+n);
    }
    return 0;
}
