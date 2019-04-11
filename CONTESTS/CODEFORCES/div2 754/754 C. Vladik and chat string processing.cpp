
#include <bits/stdc++.h>
using namespace std;

void print_map(string cause, map<string, int> mp)
{
    cout<<"printing for: "<<cause<<endl;
    std::map<string, int>::iterator it;
    printf("\n\n");
    for(it = mp.begin(); it!= mp.end(); it++)
    {
//                printf("mp %s %d\n",it->first.c_str(), it->second);
        cout<<"mp_val "<<it->first<<" value "<<it->second<<endl;
        it->second = 0;
    }
    printf("\n\n");
}

bool valid_user(string str)
{
    int len  = str.length();
    string name;
    int j;
    for(j=0; j<len; j++)
    {
        if(str[j] == ':')
        {
            name = str.substr(0, j);
            break;
        }
    }


    for(; j<len;)
    {
        if((tolower(str[j])>= 'a' && tolower(str[j]) <='z' ) || (str[j]>='0' && str[j] <='9' ) )
        {
            for(int k = j; k<len; k++)
            {
                if(k==len-1 || !( (tolower(str[k])>= 'a' && tolower(str[k]) <='z' ) || (str[k]>='0' && str[k] <='9' ) ))
                {
                    if(( (tolower(str[k])>= 'a' && tolower(str[k]) <='z' ) || (str[k]>='0' && str[k] <='9' ))) k++;
//                        printf("entry-user %s\n", str.substr(j,k-j).c_str());
                    if(str.substr(j,k-j)== name )
                    {
//                        cout<<"user "<<name<<"str "<<str<<endl;
                        return false;
                    }
                    j = k+1;
                    break;
                }
            }
        }
        else j++;
    }
    return true;

}

int main()
{
//    freopen("myOut.txt", "w", stdout);

    int t;
    cin>>t;
    while(t--)
    {

        map<string,int> mp;

        int n;
        cin>>n;
        cin.ignore();
        string str[102],temp;
        std::map<string, int>::iterator it;
        for(int i=0; i<n; i++)
        {
            cin>>temp;
//            cout<<temp<<endl;
            mp[temp]  =0;
//            printf("mp_making %d\n", mp[temp]);
        }

        int m;
        cin>>m;
        cin.ignore();
        for(int i=0; i<m; i++)
        {
            getline(cin, str[i]);
//            cout<<str[i]<<endl;
        }

//        print_map("insert check",mp);

        bool imp=false;
        for(int i=0; i<m; i++)
        {

            if(str[i][0] != '?')
            {
                if(!valid_user(str[i]))
                {
//                    printf("not valid for %d\n", i);
                    imp = true;
                    break;
                }
                continue;

            }


            for(it = mp.begin(); it!= mp.end(); it++)
            {
//                printf("mp %s %d\n",it->first.c_str(), it->second);
//                cout<<"mp_val "<<it->first<<endl;
                it->second = 0;
            }
//            print_map("reset check",mp);

            int len = str[i].length();

            for(int j =0; j<len;)
            {
                if((tolower(str[i][j])>= 'a' && tolower(str[i][j]) <='z' ) || (str[i][j]>='0' && str[i][j] <='9' ) )
                {
                    for(int k = j; k<len; k++)
                    {
                        if(k==len-1 || !( (tolower(str[i][k])>= 'a' && tolower(str[i][k]) <='z' ) || (str[i][k]>='0' && str[i][k] <='9' ) ))
                        {
                            if(( (tolower(str[i][k])>= 'a' && tolower(str[i][k]) <='z' ) || (str[i][k]>='0' && str[i][k] <='9' ))) k++;
//                        printf("entry-user %s\n", str[i].substr(j,k-j).c_str());
                            if(mp.find(str[i].substr(j,k-j))!= mp.end() )
                            {
//                        printf("user %s\n", str[i].substr(j,k-j).c_str());
//                        printf("dhukse\n");
                                mp[str[i].substr(j,k-j)] = 1;
                            }
                            j = k+1;
                            break;
                        }
                    }
                }
                else j++;
            }
//            print_map("searching chat check",mp);
//            if(mp.find(prev)!= mp.end()) {
////                    printf("baal\n");
//                mp[prev] =1;
//            }
            if(i!= m-1)
            {
                if(str[i+1] [0] !='?')
                {
                    for(int j =0; j<20; j++)
                        if(str[i+1] [j] == ':')
                        {
//                        cout<<"next man "<<str[i+1].substr(0, j)<<endl;
                            mp[str[i+1].substr(0, j) ] = 1;
                            break;
                        }
                }
            }
//            print_map("next man check", mp);
//            cout<<"i "<<i<<endl;
            if(i!=0)
            {
//                if(str[i-1] [0] !='?') {
                for(int j =0; j<20; j++)
                    if(str[i-1] [j] == ':')
                    {
//                        cout<<"previous man "<<str[i-1].substr(0, j)<<endl;
                        mp[str[i-1].substr(0, j) ] = 1;
                        break;
                    }
//                }
            }
//            print_map("next-previous username check", mp);

            imp = true;
            for(it= mp.begin(); it!= mp.end(); it++)
            {
//                cout<<"xx>"<< it->first<<endl;
                if(it->second ==0)
                {
                    imp=false;
//                    prev = it->first;
//                    cout<<"prev "<<prev<<endl;
                    str[i].replace(0, 1, it->first);
                    break;
                }
            }
//            print_map("replace check", mp);



            if(imp)
            {
                break;
            }
        }

        string s= "-1", p;
        if(!imp)
            for(int i=0; i<m; i++)
            {
                for(int j =0; j<20; j++)
                {
                    if(str[i] [j] == ':')
                    {
//                        cout<<"previous man "<<str[i-1].substr(0, j)<<endl;
                        p = str[i].substr(0, j);
                        break;
                    }
                }
//            cout<<"s "<<s<<" p "<<p<<endl;
                if(s != "-1" && s==p)
                {
                    imp = true;
                    break;
                }
                s = p;

            }

        if(imp)
        {
            printf("Impossible\n");
        }
        if(!imp)
        {
            for(int i=0; i< m; i++)
                cout<<str[i]<<endl;
        }
        mp.clear();
        for(int i=0; i<m; i++)
            str[i].clear();
    }
    return 0;
}
