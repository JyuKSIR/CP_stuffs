// given an array you have to tell how many unique pairs are there which product is perfect sqaure
// n <= 10^5
// 1 <= A[i] <= 10^5
// Test Case
// 10
// 2 8 18 50 3 12 75 1 4 9
// output -> 12

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

vector<bool> vis(N, 1);
vector<int> spf(N);

void sieve() {
  vis[0] = vis[1] = 0;
  iota(spf.begin(), spf.end(), 0);
  for (int i = 2; i * i < N; i++) {
    if (vis[i]) {
      for (int j = i * i; j < N; j += i) {
        vis[j] = 0;
        if (spf[j] == j) spf[j] = i; 
      }
    }
  }
}

vector<int> pfact(int n) {
  vector<int> v;
  while (n > 1) {
    int p = spf[n];
    v.push_back(p);
    n /= p;
  }
  return v;
}

int change(int n) {
  vector<int> pf = pfact(n);
  map<int, int> mp;
  int ans = 1;
  for (auto i : pf) {
    mp[i]++;
  }
  for (auto [a, b] : mp) {
    if (b & 1) ans *= a;
  }
  return ans;
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  sieve();
  int n; cin >> n;
  int a[n], mod[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    mod[i] = change(a[i]);
  }
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[mod[i]]++;
  }
  ll ans = 0;
  for (auto [a, b] : mp) {
    ans += (b * (b - 1)) / 2 * 1ll;
  }
  cout << ans;
}
