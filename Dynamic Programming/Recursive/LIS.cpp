#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    int ar[n], dp[n];

    memset(dp,-1,sizeof(dp));

    for(int i=0; i<n; i++) cin >> ar[i];

    function<int(int)> lis = [&](int i){ //returns maximum length of the subsequence ends in ith number
        if(dp[i] != -1) return dp[i];
        int ct = 1;
        for(int j=0; j<i; j++){
            if(ar[i]>ar[j]){
                ct = max(ct,lis(j)+1);
            }
        }
        return dp[i] = ct;
    };

    int ans = 0;

    for(int i=0; i<n; i++){
        ans = max(ans,lis(i));
    }

    cout << ans << "\n";

  return 0;
}
