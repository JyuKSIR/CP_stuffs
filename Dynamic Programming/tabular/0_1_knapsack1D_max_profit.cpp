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
    
    vector<int> dp(W + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = W; j >= wt[i]; j--) {
            dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
        }
    }
    
    cout << "Maximum value in knapsack: " << dp[W] << endl;
    return 0;
}
