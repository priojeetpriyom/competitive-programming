#include <bits/stdc++.h>

using namespace std;
struct node
{
    struct node* characters[11];
    bool endmark=false;
    node()
    {
        for(int i=0; i<10; i++)
        {
            characters[i] = NULL;
        }
    }
};
node* root;
bool prefix;
void addNumber(char str[], int len)
{
    node* current= root;
    for(int i=0; i<len; i++)
    {
        if(current->endmark == true)
        {
            prefix=true;
            break;
        }
        if(current->characters[str[i]-'0'] ==NULL)
        {
            current->characters[str[i]-'0'] = new node();
        }
            current= current->characters[str[i]-'0'];
    }
    for(int i=0; i<10; i++)
        if(current->characters[i]!= NULL)
        {
            prefix=true;
            break;
        }
    current->endmark = true;
}
void del(node* ptr)
{
    if(ptr== NULL)
        return;
    for(int i=0; i<26; i++)
    {
        del(ptr->characters[i]);

    }
    delete(ptr);
}
int main()
{
    int t,n;
    char str[11];
    scanf("%d",&t);
    while(t--)
    {
        root= new node();
        prefix=false;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("\n%s", str);
            if(!prefix)
                addNumber(str, strlen(str));

        }
        if(prefix)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}



