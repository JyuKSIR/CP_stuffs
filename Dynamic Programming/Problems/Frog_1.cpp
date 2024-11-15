#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

const int N = 1e5+10;
int h[N];
int dp[N];

int min_cost(int x){

    if(x==0) return 0;
    if(dp[x] != -1) return dp[x];
    int cost = INT_MAX;
    // way 1
    cost = min(cost,(min_cost(x-1) + abs(h[x]-h[x-1])));
    // way 2
    if(x>1){
       cost = min(cost,(min_cost(x-2) + abs(h[x]-h[x-2]))); 
    }
    dp[x] = cost;
    return dp[x];
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    memset(dp,-1,sizeof(dp));
    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    cout << min_cost(n-1);

  return 0;
}
