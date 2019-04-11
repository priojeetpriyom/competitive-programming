#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


vector <ll > vec[10];


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n, m;

    cin>>n>>m;


    int w,c;

    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &w, &c);
        vec[w].push_back(c);

    }

    for(int i=1; i<=3; i++)
        sort(vec[i].begin(), vec[i].end());

    ll ans=0;

    vector<ll>:: iterator it1, it2,it3;
    ll cost1, cost2, cost3;

//    printf("now m_left %d ans %I64d\n", m, ans);


    while(m>2) {

        cost1=cost2=cost3=0;
        it1= vec[1].end();
        if(vec[1].size()>2) {
            it1--;
            cost1+= *it1;


                it1--;
                cost1+= *it1;


                   it1--;
                cost1+= *it1;

        }
        it2 = vec[2].end();

        if(vec[2].size() && vec[1].size()) {
            cost2+= *(--it2);


                cost2+= *(-- vec[1].end());

        }
        it3 = vec[3].end();
        if(vec[3].size()) {
            cost3+= *(--it3);
        }
//        printf("cost1 %I64d cost2 %I64d cost3 %I64d ", cost1, cost2, cost3 );
        if(cost3>=cost1 && cost3 >= cost2 && vec[3].size()) {
//            printf("picked 3\n");
            ans+= cost3;
            vec[3].erase(it3);
            m-=3;
        } else if(cost2 > cost1 && cost2 > cost3 && vec[2].size() && vec[1].size()) {
//            printf("picked 2-%d\n", 1+ (vec[1].size()>0));
            ans+=cost2;
                vec[2].erase(it2);

                vec[1].erase(--vec[1].end());
                m-=3;

        } else if(cost1>cost2 && cost1 > cost3 && vec[1].size()>2) {
//            printf("picked 1- %d\n", i1);
            ans+= cost1;
            int x=3;
            while(x--)
                vec[1].pop_back();
            m-=3;
        } else {

        printf("cost1 %I64d cost2 %I64d cost3 %I64d ", cost1, cost2, cost3 );
            break;

        }

    }

    printf("now m_left %d ans %I64d\n", m, ans);

    printf("size %d vec_3", vec[3].size());
    for( it3 = vec[3].begin(); it3!= vec[3].end(); it3++) {
        printf(" %d",*it3);
    } printf("\n");

    printf("size %d vec_2", vec[2].size());
    for( it2 = vec[2].begin(); it2!= vec[2].end(); it2++) {
        printf(" %d",*it2);
    } printf("\n");

    printf("size %d vec_1", vec[1].size());
    for( it1 = vec[1].begin(); it1!= vec[1].end(); it1++) {
        printf(" %d",*it1);
    } printf("\n");

    while(m>1) {

        int i2=0;
        cost1=cost2=cost3=0;
        it1= vec[1].end();
        if(vec[1].size()>1) {
            it1--;
            cost1+= *it1;



                it1--;
                cost1+= *it1;


        }
        it2 = vec[2].end();

        if(vec[2].size()) {
            cost2+= *(--it2);

        }
//        printf("cost1 %I64d cost2 %I64d cost3 %I64d ", cost1, cost2, cost3 );
        if(cost2 >= cost1 && vec[2].size()) {
//            printf("picked 2-%d\n", 1+ (vec[1].size()>0));
            ans+=cost2;
                vec[2].erase(it2);
             m-=2;
        } else if(cost1>cost2 && vec[1].size()>1) {
//            printf("picked 1- %d\n", i1);
            ans+= cost1;
            vec[1].erase(it1, vec[1].end());
            m-=2;
        } else break;

    }


    while(m>0) {

        if(vec[1].size()) {
            ans+= *(--vec[1].end());
            vec[1].erase(--vec[1].end());
            m--;
        }else break;
    }

    printf("m_left %d set_1 %d set_2 %d set_3 %d\n", m, vec[1].size(), vec[2].size(), vec[3].size());





    cout<<ans<<endl;

    return 0;
}


