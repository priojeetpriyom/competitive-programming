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


vector <int> pos;
vector <char> G[110];
int cnt = 0;
int nU=-1,nV=-1;

void bfs(int r,int c,int x,int y)
{
    queue <int> Q;
    Q.push(r);
    Q.push(c);
    int visited[110][110] = {0};
    int level[110][110]= {0};
    int parent[110][110];
    visited[r][c] = 1;
    int cx[]= {-1,1,0,0};
    int cy[]= {0,0,-1,1};
    while(!Q.empty())
    {
        int flag = 0;
        int u = Q.front();
        Q.pop();
        int v = Q.front();
        Q.pop();
        for(int a=0; a<4; a++)
        {
            int rx = u + cx[a];
            int ry = v + cy[a];
            if((rx>=0 && rx<x) && (ry>=0 && ry<y))
            {
                if(G[rx][ry]=='E')
                {
                    nU = u;
                    nV = v;
                    if(nU!= -1 && nV!=-1)
                    {
                        cnt = level[u][v];
                    }
                    flag = 1;
                    break;
                }
                else if(visited[rx][ry]!=1 && G[rx][ry]!='#')
                {
                    visited[rx][ry] = 1;
                    level[rx][ry] = level[u][v] + 1;
                    Q.push(rx);
                    Q.push(ry);
                }
            }
        }
        if(flag==1)
        {



            break;
        }
    }
}

int main()
{
    int t,x,y;
    int pert;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&x,&y);
        getchar();
        char ch;
        int per = 0;
        for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {
                scanf("%c",&ch);
                G[i].push_back(ch);
                if(ch>='1' && ch<='9')
                {
                    pos.push_back(i);
                    pos.push_back(j);
                    per++;
                }
            }
            getchar();
        }
        int l = 0;
        int CPP[10];
        char PONCounter[10];
        int flag = 0;
        for(int i=0; i<pos.size(); i+=2)
        {
            int Min = 100000;
            int r = pos[i];
            int c = pos[i+1];
            bfs(r,c,x,y);
            CPP[l] = cnt;
            PONCounter[l] = G[r][c];
            nU = -1;
            nV = -1;
            cnt = 0;
            l++;
        }
        int Min = 50000;
        char cns;
        for(int j=0; j<l; j++)
        {
            if(CPP[j]!=0)
            {
                if(CPP[j] < Min)
                {
                    Min = CPP[j];
                    cns = PONCounter[j];
                }
                else if(CPP[j] == Min)
                {
                    if(cns > PONCounter[j])
                        cns = PONCounter[j];
                }
                flag = 1;
            }
        }
        if(flag == 1)
            printf("%c\n",cns);
        else
        {
            printf("0\n");
        }
        pos.clear();
        for(int l=0; l<x; l++)
        {
            G[l].clear();
        }
    }
    return 0;
}
