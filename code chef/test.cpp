

#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>

#define pb push_back
#define INF 1<<28
#define sz(a) a.size()
#define all(a) (a.begin(),a.end())
#define mx 200

using namespace std;

vector < int > vec[mx];
int d[mx],original[mx];
bool color[mx];

queue < int > q;

void bfs( int start )
{
//    cout<<"Calling BFS with = "<<start<<endl;
   d[start] = 0;
   q.push(start);
   color[start] = true ;

   while( q.size() )
   {
       int front = q.front() ;

       q.pop();
       for ( int i = 0 ; i < vec[front].size() ; i++)
       {
           int var = vec[front][i];
           if ( !color[var] )
           {
               color[var] = true ;
               d[var] = d[front]+1;
               q.push(var);
               original[var] += d[var] ;
           }
       }
   }
}

int main()
{
    int tc,T=0;
    cin>>tc;
    while(tc--)
    {
        int node,edges;
        cin>>node>>edges;

        for ( int i = 0 ; i < node ; i++) d[i]=0;
        for ( int i = 0 ; i < edges ; i++)
        {
            int a,b;
            cin>>a>>b;

            vec[a].push_back(b);
            vec[b].push_back(a);
        }

        int start , end ;
        cin>>start>>end;

        original[start] = 0 ;

        bfs(start);
        memset(color,false,sizeof color);
        bfs(end);

        int res = 0 ;

        for ( int i = 0 ; i < node ; i++ )
        {
           cout<<"---->>>>>>>>>>"<<i<<" "<<original[i]<<endl;

            if ( original[i] > res ) res = original[i];
        }

        printf("Case %d: %d\n",++T,res);

        memset(color,false,sizeof color);
        memset(d,0,sizeof d);
        memset(original,0,sizeof original);

        for ( int i = 0 ; i < node+10 ; i++) vec[i].clear();
    }
    return 0;
}



