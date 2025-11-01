#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto f = [&](int x) -> bool {
    if (x == 0) return 0;
    set<int> st;
    // Initialize the set with all numbers from 0 to x-1
    for (int i = 0; i < x; i++) {
      st.insert(i);
    }
    int fd = 0; // how many complete sets [0..x-1] found
    // Iterate over the array
    for (int i = 0; i < n; i++) {
      if (st.count(a[i])) st.erase(a[i]);  // remove if found
      if (st.empty()) {                    // found one full set
        fd++;                              // increase count
        // Reset the set for the next round
        for (int j = 0; j < x; j++) st.insert(j);
      }
    }
    if (fd >= k) return 0;
    else return 1;
  };
  // Binary search on x
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
  while (t--) {
    solve();
  }

  return 0;
}
