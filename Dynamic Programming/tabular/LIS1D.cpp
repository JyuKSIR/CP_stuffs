// subarray should be contigious
// subsequnce shouldn't be contigious but have to be in right order

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    vector<int> v(n),dp(n,1);
    for(int &a : v) cin >> a;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(v[i]>v[j]){
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
    }
    int ans = dp[0];
    for(int i=1; i<n; i++){
        ans = max(ans,dp[i]);
    }
    cout << ans << "\n";
}
