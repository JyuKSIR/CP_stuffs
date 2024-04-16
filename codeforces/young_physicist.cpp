#include<bits/stdc++.h>
using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

  int n,x,y,z,xsum=0,ysum=0,zsum=0;
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>x>>y>>z;
    xsum+=x;
    ysum+=y;
    zsum+=z;
  }
  if(xsum==0 && ysum==0 && zsum==0){
    cout<<"YES";
  }
  else{
    cout<<"NO";
  }
  return 0;
}