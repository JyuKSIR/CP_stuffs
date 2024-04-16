#include<bits/stdc++.h>
using namespace std;

string convert(string &s);

int main()
{
    string s1;
    cin>>s1;
    convert(s1);
    string s2;
    cin>>s2;
    convert(s2);

    if(s1>s2)
        cout<<"1";
    else if(s1<s2)
        cout<<"-1";
    else if(s1==s2)
        cout<<"0";

    return 0;
}
string convert(string &s){

   for(int i=0; i<s.size(); i++)
   {
       if(s[i]<97)
       s[i]=s[i]+32;
   }
  return s;
}
