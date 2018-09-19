#include <bits/stdc++.h>
using namespace std;

int main()
{
    double nuts,capacityOfEachSection;
    int maxSections,divisors;
    while(scanf("%d %lf %d %lf",&maxSections,&nuts,&divisors,&capacityOfEachSection)==4)
    {
        double  temp=ceil(nuts/capacityOfEachSection);
        int neededSections=temp;
        //printf("%.0lf\n",neededSections);
        int neededBoxs;
        if(neededSections<=2)
            neededBoxs=neededSections;
        else if(divisors+1 <= neededSections)
        {
            neededBoxs = divisors/(maxSections-1);
            divisors= divisors - (neededBoxs*(maxSections-1));
            int usedSections = neededBoxs*maxSections;
            neededSections-=usedSections;
            //printf("%d\n",divisors);
            if(divisors>0)
            {
                neededSections=neededSections-divisors-1;
                neededBoxs++;
            }
//            printf("%d\n",neededBoxs);
//            printf("%d\n",neededSections);
            if(neededSections>0)
                neededBoxs+=neededSections;
        }
        else
        {
//            neededBoxs= divisors/(maxSections-1);
//            //divisors
            neededBoxs= ceil(temp/maxSections);
        }

        printf("%d\n",neededBoxs);
    }
    return 0;
}
