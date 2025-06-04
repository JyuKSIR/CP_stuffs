#include<bits/stdc++.h>
using namespace std;

int main(){

    long long n; cin >> n;

    long long dp[n+1];

    memset(dp,-1,sizeof(dp));

    function<long long(long long)> fib = [&](long long n){
        if(dp[n] != -1) return dp[n];
        if(n == 0) return dp[n] = 0;
        if(n == 1) return dp[n] = 1;
        return dp[n] = fib(n-1) + fib(n-2);
    };

    fib(n);

    cout << dp[n] << "\n";

  return 0;
}
