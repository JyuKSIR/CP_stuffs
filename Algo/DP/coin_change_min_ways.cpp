#include <iostream>
using namespace std;

int main(){
  int n, tot; cin >> n >> tot;
  int c[n + 1]{};
  for(int i = 1; i <= n; i++) cin >> c[i];
  int dp[n + 1][tot + 1]{};
  dp[0][0] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= tot; j++){
      if(c[i] > j){
        dp[i][j] = dp[i - 1][j];
      }
      else dp[i][j] = dp[i - 1][j] + dp[i][j - c[i]];
    }
  }
  cout << dp[n][tot];
}
