#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 15
int ara[11];
int ans[100100];

int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    int n;
    cin>>n;
    int sum=0;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        ara[x]++;
        sum+=x;
    }

    if(sum%3==1)
    {
        if(ara[1])
            sum-=1, ara[1]--;
        else if(ara[4])
            sum-=4, ara[4]--;
        else if(ara[7])
            sum-=7, ara[7]--;

//        else if(ara[2]>1)
//            sum=sum - 2 -2, ara[2]-=2;
//        else if(ara[5]>1)
//            sum=sum - 5 - 5, ara[5]-=2;
//        else if(ara[8]>1)
//            sum=sum - 8 - 8, ara[8]-=2;
//
    }
    else if(sum%3==2)
    {
        if(ara[2])
            sum-=2, ara[2]--;
        else if(ara[5])
            sum-=5, ara[5]--;
        else if(ara[8])
            sum-= 8, ara[8]--;
//
//        else if(ara[1]>1)
//            sum=sum - 1 - 1, ara[1]-=2;
//        else if(ara[4]>1)
//            sum=sum - 4 - 4, ara[4]-=2;
//        else if(ara[7]>1)
//            sum=sum - 7 - 7, ara[7]-=2;
    }
//    cout<<"sum "<<sum<<endl;

    if(sum %3 !=0)
    {
        for(int i=1; i<10; i+=3)
        {
            for(int j=2; j<10; j+=3)
            {
                if(ara[i] && ara[j] && (i+j)%3 == sum %3)
                {
                    sum-= (i+j);
                    ara[i]--;
                    ara[j]--;
                    i=10;
                    break;
                }
            }
            if(sum %3!=0)
                for(int j=1; j<10; j+=3)
                {
                    if(i==j && ara[i]<2) continue;
                    if(ara[i] && ara[j] && (i+j)%3 == sum %3)
                    {
                        sum-= (i+j);
                        ara[i]--;
                        ara[j]--;
                        i=10;
                        break;
                    }
                }
        }
        if(sum %3!=0)
        {
            for(int i=2; i<10; i+=3)
            {
                for(int j=2; j<10; j+=3)
                {
                    if(i==j && ara[i]<2) continue;
                    if(ara[i] && ara[j] && (i+j)%3 == sum %3)
                    {
                        sum-= (i+j);
                        ara[i]--;
                        ara[j]--;
                        i=10;
                        break;
                    }
                }
            }
        }
    }


//    cout<<"sum2 "<<sum<<endl;
    if(ara[0] == n || (sum==0) )
        return cout<<"0"<<endl,0;
    if(!ara[0] || sum%3!=0)
        return cout<<( (ara[0]>0)?"0":"-1")<<endl,0;
    int len=0;
//    int sum=0;
    for(int i=9; i>=0; i--)
    {
        while(ara[i])
        {
            ans[len++] = i;
            sum+=i;
            ara[i]--;
        }
    }
//    cout<<len<<" "<<sum<<endl;

//    for(int i = len-1; i>=0; i--)
//    {
//        if(sum %3 !=0)
//            sum-=ans[i], len--;
//        else
//            break;
//    }
//
//    while(ara[0])
//    {
//        ans[len++] = 0;
//        ara[0]--;
//    }

    for(int i=0; i<len; i++)
        cout<<ans[i];
    cout<<endl;

    return 0;
}

