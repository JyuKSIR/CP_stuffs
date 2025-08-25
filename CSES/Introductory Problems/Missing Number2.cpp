#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

  ll n,sum=0; cin >> n;
  ll in = n-1;
  while(in--){
    ll a; cin >> a;
    sum += a;
  }
  cout << (n*(n+1))/2 - sum;

 return 0;
}
