#include<bits/stdc++.h>
using namespace std;

int main(){
    int l,n; cin >> l >> n;
    vector<int> val(n),prof(n);
    vector<int> dp(l+1,0);

    for(int &a : val) cin >> a;
    for(int &a : prof) cin >> a;

    for(int i=0; i<n; i++){
        for(int j=val[i]; j<=l; j++){
            dp[j] = max(dp[j],dp[j-val[i]]+prof[i]);
        }
    }

    cout << dp[l] << "\n";
}
