#include<bits/stdc++.h>
using namespace std;
int ara[100005],ara_sorted[100005];

int findd(int high, int low, int data) {
    int mid;

    while(low<=high) {
        mid = (high+low)/2
        if(ara_sorted[mid]==data)
            return
    }
}

int main ()
{
//    scanf("%d",&t);

    map<int,int> nums,freq;

    int powers[100],len_powers=0;
    for(int i=1; i<1000000;i= i*2)
    {
        powers[len_powers++] = i;
    }
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        int x;
        scanf("%d",&ara[i]);
        ara_sorted[i] = ara[i];
    }

    sort(ara_sorted,ara_sorted+n);

    int cnt=0;
    for(int k=0; k<n;k++) {

        for(int i=0; i<len_powers;i++) {
            if(!(nums.find(powers[i]-ara[k])== nums.end()))
            {
                if(k< nums[powers[i]-ara[k]])
                    {cnt++;
//                        cnt+=freq[powers[i]-ara[k]];
//                        if(ara[k] == (powers[i]-ara[k]))
//                            cnt--;
                    }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}

