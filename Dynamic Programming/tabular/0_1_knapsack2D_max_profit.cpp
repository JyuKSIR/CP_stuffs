#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> W;
    
    vector<int> val(n), wt(n);
    cout << "Enter values and weights of items: \n";
    for (int i = 0; i < n; i++) {
        cin >> val[i] >> wt[i];
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (wt[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
        }
    }
    
    cout << "Maximum value in knapsack: " << dp[n][W] << endl;
    return 0;
}
