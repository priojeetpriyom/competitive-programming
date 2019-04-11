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


vector <int> Pos;
vector <char> G[110];
int cnt = 0;

void bfs(int r,int c)
{

}

int main()
{
    int t,x,y;
    scanf("%d",&t);
    while(t--)
    {
        int scanf("%d %d",&x,&y);
        getchar();
        char ch;
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                scanf("%c",&ch);
                G[i].push_back(ch);
                if(ch>='1' && ch<='9')
                pos.push_back(i);
                pos.push_back(j);
            }
            getchar();
        }

        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
               printf("%c",G[i][j]);
            }
            printf("\n");
        }
    }

}
