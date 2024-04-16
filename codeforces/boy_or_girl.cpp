#include<bits/stdc++.h>
using namespace std;

int main()
{
    int step=0;
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0; i<n; i++){
        step++;
        for(int j=i+1; j<n; j++){
            if(s[i]==s[j]){
                step--;
                break;
            }
        }
    }
    if(step%2==0){
        cout<<"CHAT WITH HER!";
    }
    else{
        cout<<"IGNORE HIM!";
    }
}
