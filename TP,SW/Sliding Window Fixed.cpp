#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k; cin >> n >> k;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  multiset<int> ms;
  for(int i = 0; i < k; i++){
    ms.insert(a[i]);
  }
  vector<array<int,2>> ans;
  for(int i = 0; i <= n - k; i++){
    // for(auto x : ms) cout << x << " ";
    // cout << "\n";
    int mn = *ms.begin();
    int mx = *ms.rbegin();
    ans.push_back({mn,mx});
    ms.erase(ms.find(a[i]));
    if(i + k <= n) ms.insert(a[i + k]);
  }
  for(auto [a,b] : ans) cout << a << " " << b << "\n";
  return 0;
}
