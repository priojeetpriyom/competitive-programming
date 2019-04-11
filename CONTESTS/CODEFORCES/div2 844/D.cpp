#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


void get_val(int &num,  int pos) {
    int temp;
    cout<<"? "<<pos<<endl<<flush;
//    fflush(stdout);
    cin>>num>>temp;
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, start, x;
    cin>>n>>start>>x;

    int high = n, low=1, mid = (high+low)/2;
    int val_high, val_low, temp;

    get_val(val_high, n);
    get_val(val_low, 1);

    while(low<=high) {
        mid = (high+low)/2;
        if(val_low < x) {
            low = mid+1;
            get_val(val_low, low);
        }
        else {
            high = mid-1;
            get_val(val_high, high);
        }
    }
    int f=0;
    if(val_low<x) {
        low++;
        get_val(val_low, low);
    }
    cout<<"! ";
    if(low>n) {
        cout<<-1<<endl<<flush;
    } else cout<<val_low<<endl<<flush;

//    exit(0);

    return 0;
}


