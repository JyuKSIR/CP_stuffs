#include <bits/stdc++.h>
using namespace std;

int main() {
    int am, n;
    cin >> am >> n;
    int c[n];
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<vector<int>> dp(n, vector<int>(am + 1, -1));

    function<int(int, int)> numofway = [&](int i, int sum) {
        if (sum == 0) return 1;
        if (i < 0) return 0;
        if (dp[i][sum] != -1) return dp[i][sum];

        int ways = 0;
        for (int coin_am = 0; coin_am <= sum; coin_am += c[i]) {
            ways += numofway(i - 1, sum - coin_am);
        }
        return dp[i][sum] = ways;
    };

    int result = numofway(n - 1, am);
    cout << result << "\n";

    return 0;
}
