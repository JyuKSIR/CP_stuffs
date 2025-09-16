#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int a[n][m], ps[n + 1][m + 1]{};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ps[i][j] = a[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
    }
  }

  int ct = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 1; i + k - 1 <= n && j + k - 1 <= m; k++) {
        int x1 = i, y1 = j;
        int x2 = i + k - 1, y2 = j + k - 1;
        int ans = ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
        if (ans == (k * k)) ct++;
      }
    }
  }

  cout << ct << "\n";

  return 0;
}
// https://toph.co/p/anina-s-birthday-gift
