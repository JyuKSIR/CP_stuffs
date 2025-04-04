#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9+7;

void solve() {
    int n; 
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) { //first iterate sum and then given elemnet || ordered dp
        for(int j = 1; j <= 6; j++) {
            if(i >= j) {
                dp[i] = (dp[i] + dp[i-j]) % mod;
            }
        }    
    }

    cout << dp[n] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}

