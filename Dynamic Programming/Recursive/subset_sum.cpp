#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,sum = 0; cin >> n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin >> ar[i];
        sum += ar[i];
    }
    if(sum % 2 != 0){
        cout << 0;
        return 0;
    }
    sum = sum / 2;
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));

    function<int(int,int)> subsum = [&](int i, int tg){
        if(tg == 0) return 1;
        if(i < 0) return 0;
        if(dp[i][tg] != -1) return dp[i][tg];
        bool pos = subsum(i-1,tg);
        if(tg-ar[i] >= 0){
            pos |= subsum(i-1,tg-ar[i]);
        }
        return dp[i][tg] = ((pos == true) ? 1 : 0);
    };

    subsum (n-1, sum);
    cout << dp[n-1][sum];

  return 0;
}
