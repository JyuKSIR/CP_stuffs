#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    int p[n],dp[n+1];
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<n; i++) cin >> p[i];

    function<int(int)> cut = [&](int l){
        if(l == 0) return 0;
        if(dp[l] != -1) return dp[l];
        int ans = 0;
        for(int i=1; i<=l; i++){
            if(l-i >= 0){
                ans = max(ans,cut(l-i) + p[i-1]);
            }
        }
        return dp[l] = ans;
    };

    cut(n);

    cout << dp[n] << "\n";

  return 0;
}

// 8
// 1 5 8 9 10 17 17 20
