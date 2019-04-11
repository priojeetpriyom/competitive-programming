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
    int n;
    string x1,x2;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int cnt = 0;
        cin >> x1 >> x2;
        int len = x1.length();
        int len2 = x2.length();
        for(int j=0;j<len2-len+1; j++)
        {
            string x = x2.substr(j,len);
            if(x == x1)
            {
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
