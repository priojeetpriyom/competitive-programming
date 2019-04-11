#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOut.txt", "w", stdout);
    int x1,x2,x3,x4,y1,y2,y3,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    int arrx[10], arry[10];

    x4 = (x1-x2);
    y4 = (y1-y2);
    int len=0;
    arrx[len] = x3+ x4;
    arry[len++] = y3+y4;
    arrx[len] = x3- x4;
    arry[len++] = y3-y4;

    x4 = (x2-x3);
    y4 = (y2- y3);
    arrx[len] = x1+ x4;
    arry[len++] = y1+y4;
    arrx[len] = x1- x4;
    arry[len++] = y1-y4;


    cout<<3<<endl;

    for(int i=0; i<len; i++) {
        bool print = true;
        for(int j = i+1; j<len; j++) {
            if(arrx[i] == arrx[j] && arry[i] == arry[j])
            {
                print = false;
                break;
            }
        }
        if(print)
            printf("%d %d\n", arrx[i], arry[i]);
    }
    return 0;
}


