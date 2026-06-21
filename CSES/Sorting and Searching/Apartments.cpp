// https://cses.fi/problemset/task/1084/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m, k; 
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int i = 0, j = 0, ct = 0;
  while (i < n && j < m) {
    if (a[i] >= b[j] - k && a[i] <= b[j] + k) {
      ct++;
      i++;
      j++;
    } else if (a[i] < b[j] - k) {
      i++;
    } else {
      j++;
    }
  }
  cout << ct;
}
