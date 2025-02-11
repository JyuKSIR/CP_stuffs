#include<bits/stdc++.h>
using namespace std;

int main(){

    int l,n; cin >> l >> n;

    vector<int> val(n),prof(n);
    vector<vector<int>>dp(n+1,vector<int>(l+1,0));

    for(int &a : val) cin >> a;
    for(int &a : prof) cin >> a;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=l; j++){
            if(val[i-1]>j){
                dp[i][j] = dp[i - 1][j];
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - val[i - 1]] + prof[i - 1]);
        }
    }
    cout << dp[n][l] << "\n";
}
