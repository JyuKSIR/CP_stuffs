// in how many ways you can travel to the goal on a grid with dimension m*n?
// you begin in the top-left corner goal is to travel bottom-right corner. You may only move down or right. 

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    ll n,m; cin >> n >> m;

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, -1));

    function<ll(ll,ll)> gridTraveler = [&](ll a, ll b){

        if(dp[a][b] != -1) return dp[a][b];

        if(a == 0 || b == 0) return dp[a][b] = 0LL;
        if(a == 1 && b == 1) return dp[a][b] = 1LL;

        return dp[a][b] = gridTraveler(a-1,b) + gridTraveler(a,b-1);
    };

    gridTraveler(n,m);

    cout << dp[n][m];

  return 0;
}
