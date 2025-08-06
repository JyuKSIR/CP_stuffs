#include<bits/stdc++.h>
#define ll long long
#define ld long double
 
using namespace std;

const ll x = 1e6+10;
vector<ll> fq(x,0), ct(x,0);
 
int main(){
 
  ll n; scanf("%lld", &n);
  for(ll i = 0; i < n; i++){
    ll p; scanf("%lld", &p);
    fq[p]++;
  }
 
  for(ll i = 2; i < x; i++){
    for(ll j = i; j < x; j += i){
      ct[i] += fq[j];
    }
  }
 
  ll mx = 1;
 
  for(ll i = 1; i < x; i++){
    if(ct[i] >= 2){
      mx = max(mx, i);
    }
  }
 
  printf("%lld", mx);
 
 return 0;
}

// https://cses.fi/problemset/task/1081/
