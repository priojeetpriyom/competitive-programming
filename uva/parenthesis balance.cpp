//special input" 1 ((()))][][ " check condition 23!! return 0 dosent work!
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
using namespace std;
stack <char> S;
int bal_check(char str[],int len) {
    int f=0,t=0;
    char top;
    for (int i=0;i<len;i++) {
         //cout<<"i "<<i<<endl;//return 0;
        if(str[i] == '(' || str[i] == '[')
            {
                S.push(str[i]);
                if(str[i] == '(') f++;
                else t++;
            }
        else if(str[i] == ']' || str[i] == ')') {
            //printf("%c %c\n",S.top(),str[i]);
            if(str[i]== ')') f--;
            else t--;
            if(S.empty()) {
                //printf("%c\n",str[i]);
                    return 0;
                    break;
                //printf("ball\n");
            }
            else if(str[i]== ')') {
                top=S.top();
                if(top == '[') return 0;

            }
            else {
                top = S.top();
                if(top == '(') return 0;

            }
           // printf("%c %c\n",str[i],S.top());
            S.pop();
        }
//        if(S.empty() && i<len-1) return 0;
//            {
//            cout<<"i "<<i<<endl;
//            return 0;
//        }
            ////
    }
    //printf("frst %d thrd %d\n",f,t);
    if(f==0 && t==0)
        return 1;
    return 0;

}

int main ()
{
    int t,len,i;
    //bool first=false,third=false;
    char str[200],c;
    while (scanf("%d",&t)==1) {
        getchar();
    while (t--) {

        gets(str);
        len = strlen(str);
        str[len] = '\0';
        if(str[0] == '\0') {
            printf("Yes\n");
            continue;
        }
        if(bal_check(str,len)==1)
            printf("Yes\n");
        else printf("No\n");
        while (!S.empty()) S.pop();
    }
    }
    return 0;
}
