/*
    algo:
    idea:

*/
#include <iostream>

using namespace std;


int ara[2020];

int main()
{
//    FAST_READ
    int n;

    cin>>n;

    for(int i=0; i<n; i++)
        cin>>ara[i];

    for(int i=0; i<n; i++) {
        for(int j= i+1; j<n; j++) {
            if(ara[i]> ara[j])
                swap(ara[i], ara[j]);
        }
    }

    cout<<ara[(n+1)/2-1]<<endl;

    return 0;
}
