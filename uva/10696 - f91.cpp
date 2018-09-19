#include <cstdio>
#include <iostream>

using namespace std;

    int recursion(int f91) {
        if (f91>100) return f91-10;
        else return recursion(recursion((f91+11)));
        //else return recursion((f91+11));
    }

    int main()
    {
    while(1) {
        int f91;
        scanf("%d",&f91);
        if (f91 == 0) break;
        else {
            printf("f91(%d) = %d\n",f91,recursion(f91));
        }
    }
    return 0;
    }

