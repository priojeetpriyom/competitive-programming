#include<bits/stdc++.h>

using namespace std;




int vec[100100],ans[100100], id[100100], cum[100100];
//map<int, int> mp;

//map<int, int > :: iterator it;
//int ;

int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n, k,p, x;

    scanf("%d %d %d", &n, &k, &p);
    {
        vec[0]= 0;
        int mx= -1, mx_idx;

        int firstCons=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &vec[i]);
//            if(i<=k)
//            {
//                ara[i]= vec[i] + ara[i-1];
//                mp[ara[i]]++;
//            }
        }

        int i;
        for(i=1; i<=n && vec[i]==1; i++);
        firstCons = i-1;
//        printf("firstCon %d\n", firstCons);
        int cnt=1;
        pair<int, int> mx1, mx2;
        mx1.first=mx1.second = mx2.first = mx2.first=0;
        cum[0]=0;
        for(i=1; i<=n; i++)
        {
            if(vec[i])
            {
                int j;
                for(j=i; j<=n; j++)
                {
                    if(!vec[j]) break;
                    cum[j] = cum[j-1] +1;
                    id[j]=cnt;
                }
//                printf("j %d cum_j %d\n", j-1, cum[j-1]);
//                set<int> sset = ;
//                mp[cum[j-1] ] = cnt;

                if(cum[j-1] >= mx1.first)
                {
//                    printf("j %d cum_j %d\n", j-1, cum[j-1]);

                    mx2 = mx1;

                    mx1.first = cum[j-1];
                    mx1.second = cnt;
                }
                else if(cum[j-1] >= mx2.first)
                {
                    mx2.first = cum[j-1];
                    mx2.second  = cnt;
                }

                if(cum[j-1] > ans[0]) ans[0] = cum[j-1];
//                ans[0] = max(ans[0], cum[j-1]);
                i=j;
                cnt++;
            }
        }
//        printf("mx1 %d,%d mx2 %d,%d\n", mx1.first, mx1.second, mx2.first, mx2.second);
//        mp[0];


//        it = mp.end();
//        it--;


//        mx = vec[n];
        int pre_mx;
//        it = mp.end();
//        it--;
        if( mx1.second!= id[n])
        {
            pre_mx = mx1.first;
        }
        else if(mx2.second != id[n])
        {
            pre_mx = mx2.first;
        }
        else
            pre_mx = 0;

//        printf("pre_max %d on last_pre_calc\n", pre_mx);
        int x=0;
        for(i=n; vec[i]; i--)
        {
            x= firstCons+ (n-i+1);
            ans[n-i+1] = max(pre_mx,  max(cum[n]-(n-i+1), x));
        }

        if(x> mx1.first) {
            swap(mx1, mx2);
            mx1.first = x;
            mx1.second=1;
        } else if(x> mx2.first) {
            mx2.first=x;
            mx2.second=1;
        }
//        printf("now mx1 %d,%d mx2 %d,%d\n", mx1.first, mx1.second, mx2.first, mx2.second);
//        printf("i now %d\n", i);
//        if(mp[firstCons].find(1) != mp[firstCons].end())
//        if(mp[firstCons]==1) mp.erase(mp.find(firstCons));
//        if(mp.find(x) == mp.end()) mp[x]=1;
        ans[n+1] = ans[0];
        for( ; i>0; i--)
        {
            if(vec[i])
            {
                int j = i;
                if( mx1.second!= id[i])
                {
                    pre_mx = mx1.first;
                }
                else if(mx2.second != id[i])
                {
                    pre_mx = mx2.first;
                }
                else
                    pre_mx = 0;

                while(vec[j])
                {
                    ans[n-j+1] = max(pre_mx, max(cum[i]-(i-j+1), (i-j+1) ));
//                    printf("j %d pre_mx %d right %d left %d ans_j %d\n", j, pre_mx, cum[i]- (i-j+1), (i-j+1), ans[n-j+1]);
                    j--;
                }
                i=j;

            }

        }
//        ans[n] = ans[0];
        for(i = 1; i<=n; i++)
            if(!ans[i]) ans[i] = ans[i-1];

//        for(int i=0; i<=n; i++) printf("%d ", ans[i]);printf("\n");
//        printf("aise\n");


        char c;
        cnt=0;

        while(p)
        {
            scanf("\n%c", &c);
//            ;

            if( c=='!')
            {
//                printf("p %d ! e aise\n",p);
                cnt++;

//                p--;
            }
            else if(c=='?')
            {
                cnt%=n;

                printf("%d\n", min(ans[cnt], k));
            }
            p--;
        }

    }


}

