#include<bits/stdc++.h>
using namespace std;

int main(){
    int stoneNumber;
    int step=0;
    string s;
    cin>>stoneNumber>>s;
    for(int i=0; i<stoneNumber-1; i++){
            if(s[i]==s[i+1]){
                step++;
            }
         }
    cout<<step;
   return 0;
}