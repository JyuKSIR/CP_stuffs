// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=788
// recursion for seeing pattern
#include <bits/stdc++.h>
using namespace std;
int dp[90000];// -1 = unvisited, 0 = lose, 1 = win
int n;
// fun = 1 = stan wins, fun = 0 = stan loses / ollie wins
int fun(int p){
  if(p >= n){
    return 0; // stan loses
  }
  if(dp[p] != -1) return dp[p];
  bool w = 0;
  for(int i = 2; i <= 9; i++){
    w |= !fun(p * i); // !fun(p * i) means function returning 1 means
  }                   // opponent loses so i want just one case where
  return dp[p] = w;   // opponent is losing
}
int main(){
  //cin >> n;
  for(int i = 1; i <= 1900; i++){
    n = i;
    memset(dp, -1, sizeof(dp));
    if(!fun(1))
      cout << i << " " << "Ollie\n";
  }
}
// but in this particular problem it can be solved by recursion
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, ll> dp;
ll n;
// fun = 1 = stan wins, fun = 0 = stan loses / ollie wins
bool fun(ll p){
  if(p >= n){
    return 0;
  }
  if(dp.count(p)) return dp[p];
  bool w = 0;
  for(ll i = 2; i <= 9; i++){
    w |= !fun(p * i); // !fun(p * i) means function returning 1 means
  }                   // opponent loses so i want just one case where
  return dp[p] = w;   // opponent is losing
}
int main(){
  while(cin >> n){
    dp.clear();
    if(fun(1)){
      cout << "Stan wins.\n";
    }
    else{
      cout << "Ollie wins.\n";
    }
  }
}
TC - O(log n log log n)
// and if you want to solve the problem greedily we can see from the pattern stan always multiplying 9 and ollie multiplying 2 so
// we can do it greedily
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  cin.tie(0)->sync_with_stdio(0);
  ll n;
  while(cin >> n){
    ll p = 1;
    bool t = 0; // stan's turn = 0, Ollie's turn = 1
    while(1){    
      if(!t) p *= 9; // we can see from the pattern that stan is 
      else p *= 2;  // trying to multiply p by 9 and ollie by 2
      if(p >= n) break;
      t = !t;
    }
    if(!t) cout << "Stan wins.\n";
    else cout << "Ollie wins.\n"; 
  }
}


