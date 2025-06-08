#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    ll n,w; cin >> n >> w;
    ll wt[n],p[n];
    
    vector<vector<ll>> dp(n,vector<ll>(w+1,-1));

    for(int i=0; i<n; i++){
        cin >> wt[i] >> p[i];
    }

    function<ll(ll,ll)> knap = [&](ll i, ll wleft){
        if(wleft == 0) return 0LL;
        if(i < 0) return 0LL;
        if(dp[i][wleft] != -1) return dp[i][wleft];
        ll ans = knap(i-1,wleft);
        if(wleft - wt[i] >= 0) {
            ans = max(ans, knap(i-1,wleft-wt[i]) + p[i]);
        }
        return dp[i][wleft] = ans;
    };

    knap(n-1, w);
    cout << dp[n-1][w];

  return 0;
}