#include <bits/stdc++.h>
using namespace std;

int ara[111];
int sortedAra[2] [111];

int findPos (int data, int high, int low, int mid) {

    while(sortedAra[0] [mid] != data)
     {
         if(sortedAra[0][mid]>data)
            high = mid-1;
         else
            low= mid+1;
         mid=(high+low)/2;
     }
       return mid;
}

int main()
{
//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w", stdout);
    int n;

    scanf("%d",&n);
    bool isPreSorted=true;
    for(int i=0; i<n; i++) {
        scanf("%d",&ara[i]);
        if(i!=0 && ara[i]< ara[i-1])
            isPreSorted=false;
        sortedAra[0] [i]=ara[i];
        sortedAra[1] [i]=i;

    }
    if(isPreSorted)
        return 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(sortedAra[0][i]> sortedAra[0][j]) {
                swap(sortedAra[0][i],sortedAra[0][j]);

                swap(sortedAra[1][i],sortedAra[1][j]);
            }
        }
    }
//    for(int i=0; i<n; i++)
//        printf("%d ",sortedAra[0][i]);
//    printf("sorted ara finished\n");

    for(int k=0; k<n;k+=1) {
//            printf("i %d s-i %d sortedara %d ",k,sortedAra[1][k],sortedAra[0][k]);
           int currentPos = sortedAra[1][k];
        while(ara[k]!=sortedAra[0][k]) {


            printf("%d %d\n",currentPos,currentPos+1);
            swap(ara[currentPos],ara[currentPos-1]);
            sortedAra[1] [ findPos(ara[currentPos],n-1,0,((n-1)/2))]= currentPos;
            currentPos--;
//            getchar();
        }
    }

    return 0;
}

