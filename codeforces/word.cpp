#include<bits/stdc++.h>
using namespace std;

int main(){

int n, upcount=0,lowcount=0;
string s;
cin>>s;
n=s.size();
for(int i=0; i<n; i++){
    if(s[i]>96){
        lowcount++;
    }
    else if(s[i]<97){
        upcount++;
    }
}
if(lowcount>upcount){
    for(int i=0; i<n; i++){
        if(s[i]<97){
            s[i]=s[i]+32;
        } 
    }
}
else if(lowcount<upcount){
    for(int i=0; i<n; i++){
        if(s[i]>96){
            s[i]=s[i]-32;
        } 
    }
}
else{
    for(int i=0; i<n; i++){
        if(s[i]<97){
            s[i]=s[i]+32;
        } 
    }
}
cout<<s;

return 0;
}