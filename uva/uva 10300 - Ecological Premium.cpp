#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
    int t,f,space[100],animal[100],enviorment[100],i,j,k, total_cost;
    scanf ("%d",&t);
    for (i = 0; i<t; i++) {
        total_cost = 0;
        scanf("%d",&f);
        for (j=0; j<f; j++) {
            scanf("%d %d %d",&space[j],&animal[j],&enviorment[j]);
            total_cost = total_cost + space[j] * enviorment[j];
        }
        printf("%d\n",total_cost);
    }
    return 0;
}
