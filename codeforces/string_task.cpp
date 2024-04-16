#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1;
    cin>>s1;
    char s2[7]={'a','o','y','e','u','i'};
    int n=s1.size();
    string &s3=s1;
    for(int i=0; i<n; i++){
        if(s3[i]<97){
            s3[i]=s3[i]+32;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<6; j++){
            if(s3[i]==s2[j]){
                s3.erase(s3.begin()+ i);
                i--;
            }
        }
    }
    int a=s3.size();
    for(int i=0; i<a;i++){
        cout<<"."<<s3[i];
    }

    return 0;
}
