/*
    algo:
    idea:

*/
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX (1<<18)

// struct Node {
//   ll subarrays=0, prefix=0, suffix=0;
// } treeL[MX*4], treeR[MX*4];

// int N,Q,L,R;
ll tree[MX*4];

void update(int node, int b, int e, int pos, int val, int turn) {
	// cout<<"b "<<b<< " e "<<e<< " pos "<<pos<<" val "<<val<<endl;
  if(b==e && b==pos) {
		tree[node] = val;
      return;
  }

  if(b>pos || e< pos)
    return;

  int left = node<<1;
  int right = left+1;
  int mid = (b+e)/2;

  update(left, b, mid, pos, val, turn^1);
  update(right, mid+1, e, pos, val, turn^1);



  if(turn)
		tree[node] = tree[left] | tree[right];
	else
		tree[node] = tree[left] ^ tree[right];
  // cout<<"b "<<b<<" e "<<e<<" prefix "<<cur.prefix<<" suffix "<<cur.suffix<<" subarrays "<<cur.subarrays<<endl;

}


int main()
{
	ios_base::sync_with_stdio(0);
  cin.tie(0);
//freopen("output.txt", "w", stdout);
  int n,m ;
	cin>>n>>m;

int lim = 1<<n;
ll pos, val;
for(int i=1; i<=lim; i++) {
	cin>>val;
	update(1,1,lim, i, val, n&1);
}
// cout<<"tree_after_input: "<<tree[1]<<endl;
while(m--) {

		cin>>pos>> val;
		update(1,1,lim, pos, val, n&1);
		cout<<tree[1]<<endl;
}
	// cout<<"EXECUTION FINISHED";
    return 0;
}
