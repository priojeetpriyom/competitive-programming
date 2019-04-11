#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int root;
    int tCase, cnt;
    scanf("%d",&tCase);
    while(tCase--)
    {
        scanf("%d",&n);
        root = sqrt(n);
        cnt = 0;
        for(int i = 0; i <= root; i++){
            for(int j = 0; j <= root; j++){
                if((i * i) + (j * j) < n){
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
}
