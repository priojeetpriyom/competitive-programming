#include <bits/stdc++.h>

using namespace std;
long long gcd(long long a,long long b)
{
    return (a%b==0)? b :gcd(b,a%b);
}
long long Lcm(long long a,long long b)
{
    return (a*b)/gcd(a,b);
}
long long ara[1000001];
int main()
{
    long long n;
    //int a,b;
    //prlong longf("%I64d\n",gcd(5,25));
//    while(cin>>a>>b)
//        cout<<gcd(a,b)<<endl;
    ara[1]=1,ara[2]=2,ara[3]=6;
    long long result,mx=6,x;
    //long long lcm= Lcm(num1,num2);
    for(int i=4; i<1000001; i++)
    {
        x=Lcm(Lcm(i,i-1),i-2);
        if(x>mx)
        {
            ara[i]=x;
            mx=x;
        }
        else
            ara[i]=mx;
    }
    while(scanf("%I64d",&n)==1)
    {
        //long long nums=0,num1=n,num2=n-1;
//        if(n<3)
//        {
//            printf("%I64d\n",n);
//            continue;
//        }

//        if(n==3)
//        {
//            printf("6\n");
//            continue;
//        }
//        if(n==6)
//        {
//            printf("60\n");
//            continue;
//        }
        //n-=2;


        //prlong longf("%lld\n",result);
//        while(n>0)
//        {
//            //num2=n-1;
//            //prlong longf("n %I64d\n",n);
//            if(gcd(num1,n)==1 && gcd(num2,n)==1 )
//            {
//                result*=n;
//                //break;
//            }
//            else if(Lcm(lcm,n)>mx)
//            {
//                mx=Lcm(lcm,n);
//                //break;
//                x=n;
//            }
//            if(result>mx)
//                {
//                    mx=result;
//                    x=n;
//                }
//            result= num1*num2;
////            else if(gcd(num2,n)==1)
////            {
////                if((result*(n/gcd(num1,n)) )>mx)
////                    mx=result;
////            }
////            else
////            {
////                if((result*(n/(gcd(num2,n)* gcd(num1,n))) )>mx)
////                    mx=result;
////            }
//
////            result/=gcd(num1,n);
////            result/=gcd(num2,n);
////            else if(n==2)
////                break;
//            n--;
//        }
        //printf("%lld %lld %lld\n",num1,num2,x);
//        if(mx>result)
//                result=mx;
        //result*=num2;
        //prlong longf("%I64d\n",result);
        cout<<ara[n]<<endl;
    }
    return 0;
}

// http://acm.hust.edu.cn/vjudge/contest/view.action?cid=104894#rank
