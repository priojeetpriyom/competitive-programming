#include <bits/stdc++.h>
using namespace std;

//bool operator< (const & lhs, const & rhs)
//{
//    return lhs>rhs;
//}
std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

string s[100005];
int num[100005];
int main()
{
//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w", stdout);
    int n,cnt=0;
    cin>>n;


    cnt=n;
    for(int i=0; i<n; i++)
    {
//        getchar();
        cin>>s[i];
        if(s[i]!= "removeMin")
            cin>> num[i];

        if(s[i]== "insert")
        {
            pq.push(num[i]);
//                cout<<s<<" "<<num<<endl;
        }
        else if(s[i]== "removeMin")
        {
            if(pq.empty())
            {
//                printf("insert 1\n");
//                printf("removeMin\n");
                cnt++;
            }
            else
            {

//                printf("removeMin\n");
                pq.pop();
            }
        }
        else
        {
            if(pq.empty())
            {
//                    printf("insert %d",num[i]);
                cnt++;
                pq.push(num[i]);
            }
            else if(num[i] == pq.top())
            {
//                printf("getMin %d\n",num);
            }
            else
            {

//                printf("i %d num %d top %d\n",i,num[i],pq.top());
                while(!pq.empty() && (num[i]>pq.top()))
                {
                    cnt++;

                    pq.pop();
                }
                if(pq.empty() || num[i]!= pq.top())
                {
                    cnt++;
                    pq.push(num[i]);
                }
//                printf("insert %d\n",num);
//                printf("getMin %d\n",num);
            }
        }
//        printf("i %d num %d top %d\n",i,num[i],pq.top());
    }
    while(!pq.empty())
        pq.pop();

    printf("%d\n",cnt);
    for(int i=0; i<n; i++)
    {

        if(s[i]== "insert")
        {
            pq.push(num[i]);
            cout<<s[i]<<" "<<num[i]<<endl;
        }
        else if(s[i]== "removeMin")
        {
            if(pq.empty())
            {
                printf("insert 1\n");
                printf("removeMin\n");
            }
            else
            {

                printf("removeMin\n");
                pq.pop();
            }
        }
        else
        {
            if(pq.empty())
            {
                pq.push(num[i]);
                printf("insert %d\n",num[i]);
                printf("getMin %d\n",num[i]);
            }
            else if(num[i] == pq.top())
            {
                printf("getMin %d\n",num[i]);
            }
            else
            {


                while(!pq.empty() && (num[i]>pq.top()))
                {
                    printf("removeMin\n");
                    pq.pop();
                }
                if(pq.empty() || num[i]!=pq.top())
                {
                    printf("insert %d\n",num[i]);
                    pq.push(num[i]);
                }
                printf("getMin %d\n",num[i]);
            }
        }

    }

    return 0;
}
