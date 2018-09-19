#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define N 4
int bond[N<<1];

void make_marriage_stable(int prefer[2*N][N])
{
    queue<int> male_queue;
    for(int i=0; i<N; i++)
        male_queue.push(i);

    vector<map<int, int> > women_choice;
    for(int i=N; i< (1<<N); i++)
    {
        map<int, int> mp;
        for(int j=0; j<N; j++)
        {
            mp[prefer[i][j] ] = j;
        }
        women_choice.push_back(mp);
    }

//    for(int i=0; i<N; )

    while(!male_queue.empty())
    {
        int male = male_queue.front();
        male_queue.pop();

        for(int i=0; i<N; i++)
        {
            if(bond[prefer[male][i] ] == -1)
            {
                bond[prefer[male][i] ] = male;
                break;
            }
            else
            {
                int women = prefer[male][i];
                map<int, int> & rankk = women_choice[women-N];
                if(rankk[male] < rankk[bond[women] ] )
                {
                    male_queue.push(bond[women]);
                    bond[women] = male;
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
memset(bond, -1, sizeof bond);
    int prefer[2*N][N] = { {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
    make_marriage_stable(prefer);
        // Print the solution
    cout << "Woman   Man" << endl;
    for (int i = 0; i < N; i++)
       cout << " " << i+N << "\t" << bond[N+i] << endl;
    return 0;
}



