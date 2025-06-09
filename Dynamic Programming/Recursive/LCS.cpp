#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int a = s1.size(), b = s2.size();
    vector<vector<int>> dp(a, vector<int>(b, -1));

    function<int(int, int)> lcs = [&](int i, int j){
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int ans = max(lcs(i - 1, j), lcs(i, j - 1));
        if (s1[i] == s2[j]) {
            ans = max(ans, lcs(i - 1, j - 1) + 1);
        }

        return dp[i][j] = ans;
    };

    cout << lcs(a - 1, b - 1);

    return 0;
}
