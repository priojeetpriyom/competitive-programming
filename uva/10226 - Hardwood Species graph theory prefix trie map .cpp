#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w", stdout);
    int t,total;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--){
        char str[31];
        total=0;
        map<string, double> species;
        while(gets(str) && str[0]!='\0') {
            total++;
            species[str]++;
//            printf("%lf\n", species[str]);
        }

        for(std:: map<string,double>:: iterator it= species.begin(); it!= species.end(); it++) {
            printf("%s %.4lf\n",it->first.c_str(), ((it->second)/total)*100);
        }
        if(t!=0)
            printf("\n");
    }
    return 0;
}
