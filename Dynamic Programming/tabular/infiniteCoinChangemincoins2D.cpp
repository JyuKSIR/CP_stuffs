#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

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

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, inf));

    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= amount; j++) {
            if (coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = min(dp[i - 1][j],1+dp[i][j - coins[i - 1]]);
        }
    }
	// printing the table
	for(auto x : dp){
		for(auto y : x) cout << y << " ";
	    cout << "\n"; 	
	}

    cout << "Minimum number of coins: " << dp[n][amount] << endl;
    return 0;
}
