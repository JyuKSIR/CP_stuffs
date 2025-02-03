#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    cout << "Enter the number of coins: ";
    int n;
    cin >> n;
    
    vector<int> coins(n);
    cout << "Enter the values of coins: ";
    for (int i = 0; i < n; i++) cin >> coins[i];

    cout << "Enter the amount: ";
    int amount;
    cin >> amount;

    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int i=0; i<n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
        }
    }

    cout << "Minimum number of coins: " << dp[amount] << endl;

    return 0;
}
