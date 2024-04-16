#include<bits/stdc++.h>
using namespace std;

int main(){
    
int n,count=0;
long long x;
cin>>x;
string s;
s=to_string(x);
n=s.size();
for(int i=0; i<n; i++){
    if(s[i]=='4' || s[i]=='7'){
        count++;
    }
}
if(count==7 || count==4){
    cout<<"YES"; 
}
else{
    cout<<"NO";
}
return 0;
}