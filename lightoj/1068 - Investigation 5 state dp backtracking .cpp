/*
    algo:
    idea:

*/
//
//
//#include<stdio.h>
//#include<string.h>

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 11

int tc, k;
ll dp[11][100][5][5][100];
vector<int> a, b;
ll  x, y;



int lim;

void inflate(ll num, vector<int> &vec);

ll rec(int pos, int dsum,int compa,  int compb, int tsum) {
    if(compa==1 || compb==2)
        return 0;
//    if(pos == lim)
//    cout<<"pos "<<pos<<" dsum "<<dsum<<" compb "<<compb<<" path "<<path<<endl;
    if (pos == lim) {
        return ( !dsum && !tsum && compa!=1 && compb!=2);
    }

//    cout<<"R "<<r<<" B "<<b<<endl;

    ll &ret = dp[pos][dsum][compa][compb][tsum];

    if (~ret) {
        return ret;
    }
    ret = 0;

    for (int i = 0; i <=9 ; i++) {
//        int temp_start;
//        if(!start) {
//            temp_start = (i>0)? pos+1:0;
//        }
//        if(!compb && i>b[pos])
//            breakst& i<a[pos])
//            continue;
        int tempa = compa, tempb = compb;
        if(!compa && i!= a[pos]) {
            if((i>a[pos])) {
                tempa=2;
            } else if(i < a[pos]) {
                tempa=1;
            }
        }
        if(!compb && i!= b[pos]) {
            if(i>b[pos])
                tempb=2;
            else
                tempb =1;
        }
//        path = path * 10 + i;
        ret += rec(pos + 1, (dsum + i)%k, tempa, tempb, ((tsum*10)+i)%k);
//        path = (path - i) / 10;
    }
        return ret;

}


int main()
{
//freopen("output.txt", "w", stdout);

  int t;

  scanf("%d", &t);

  for(tc=1; tc<=t; tc++)
  {
      memset(dp, -1, sizeof dp);
      scanf("%lld %lld %d",&x, &y, &k);

      inflate(x, a);
      inflate(y, b);
      lim = b.size();
      vector<int> temp;
      while(temp.size()+a.size() != b.size()) {
          temp.push_back(0);
      }
      a.insert(a.begin(), temp.begin(), temp.end());

//      for(auto i: a)
//          cout<<i;
//      cout<<endl;

//      cout<<"a "<<a.size()<<" b "<<b.size()<<endl;

      ll ans=0;
      if(k<100) {
          ans = rec(0, 0, 0, 0, 0);
      }
      printf("Case %d: %lld\n", tc, ans);


  }


    return 0;
}

void inflate(ll num, vector<int> &vec) {
    vec.clear();
//    cout<<"num "<<num<<endl;
    do {
//        cout<<"num "<<num<<" num_digit "<<num%10<<endl;
        vec.push_back(num%10);
        num/=10;
    } while(num>0);

    reverse(vec.begin(),  vec.end());

//    for(int i=0; i<vec.size(); i++)
//        cout<<vec[i];
//    cout<<"\n ^vec_eles"<<endl;

}
