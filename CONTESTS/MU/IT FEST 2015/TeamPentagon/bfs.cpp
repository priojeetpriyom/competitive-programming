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

vector<char>G[100];


int cnt = 0;

void bfs(int n,int src)
{


}

int main()
{
    int n,t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        getchar();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                char ch;
                scanf("%c",&ch);
                v[i].push_back(ch);
            }
        }
    }
}
