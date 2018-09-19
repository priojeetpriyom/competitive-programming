#include <bits/stdc++.h>
using namespace std;

map <string, string> animals;
string find_representative(string r)
{
    if(animals[r]== r)
        return r;
    animals[r] = find_representative(animals[r]);
    return (animals[r]);
}
void unionNodes(string a, string b)
{
//    printf("a %d b %d\n",a,b);
    string u,v;
    u= find_representative(a);
    v= find_representative(b);
    animals[u] = v;

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

    int c,r;

//    scanf("%d", &t);
//getchar();
    while(scanf("%d %d",&c, &r)==2)
    {
        if(c== 0 && r==0)
            break;

        string temp;
        for(int j=0; j<c; j++)
        {getchar();
            cin>>temp;

            animals[temp] = temp;
//            cout<<"temp "<<animals[temp]<<endl;
        }

        int cnt=0;
        for(int j=0; j<r; j++)
            {
                 getchar();
                string a,b;
                cin>>a>>b;
//                cout<<"a "<<a<<" b "<<b<<endl;
                unionNodes(a,b);
            }
        map<string, int> frequency;
        int mx=0;

//        for(map<string,string>:: iterator it = animals.begin(); it!= animals.end(); ++it)
//        {
//            cout<< find_representative(it->first)<< " "<< find_representative(it->second)<<endl;
//        }
//        for(map<string,string>:: iterator it = animals.begin(); it!= animals.end(); ++it)
//        {
//            cout<< (it->first)<< " "<< (it->second)<<endl;
//        }

         for(map<string,string>:: iterator it = animals.begin(); it!= animals.end(); ++it)
         {
             int x = ++frequency[find_representative(it->second)];
             if(x>mx)
                mx=x;


         }

        printf("%d\n", mx);
//        if(i!=t)
//            printf("\n");
        animals.clear();
        frequency.clear();
//        getchar();
    }
//    printf("\n");

    return 0;
}


