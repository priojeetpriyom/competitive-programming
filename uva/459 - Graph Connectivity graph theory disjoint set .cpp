#include <bits/stdc++.h>
using namespace std;
int nodesRepresentatives[30];
int find_representative(int r)
{
    if(nodesRepresentatives[r]== r)
        return r;
    nodesRepresentatives[r] = find_representative(nodesRepresentatives[r]);
    return (nodesRepresentatives[r]);
}
void unionNodes(int a, int b)
{
//    printf("a %d b %d\n",a,b);
    int u,v;
    u= find_representative(a);
    v= find_representative(b);
    nodesRepresentatives[u] = v;

//    for(int j=0; j<5; j++)
//            printf("%d ", find_representative(j));
//    printf("\n");
//    find_representative(a);
//    find_representative(b);
}

int main()
{

//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w",stdout);

    int n, t;

    scanf("%d", &t);
//getchar();
    for(int i=1; i<= t; i++)
    {
//
        for(int j=0; j<30; j++)
            nodesRepresentatives[j] =j;
        char a,b, lim;
//        scanf("%c", &lim);
        scanf("\n%c",&lim);
//        scanf("\n%c \n%c",&a, &b) != NULL
        char temp[10];
//        printf("lim %c\n", lim);
//        getchar();
        int k=0;
        char c=1;
        temp[0] = 1;
        gets(temp);
        while(gets(temp))
        {
//            printf("tcasse %d %s\n",i,temp);
            if(strlen(temp)==1)
                break;
//            k++;
//            if(k>5) break;
            if(temp[0] == '\0')
                break;
            a= temp[0];
            b=temp[1];
            if(a<b)
                swap(a,b);
            unionNodes(a-'A', b-'A');
            temp[0] =0;
        }
//        printf("\n");


        bool cnt_par[30] = {false};
        lim= lim- 'A'+1;

//        for(int j=0; j<lim; j++)
//            printf("%d ", find_representative(j));

        for(int j=0; j<lim; j++)
        {
            cnt_par[find_representative(j)] = true;
        }
        int cnt=0;
        for(int j=0; j<lim; j++)
            if(cnt_par[j])
                cnt++;

        printf("%d\n", cnt);
//        if(i!=t)
            printf("\n");
//        getchar();
    }


    return 0;
}


