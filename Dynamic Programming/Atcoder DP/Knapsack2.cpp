#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    ll n,w; cin >> n >> w;
    ll wt[n],p[n];
    
    vector<vector<ll>> dp(105,vector<ll>(1e5+5,-1));

    for(int i=0; i<n; i++){
        cin >> wt[i] >> p[i];
    }

    function<ll(ll,ll)> knap = [&](ll i, ll vleft){
        if(vleft == 0) return 0LL;
        if(i < 0) return (ll)1e15;
        if(dp[i][vleft] != -1) return dp[i][vleft];
        ll ans = knap(i-1,vleft);
        if(vleft - p[i] >= 0) {
            ans = min(ans, knap(i-1,vleft-p[i]) + wt[i]);
        }
        return dp[i][vleft] = ans;
    };

    for(ll i = 1e5; i>= 0; i--){
        if(knap(n-1,i) <= w){
            cout << i;
            break;
        }
    }

  return 0;
}
