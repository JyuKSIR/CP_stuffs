#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

int main(){

  ll n; scanf("%lld", &n);
  ll ans = 0;

  auto shesh = [](ll x) -> ll {
    ll p = 1, ct = 0;
    while(x >= p){
      x -= p;
      ct++;
      p++;
    }
    return ct;
  };

  for(ll i = 2; i * i <= n; i++){
    if(n % i == 0){
      ll count = 0;
      while(n % i == 0){
        count++;
        n /= i;
      }
      ans += shesh(count);
    }
  }
  if(n > 1) ans++;
  
  printf("%lld", ans);

 return 0;
}