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

    int t,n,w,tmp,mx=-1150;
    int jar[1005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&w);
        MEM(jar,0);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&tmp);
            jar[tmp] = 1;
            if(tmp>mx)
                mx = tmp;
        }
        int flag1 = 0;
        int flag2 = 0;
        for(int i=w-1; i>=1; i--)
        {
            if(jar[i]!=0)
            {
                printf("%d ",i);
                flag1 = 1;
                break;
            }
        }
        if(flag1==0)
        {
            printf("-1 ");
        }
        for(int j=w+1; j<=mx; j++)
        {
            if(jar[j]!=0)
            {
                printf("%d\n",j);
                flag2 = 1;
                break;
            }
        }
        if(flag2==0)
        {
            printf("-1\n");
        }
    }
    return 0;
}
