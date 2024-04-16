#include<bits/stdc++.h>
using namespace std;

int main(){

int y, term1=0;
cin>>y;
for(int i=y+1; i>0; i++){
    string s;
    s= to_string(i);
    term1=0;
    for(int j=0; j<4; j++){
        for(int k=0; k<4; k++){
            if(j==k){
                continue;
            }
            else{
                if(s[j]!=s[k]){
                    term1++;
                }
            }
        }
    }
    if(term1==12){
        cout<<i;
        break;
    }
}
return 0;
}