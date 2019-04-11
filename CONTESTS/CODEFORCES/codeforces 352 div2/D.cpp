#include <bits/stdc++.h>
using namespace std;
int people[500001];
int main()
{
//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w",stdout);

    int n, k;
    long long avg=0;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&people[i]);
        avg+= people[i];
    }
    sort(people, people+n);
    avg/= n;
    int allEqual = 0;
    int richest = n-1, poorest=0;
    while(k>0 && allEqual!=n)
    {
//        printf("dekhi\n");
//        allEqual = 0;
        if(people[richest] != avg)
        {
            allEqual--;
            int coins;
//            if(people[richest] > avg)
//            {
            if((people[richest] - avg)<= k)
            {
                people[richest]  = people[richest] -avg;
                coins = avg;
                k = k - avg;
                richest--;
            }
            else
            {
//                printf("yes");
                people[richest] -=k;
                coins = k;
                k=0;
            }
//printf("coins %d    ",coins);
            while(coins>0)
            {
//                printf("coin %d avg %I64d poorest %d\n",coins,avg, people[poorest]);
                if((avg-people[poorest]) <=coins)
                {
                    coins-= (avg - people[poorest]);
                    people[poorest] += (avg - people[poorest]);

                    poorest++;
                }
                else
                {
                    people[poorest] += coins;
                    coins =0 ;
                }

                if(poorest == n)
                {

                    people[poorest-1] += coins;
                    break;
                }
            }
//            }
        }
        else
            allEqual++;
    }
//    bool equality = true;
//    for(int i=0; i<n; i++)
//    {
//        if(people[i] != avg)
//        {
//            equality=false;
//            break;
//        }
//    }
//    for(int i=0; i<n; i++)
//        printf("%d ", people[i]);
//    printf("\n");
    sort(people, people+n);
    printf("%d\n",people[n-1]- people[0]);

    return 0;
}

