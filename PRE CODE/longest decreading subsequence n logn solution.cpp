#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAX 1000
int n;
int sequence[MAX], I[MAX], lds[MAX];

void LDS() {
    I[0] = INT_MAX;
    for(int i=1; i<=n; i++) {
        I[i] = INT_MIN;
        lds[i] = 0;
    }

    for(int i=1; i<=n; i++) {
        int high = n, low=0, mid;

        while(low <=high) {
            mid = (high+low)>>1;
            if(I[mid]>sequence[i])
                low = mid+1;
            else
                high = mid-1;
        }
//        printf("i %d idx %d lds_i %d\n", i, low, lds[i]);
        I[low] = sequence[i];
        lds[sequence[i]] = max(low, lds[sequence[i] ]);
//        printf("sequence_i %d lds_seq_i %d\n", sequence[i], lds[sequence[i]]);
    }
}

void print_seq(int mx) {
    int cnt=1, last = INT_MAX;

    for(int i= 1; cnt<=mx && i<100; i++) {
//        printf("i %d lds_i %d cnt %d\n", i , lds[sequence[i]], cnt);
        if(lds[sequence[i]] == cnt && sequence[i]<last)
        {
//            printf("DHUKSE\n");
            printf("%d ", sequence[i]);
            cnt++;
            last = sequence[i];
        }
    }
    printf("\n");
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    memset(rooms, 0 , sizeof rooms);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>sequence[i];
    LDS();
    int ans=0;
    for(int i=1 ; i<=n; i++) {
        ans = max(ans, lds[i]);
    }
    cout<<ans<<endl;

    print_seq(ans);

    return 0;
}



