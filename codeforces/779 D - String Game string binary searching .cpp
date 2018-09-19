
#include <bits/stdc++.h>

using namespace std;

string t,p;
int seq[200100], lenT, lenP;

bool valid(int pos) {
    string temp = t;

    for(int i=0; i<=pos; i++)
        temp[ seq[i]-1 ] = -1;

    for(int i=0, j=0; i<lenT; i++) {
        if(temp[i] == p[j])
            j++;
        if(j == lenP)
            return true;
    }
    return false;
}

int binSearch(int high, int low, int mid) {
    while(high>=low) {
        if(valid(mid))
            low = mid+1;
        else
            high = mid-1;
        mid = (high + low)>>1;

    }

    return low;
}

int main() {
    //    freopen("out.txt", "w", stdout);

   cin>>t>>p;
   lenT = t.length();
   lenP = p.length();

   for(int i=0; i<lenT; i++)
    scanf("%d", &seq[i]);

   cout<<binSearch(lenT-1, 0, (lenT-1)/2);

    return 0;
}


