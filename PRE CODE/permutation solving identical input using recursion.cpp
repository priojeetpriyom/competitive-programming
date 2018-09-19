#include<iostream>
#include<string.h>
using namespace std;
int permutation(int i,int j,string str){


if(j==str.length()-1)
    cout<<str<<endl;

for(i=j;i<str.length();i++){
        if(str[i]!=str[i+1]){
swap(str[i],str[j]);
permutation(i,(j+1),str);
swap(str[i],str[j]);
        }
}
}
int main(){
string str;
cin>>str;
permutation(0,0,str);

}

