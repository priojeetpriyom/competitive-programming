#include <bits/stdc++.h>
using namespace std;
//vector<int> vec;
vector <pair<int,int> > vec;
int main()
{
//    freopen("myOut.txt", "w", stdout);
    int q1,q2,q3,q4;
    int cnt1, cnt2, cnt3, cnt4;

//    vector <queue> vec[10];
    char c;
    int x,y;
    int q;
    scanf("%d", &q);
//    while(scanf("%d", &q)==1)
//    {
        q1 = q2 = q3 = q4 = 0;
        cnt1 = cnt2 = cnt3 = cnt4 =0;
//        vec.push_back(make_pair(INT_MAX, INT_MAX));
        while(q--)
        {
            scanf("\n%c", &c);
            if(c == 'E')
            {
                scanf("%d %d", &x, &y);
                if(x==1)
                {
                    q1 = max(q1,0);
                    if(cnt1 != 0)
                    {
                        if(q2 > q1)
                            q2++;
                        if(q3 > q1)
                            q3++;
                        if(q4 > q1)
                            q4++;
                        vec.insert(vec.begin()+q1, make_pair(x,y));
                        q1++;
                    }
                    else
                    {
                        vec.push_back(make_pair(x,y));
                        q1 = vec.size();
                    }
                    cnt1++;
                }
                else if(x == 2)
                {
                    q2 = max(q2,0);
                    if(cnt2 != 0)
                    {
                        if(q1 > q2)
                            q1++;
                        if(q3 > q2)
                            q3++;
                        if(q4 > q2)
                            q4++;
                        vec.insert(vec.begin()+q2, make_pair(x,y));
                        q2++;
                    }
                    else
                    {
                        vec.push_back(make_pair(x,y));
                        q2 = vec.size();
                    }
                    cnt2++;
                }
                else if(x == 3)
                {
                    q3 = max(q3,0);
                    if(cnt3 != 0)
                    {
                        if(q2 > q3)
                            q2++;
                        if(q1 > q3)
                            q1++;
                        if(q4 > q3)
                            q4++;
                        vec.insert(vec.begin()+q3, make_pair(x,y));
                        q3++;
                    }
                    else
                    {
                        vec.push_back(make_pair(x,y));
                        q3 = vec.size();
                    }
                    cnt3++;
                }
                else
                {
                    q4 = max(q4,0);
                    if(cnt4 != 0)
                    {
                        if(q2 > q4)
                            q2++;
                        if(q3 > q4)
                            q3++;
                        if(q1 > q4)
                            q1++;
                        vec.insert(vec.begin()+q4, make_pair(x,y));
                        q4++;
                    }
                    else
                    {
                        vec.push_back(make_pair(x,y));
                        q4 = vec.size();
                    }
                    cnt4++;
                }
            }
            else
            {
                printf("%d %d\n",vec[0].first, vec[0].second);
                int z = vec[0].first;
                if(z==1)
                {
                    cnt1--;
                    q1--;
//                    if( cnt1 ==0)
//                        q1=0;
                    q2--;
                    q3--;
                    q4--;
                }
                else if(z==2)
                {
                    cnt2--;
                    q2--;
//                    if( cnt2 ==0)
//                        q2=0;
                    q1--;
                    q3--;
                    q4--;
                }
                else if(z==3)
                {
                    cnt3--;
                    q3--;
//                    if( cnt3 ==0)
//                        q3=0;
                    q2--;
                    q1--;
                    q4--;
                }
                else
                {
                    cnt4--;
                    q4--;
//                    if( cnt4 ==0)
//                        q4=0;
                    q2--;
                    q3--;
                    q1--;
                }
                vec.erase(vec.begin());





            }
//            printf("input ");
//            if(c=='E')
//                printf("%c %d %d\n", c, x, y);
//            else
//                printf("%c\n", c);

//            printf("vec ");
//            for(int i=0; i< vec.size(); i++)
//                printf("%d %d, ",vec[i].first, vec[i].second);
//            printf("\n");
//            printf("q1 %d q2 %d q3 %d q4 %d\n", q1, q2, q3, q4);
        }
//        vec.clear();
//    }
    return 0;
}
