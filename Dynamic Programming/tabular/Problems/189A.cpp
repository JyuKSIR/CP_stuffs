// based on minimum coins but took max in place of min

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

void solve(){

   int n; cin >> n;
   vector<int> dp(n+1,-1),l(3);
   dp[0]=0;
   for(int i=0; i<3; i++) cin >> l[i];
   for(int i=0; i<3; i++){
	   for(int j=l[i]; j<=n; j++){
	      if (dp[j - l[i]] != -1) dp[j]=max(dp[j],1+dp[j-l[i]]); //if condition for correct values
	   }	   
   }
   //for(int x : dp) cout << x << " ";
   cout << dp[n] << "\n";

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

       solve();

  return 0;
}
