#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int primes[100000], len_primes;
bool gen[1000100];

int ara[1010], divs[1010] [30];
void prime_gen() {

    for(int i=2; i<1000; i++) {
        if(!gen[i]) {
            for(int j = i*i; j<= 1000100; j+=i)
                gen[j]=1;
        }
    }

    primes[len_primes++] =2;

    for(int i=3; i<1000000; i+=2)
        if(!gen[i])
            primes[len_primes++] = i;

//            printf("len_primes %d\n", len_primes);

//        for(int i=0; i<100; i++)
//            printf("%d ", primes[i]); printf("\n");

//    primes[len_primes++] = 1e9;

}

void gen_divs(int num, int pos) {

    int temp = pos;
//    int root = sqrt(num);
        int len=0;


    for(int i=0; i<len_primes; i++) {
        if(!gen[num]) break;
        while(num % primes[i]==0) {
            divs[temp] [++len] = primes[i];
            num/= primes[i];
        }
    }
    if(num>1) divs[temp] [++len] = num;

    divs[temp] [0] = len;
//    printf("pos %d len %d\n", pos, len);

}

int get_high_pos(int high, int low, int mid,int arr[],  int val) {


    while(low < high) {
        mid = (high+low)/2;
        if(arr[mid] <= val) low = mid+1;
        else high = mid;
    }

    while(low>0 && arr[low]>val) low--;

    return low;
}

int get_low_pos(int high, int low, int mid,int arr[],  int val) {


    while(low < high) {
        mid = (high+low)/2;
        if(arr[mid] <= val) low = mid+1;
        else high = mid-1;
    }
//    printf("arr_len %d : ", arr[0]); for(int i=1; i<= arr[0]; i++) printf("%d ", arr[i]); printf("\n");


//    printf("1 get_low low %d arr_low %d val %d\n", low, arr[low], val);
    while(low>0 && arr[low] >=val) {
        low--;
//        printf("low %d arr %d val %d\n", low, arr[low], val);
    }
//    printf("2 get_low low %d arr_low %d val %d\n", low, arr[low], val);

    return low;
}


int main()
{
int n,q;


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    prime_gen();



//    for(int i=1; i<=1000000; i++)
//        gen_divs(i, 1);
//
//    printf("aise\n");




    scanf("%d", &n);


    for(int i=1; i<=n; i++)
    {
        scanf("%d", &ara[i]);
        gen_divs(ara[i], i);
    }
    scanf("%d", &q);

//    for(int i=1; i<=n; i++) {
//        printf("%d => ", ara[i]);
//        for(int j=1; j<= divs[i][0]; j++) {
//            printf("%d ", divs[i][j]);
//        }
//        printf("\n");
//    }






    while(q--) {

        int l,r,x,y;
        scanf("%d %d %d %d", &l, &r, &x, &y);
        int ans=0;
        int low, high;
        for(l ; l<=r; l++) {

            low = get_low_pos(divs[l][0], 1, (divs[l][0] + 1)/2, divs[l], x);

            high = get_high_pos(divs[l][0], 1, (divs[l][0]+1)/2, divs[l ], y);
//            printf("1 l %d high %d low %d\n", l, high, low);
//            while(divs[l][low] >= x && low>0) low--;
//            while(divs[l][high]<=y && high<=divs[l][0])  high++;

//            printf("2 l %d high %d low %d\n", l, high, low);

            ans+= (high-low);


        }
        printf("%d\n", ans);

    }


    return 0;
}





