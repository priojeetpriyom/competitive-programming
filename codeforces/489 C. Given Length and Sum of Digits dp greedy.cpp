#include<bits/stdc++.h>
using namespace std;

bool checkOK(int remVal, int remPos) {
	if(remVal==0)
		return true;
	if(remPos==0)
		return false;
	return (remVal/9) + (remVal %9!=0) <=remPos;
}

int main() {
	
	int s, m;
	while(cin>>m>>s) {
		
	int temps =s;
	if(m==1 && s<10)
	{
		cout<<s<<" "<<s<<endl;
		continue;
	}
	string mxs, mns;
	
	for(int i=0; i<m; i++) {
			bool taken =  false;
		for(int j=9; j>= (i==0); j--) {
			if(s-j>=0) {
				taken = true;
				mxs+= (j+'0');
				s-=j;
				break;
			}
		}
		if(!taken)
			break;
	}
	if((int)mxs.size()!=m || s!=0) {
		cout<<"-1 -1"<<endl;
		continue;
	}
	
	s = temps;
	for(int i=0; i<m; i++) {
			bool taken =  false;
		for(int j=(i==0); j<=9; j++) {
			if(s-j>=0 && checkOK(s-j, m-i-1) ) {
				taken = true;
				mns+= (j+'0');
				s-=j;
				break;
			//	printf("i %d selected %d\n", i,j);
			}
		}
		if(!taken)
			break;
	}

	
	//cout<<mns.size()<<" "<<mxs.size()<<endl;
	cout<<mns<<" "<<mxs<<endl;
		
		}
	
}
