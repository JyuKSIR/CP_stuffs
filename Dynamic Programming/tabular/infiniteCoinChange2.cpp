#include <bits/stdc++.h>
using namespace std;

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

    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
	  for(auto x : dp) cout << x << " ";

    cout << "\nNumber of ways: " << dp[amount] << endl;
    return 0;
}
