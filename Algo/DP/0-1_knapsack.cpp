#include <iostream>
using namespace std;

int main(){
  int n, ww; cin >> n >> ww;
  int w[n + 1]{}, p[n + 1]{};
  for(int i = 1; i <= n; i++) cin >> w[i];
  for(int i = 1; i <= n; i++) cin >> p[i];
  int dp[n + 1][ww + 1]{};
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= ww; j++){
      if(j >= w[i]){
        dp[i][j] = max(dp[i - 1][j - w[i]] + p[i], dp[i - 1][j]);
      }
      else{
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  int take[n + 1]{};
  int cap = ww;
  for (int i = n; i > 0; i--) {
    if (dp[i][cap] != dp[i - 1][cap]) {
      take[i] = 1;
      cap -= w[i];
    } else {
      take[i] = 0;
    }
  }
  cout << dp[n][ww] << "\n";
  for(int i = 1; i <= n; i++){
    if(take[i]){
      cout << "Item " << i << " -> Taken\n"; 
    }
    else{
      cout << "Item " << i << " -> Not taken\n"; 
    }
  }
}
