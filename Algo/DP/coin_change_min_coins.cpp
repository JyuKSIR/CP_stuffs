#include <iostream>
using namespace std;

int main() {
  int n, tot; cin >> n >> tot;
  int c[n + 1]{};
  for(int i = 1; i <= n; i++) cin >> c[i];
  int dp[n + 1][tot + 1]{};
  for(int j = 1; j <= tot; j++) dp[0][j] = 1e9;
  dp[0][0] = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= tot; j++) {
      if(c[i] > j) {
        dp[i][j] = dp[i - 1][j];
      }
      else {
        dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - c[i]]);
      }
    }
  }
  // for(int i = 0; i <= n; i++){
  //   for(int j = 0; j <= tot; j++) cout << dp[i][j] << " ";
  //   cout << "\n";
  // }
  if(dp[n][tot] >= 1e9) cout << -1;
  else cout << dp[n][tot] << "\n";
  cout << "Coin used : ";

  int i = n;
  int j = tot;
  while (i > 0 && j > 0) {
    if (j >= c[i] && dp[i][j] == 1 + dp[i][j - c[i]]) {
      cout << c[i] << " ";
      j -= c[i];
    }
    else{
      i--;
    }
  }

  return 0;
}
