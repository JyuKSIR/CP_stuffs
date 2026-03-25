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

