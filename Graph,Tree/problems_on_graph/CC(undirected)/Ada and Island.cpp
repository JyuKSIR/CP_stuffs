// https://www.spoj.com/problems/ADASEA/cstart=20
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
  ll n, m; cin >> n >> m;
  vector<vector<char>> g(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  vector<vector<ll>> vis(n, vector<ll>(m, 0));
  vector<vector<array<ll, 2>>> cc;
  vector<array<ll, 2>> cur;
  ll dx[] = {-1, 1, 0, 0};
  ll dy[] = {0, 0, -1, 1};
  function<void(ll, ll)> dfs = [&](ll x, ll y){
    vis[x][y] = 1;
    cur.push_back({x, y});
    for (int k = 0; k < 4; k++) {
      ll nx = x + dx[k];
      ll ny = y + dy[k];
      if (nx >= 0 and nx < n and
          ny >= 0 and ny < m and
          !vis[nx][ny] && g[nx][ny] != '~') {
        dfs(nx, ny);
      }
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '#' && !vis[i][j]) {
        cur.clear();
        dfs(i, j);
        cc.push_back(cur);
      }
    }
  }
  ll sum = 0;
  for (auto cur : cc) {
    ll x = (ll)cur.size();
    sum += x * x;
  }
  ll div = __gcd(sum, n * m);
  ll num = sum / div;
  ll din = (n * m) / div;
  if (din == 1) cout << num << '\n';
  else cout << num << " / " << din << '\n';
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}
