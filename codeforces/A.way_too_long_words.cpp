#include<bits/stdc++.h>
using namespace std;

string answer(string strr);

int main()
{
    int n;
    cin>>n;
    string str[n];
    for(int i=0; i<n; i++){
        cin>>str[i];
    }
    for(int i=0; i<n; i++)
    {
        answer(str[i]);
    }
    return 0;
}
string answer(string strr){
    if(strr.size()>10){

    cout<<strr[0]<<strr.size()-2<<strr[strr.size()-1]<<endl;

    }
    else{
        cout<<strr<<endl;
    }
    return strr;
}

