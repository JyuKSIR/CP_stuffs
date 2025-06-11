#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){

    int n; cin >> n;

    vector<vector<int>> ar(2*n-1,vector<int>(n,0));
    vector<vector<int>> dp(2*n-1,vector<int>(n,-1));

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> ar[i][j];
        }
    }

    int l = 1;

    for(int i=n; i<(2*n)-1; i++){
        for(int j = l; j<n; j++){
            cin >> ar[i][j];  
        }
        l++;
    }

    // for(int i=0; i<(2*n)-1; i++){
    //     for(int j=0; j<n; j++){
    //         cout << ar[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    function<int(int,int)> take = [&](int i,int j){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int x = take(i-1,j) + ar[i][j];
        int y = take(i-1,j-1) + ar[i][j];

        return dp[i][j] = max(x,y);
    };

    cout << take(2*n-2,n-1) << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t,i = 1; cin >> t;

    while(t--){
        cout << "Case " << i << ": ";
        solve();
        i++;
    }

  return 0;
}
