///
///
///complexity:O(sqrt(maxNum)+QlogQ)

#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 200100

vector<int> divs;
set<int> common;

int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;

    cin>>a>>b;
    if(a>b)
        swap(a, b);

    int root = sqrt(a)+1;

    for(int i=1; i<root; i++) {
        if(a%i==0) {
            if(b%i==0) {
                common.insert(i);
            }
            int temp = a/i;
            if(i != temp) {
                if(b %temp==0) {
                    common.insert(temp);
                }
            }
        }
    }

    common.insert(0);
    common.insert(2e9);
//    for(auto i : common)
//        cout<< i<<" ";
//    cout<<endl;


    int n;
    cin>>n;

    while(n--) {
        int low, high;

        cin>>low>>high;
        set<int>::iterator it = common.lower_bound(high);
////        cout<<*it<<endl;
        if(*it!= high)
            it--;

        if(*it>=low && *it <=high)
            cout<<*it<<endl;
        else
            cout<<-1<<endl;
    }




    return 0;
}


