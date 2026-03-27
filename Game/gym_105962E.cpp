// https://codeforces.com/gym/105962/problem/E
// #include <bits/stdc++.h>
// using namespace std;

// int dp[1000];

// bool fun(int n){
//   if(n == 1) return 0; // if n == 1 the current player
//   if(n == 2) return 1; // wont have any way to win cause
//   if(dp[n] != -1) return dp[n]; // he have to pick the last stone
//   bool w = 0;
//   for(int i = 1; i <= 2; i++){
//       w |= !fun(n - i);
//   }
//   return dp[n] = w;
// }

// int main(){
//   cin.tie(0)->sync_with_stdio(0);

//   memset(dp, -1, sizeof(dp));
//   for(int i = 1; i <= 100; i++){
//     if(!fun(i)) cout << i << " -> E\n";;
//   }
// }
// did't find any pattern for Yvens :3

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  ll n; cin >> n;
  if(n % 3 == 1) cout << "Esteche\n";
  else cout << "Yvens\n";
}
