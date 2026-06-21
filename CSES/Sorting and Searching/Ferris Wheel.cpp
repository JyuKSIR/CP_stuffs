// https://cses.fi/problemset/task/1090
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m; cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int i = 0, j = n - 1, ct = 0;
  while (i <= j) {
    if (a[i] + a[j] <= m) {
      i++;
    }
    j--;
    ct++;
  }
  cout << ct;
}
