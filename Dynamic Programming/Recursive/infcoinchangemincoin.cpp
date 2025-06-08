#include<bits/stdc++.h>
using namespace std;

int main(){

    int am,n; cin >> am >> n;
    int c[n], dp[am+1];

    memset(dp,-1,sizeof(dp));

    for(int i=0; i<n; i++) cin >>  c[i];

    function<int(int)> mincoin = [&](int sum){
        if(sum == 0) return 0;
        if(dp[sum] != -1) return dp[sum];
        int ct = INT_MAX;
        for(auto coin : c){
            if(sum - coin >= 0){
                ct = min(ct , mincoin(sum - coin) + 1);
            }
        }
        return dp[sum] = ct;
    };

    mincoin(am);

    if (dp[am] == INT_MAX)
        cout << -1 << "\n";
    else
        cout << dp[am] << "\n";

  return 0;
}
