#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n, l;
    int ara1[100], ara2[100];
    cin>>n>>l;
    for(int i=0; i<n; i++)
        cin>>ara1[i];
    for(int i=0; i<n; i++)
        cin>>ara2[i];


    if(n==1)
    {
        printf("YES\n");
        return 0;
    }

//    if(ara1[0] > ara2[0] && (ara1[1] - (ara2[1] - ara2[0]>=0 ))) {
//        ara1[0] = ara1[1] - (ara2[1] - ara2[0]);
//    } else if(ara1[0] < ara2[0] && (ara2[1] - (ara1[1] - ara1[0])>=0)) {
//        ara2[0] = ara2[1] - (ara1[1] - ara1[0]);
//    }
    map<int, int>mp1, mp2;
    ara1[n] = ara1[0]+l;
    ara2[n] = ara2[0]+l;
    for(int i=1; i<=n; i++)
    {
        mp1[(ara1[i] - ara1[i-1])]++;
        mp2[(ara2[i] - ara2[i-1])]++;
//        if( (ara1[i] - ara1[i-1]) != (ara2[i] - ara2[i-1]))
//        {
////            printf("i %d\n", i);
//            printf("NO\n");
//            return 0;
//        }
    }
    int cnt=0;
    map<int,int>::iterator it1 = mp1.begin(), it2 = mp2.begin();
    for( ; it1!= mp1.end(); it1++, it2++) {
        if(mp2.find(it1->first)==mp2.end() || it1->second != mp2[it1->first]) {
            cnt++;

        }
    }
    if(cnt>1)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;

}


