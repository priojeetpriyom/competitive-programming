#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



vector<int> ara;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin>>n>>k;


    if(n==2) {
        if(k==0) {
            cout<<"NO"<<endl;
            return 0;
        }
    }



    cout<<"YES"<<endl;
    if(n==1)
    {
        cout<<k<<endl;
    }
    else if(n==2)
    {

        cout<<0<<" "<<k<<endl;
    }
    else if(n==3)
    {
        if(k==0) {
            cout<<"1 2 3"<<endl;
        } else {
            int pw = ceil(log2(max(n, k)));
            while( (1<<pw) <= k) pw++;
            cout<<"0 "<<(1<<pw)<<" "<<( (1<<pw)+k)<<endl;
        }
    }
    else
    {
        int val=0;
        for(int i=1; i<n-1; i++)
        {
            ara.push_back(i);
            val^=i;
        }
        int temp_n = n;

        if(val==k)
        {

            ara.pop_back();
//            int temp;
            val^= (n-2);
            temp_n = n-1;

            while (1) {
                if( (val^temp_n) != k) {
                    val ^= temp_n;
                    ara.push_back(temp_n);
                    break;
                }
                temp_n++;
            }

        }
//        else
//        {
            int pw = ceil(log2(max(temp_n, k)));
//            printf("val %d pw %d\n", val, pw);
            while((1<<pw)<=k) pw++;
            ara.push_back( ( (1<<pw) +val) );
            ara.push_back( ( (1<<pw)+k ) );
//            cout<<( (1<<pw) +val) <<" "<< ( (1<<pw)+k )<<endl;
//        }





    }
    int len = ara.size();
    for(int i=0; i<len; i++)
        printf("%d ", ara[i]);
    printf("\n");




    return 0;
}


