#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  int a[n + 1]{}, ps[n + 1]{};
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++){
    ps[i] = ps[i - 1] + a[i];
  }
  // for(int i = 1; i <= n; i++){
  //   cout << ps[i] << " ";
  // }
  // cout << "\n";
  int ans = 0;
  for(int k = 0; k <= n; k++){
    int mn = 0;
    for(int i = k; i <= n; i++){
      mn = min(mn , ps[i - k]); // keeps the minimum value outside the subarray
      ans = max(ans, ps[i] - mn + k * x); // if we minus the min value the we get the maximum subarray value
      //cout << mn << " " << i << " " << k << "\n";
    }
    cout << ans << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
