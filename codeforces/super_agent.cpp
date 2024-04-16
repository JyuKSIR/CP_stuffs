#include<bits/stdc++.h>
using namespace std;

int main(){
   string a;
   vector<vector<char>>v;
for(int i=0; i<3; ++i){
  vector<char>temp;
  for(int j=0; j<3; ++j){
    char b;
    cin>>b;
     temp.push_back(b);
  }
  v.push_back(temp);
}
a=(v[0][0]==v[2][2] && v[0][1]==v[2][1] && v[0][2]==v[2][0] && v[1][0]==v[1][2] ? "YES" : "NO");
   cout<<a;

return 0;
}