#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
int prefer[1010][555];
int company_contract[1010];
void make_stable_employment()
{
    vector<map<int, int> > company_preference;
    for(int i= n+1; i<= (n<<1); i++)
    {
        map<int, int> rankk;
        for(int j=1; j<=n; j++)
        {
            rankk[prefer[i][j] ] = j;
        }
//        printf("rankk size %d\n",rankk.size());
        company_preference.push_back(rankk);
    }
//    printf("size %d\n", company_preference.size());
    queue<int> employee_queue;
    for(int i=1; i<=n; i++)
    {
        employee_queue.push(i);
    }

    while(!employee_queue.empty())
    {
        int cur_employee = employee_queue.front();

//        printf("cur_employee %d\n", cur_employee);
        employee_queue.pop();

        for(int i=1; i<=n; i++)
        {
            int cur_company = prefer[cur_employee] [i];
            if(!company_contract[cur_company])
            {
                company_contract[cur_company] = cur_employee;
//                printf("company %d contract %d\n",cur_company, company_contract[cur_company]);
                break;
            }
            else
            {
//                printf("oka company %d\n", cur_company);
                map<int, int> rankk = company_preference[cur_company - n-1];
//                printf("oka2\n");
                if(rankk[cur_employee] < rankk[company_contract[cur_company] ])
                {
                    employee_queue.push(company_contract[cur_company]);
                    company_contract[cur_company] = cur_employee;

//                printf("company %d contract %d\n",cur_company, company_contract[cur_company]);
                    break;
                }
            }
        }
    }
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int t;
    cin>>t;

    for(int tc=1; tc<=t; tc++)
    {
        memset(company_contract, 0 , sizeof company_contract);
        scanf("%d", &n);
        for(int i=1; i<= (n); i++)
        {
            int x;
            scanf("%d", &x);
            for(int j=1; j<=n; j++)
            {
                scanf("%d", &prefer[x][j]);
                prefer[x][j]+=n;
            }
        }
        for(int i=n+1; i<= (n<<1); i++)
        {
            int x;
            scanf("%d", &x);
            x+=n;
            for(int j=1; j<=n; j++)
            {
                scanf("%d", &prefer[x][j]);
            }
        }
//        printf("oka\n");
        make_stable_employment();
//        printf("Case %d:", tc);
        for(int i=n+1; i<= (n<<1); i++)
        {
            printf("%d %d\n", i-n, company_contract[i]);
            company_contract[i]=0;
        }
//        printf("\n");

    }

    return 0;
}



