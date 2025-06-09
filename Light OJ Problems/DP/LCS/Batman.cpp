#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){

    string s1,s2,s3; cin >> s1 >> s2 >> s3;
    int a = s1.size(),
    b = s2.size(),
    c = s3.size();

    vector<vector<vector<int>>> dp(a,vector<vector<int>>(b,vector<int>(c,-1)));

    function<int(int,int,int)> lcs = [&](int i,int j, int k){
        if(i < 0 || j < 0 || k < 0) return 0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int ans = lcs(i-1,j,k);
        ans = max(ans, lcs(i,j-1,k));
        ans = max(ans,lcs(i,j,k-1));
        ans = max(ans,lcs(i-1,j-1,k-1) + (s1[i] == s2[j] and s2[j] == s3[k]));
        return dp[i][j][k] = ans;
    };
    cout << lcs(a-1,b-1,c-1) << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, i = 1; cin >> t;

    while(t--){
        cout << "Case " << i << ": ";
        solve();
        i++;
    }

  return 0;
}
// before we solved lcs for 2 strings but here given 3 string but the idea is same
// for 2 strings we did i-1,j then i,j-1 and i-1,j-1 + (s1[i] == s2[j]) then took the max of them
// but for 3 strings we will do i-1,j,k then i,j-1,k then i,j,k-1 then i-1,j-1,k-1 + (s1[i] == s2[j] and s2[j] == s3[k]) then took the max of them
