#include <bits/stdc++.h>
using namespace std;

map <string, string> peoples;

string find_mutual_friend(string person)
{
    if(person == peoples[person])
        return person;
//    cout<<"func "<< person<<" "<< peoples[person]<<endl;
    peoples[person] = find_mutual_friend(peoples[person]);
    return peoples[person];

}

void make_friends(string a, string b)
{
    string u = find_mutual_friend(a), v= find_mutual_friend(b);

    peoples[u] = v;
}
int main()
{
//
//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w",stdout);

    int t;
    scanf("%d",&t);

//    scanf("%d", &t);
//getchar();
    while(t--)
    {
        int f;
        scanf("%d",&f);
        int cnt=0;

        string a,b;
        map<string, int> frequency;
        for(int j=0; j<f; j++)
        {
            getchar();

            cin>>a>>b;
//            cout<<a <<" "<<b<<endl;
            map<string,string>:: iterator parent1 = peoples.find(a);
            map<string,string>:: iterator parent2 = peoples.find(b);

            if(parent1 == peoples.end())
            {
                if(parent2 == peoples.end())
                {
//                    cout<<a <<" "<<b<<" parent nai"<<endl;
                    peoples[a] = b;
                    peoples[b] = b;
                    if(a==b)
                        {
                            printf("1\n");
                            frequency[b]=1;

                        }
                    else
                    {
                        printf("2\n");
                        frequency[b]=2;

                    }
                }
                else
                {
                    b = find_mutual_friend(b);
                    peoples[a] = b;
                    frequency[b]++;
                    printf("%d\n", frequency[b]);

                }
            }
            else if(parent2 == peoples.end())
            {
//                cout<<"aisilo "<<peoples[a]<<"\n";
                a= find_mutual_friend(a);
//                printf("aynai\n");
                peoples[b] = a;
                frequency[a]++;
                printf("%d\n", frequency[a]);
            }
            else
            {
                a = find_mutual_friend(a);
                b = find_mutual_friend(b);
                if(a==b)
                    printf("%d\n",frequency[a]);
                else
                {
                    frequency[a]+= frequency[b];
                    frequency[b]= 0;
                    peoples[b] = peoples[a];
                    printf("%d\n", frequency[a]);
                }
            }
//            make_friends(a,b);
//            printf("%d\n", cnt);
//            cout<<"temp "<<animals[temp]<<endl;
        }
;
        peoples.clear();

    }

    return 0;
}


