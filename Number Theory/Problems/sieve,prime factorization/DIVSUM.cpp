#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

const ll n = 5e5+5;
ll sum[n];

void solve(){

  for(ll i = 2; i < n; i++){
    for(ll j = i; j < n; j += i){
      sum[j] += i;
    }
  }

}

int main(){
  
  solve();
  int t; 
  scanf("%d", &t);
  while(t--){
    ll x; scanf("%lld", &x);
    if(x == 0 || x == 1) printf("0\n");
    else printf("%lld\n", sum[x] - x + 1);
  }

 return 0;
}