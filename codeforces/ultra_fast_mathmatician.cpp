#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
string sx;
string sy;
getline(cin, sx);
getline(cin, sy);
n=sx.size();
for(int i=0; i<n; i++){
    if(sx[i]!=sy[i]){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
}
return 0;
}