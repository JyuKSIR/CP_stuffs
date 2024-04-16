#include<bits/stdc++.h>
using namespace std;

#define in(s) cin>>s
#define zero cout<<"0"
#define one cout<<"1"
#define two cout<<"2"
#define plus i++

int main(){


string s;
in(s);
int n=s.size();
for(int i=0; i<n; i++){
    if(s[i]=='-'&& s[i+1]=='-'){
        two;
        plus;
    }
    else if(s[i]=='-'&& s[i+1]=='.'){
        one;
        plus;
    }
    else{
        zero;
    }
}

return 0;
}