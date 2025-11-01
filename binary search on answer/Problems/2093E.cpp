#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  // where each group contains all numbers from 0 to x-1 at least once.
  auto f = [&](int x) -> bool {
    if (x == 0) return 0;  // x = 0 is invalid
    vector<int> c(x, 0);  // frequency array for elements in range [0..x-1]
    int fd = 0;           // how many full groups we have found
    int ct = 0;           // count of distinct numbers seen so far
    for (int i = 0; i < n; i++) {
      if (a[i] < x) {               // only care about elements in [0..x-1]
        c[a[i]]++;                  // increase count for a[i]
        if (c[a[i]] == 1) ct++;     // new distinct number found
        // If we’ve seen all numbers [0..x-1], one full group is completed
        if (ct == x) {
          fd++;                     // increase full group count
          ct = 0;                   // reset distinct counter
          fill(c.begin(), c.end(), 0); // reset frequency array for next group
        }
      }
    }
    if (fd >= k) return 0;
    else return 1;
  };

  // Binary search to find the largest x such that
  // we can form at least k full groups of [0..x-1]
  int l = 0, r = n;
  while (l <= r) {
    int m = (l + r) / 2;
    if (f(m)) r = m - 1;
    else l = m + 1;
  }
  cout << r << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}
