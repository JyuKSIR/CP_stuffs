// https://cses.fi/problemset/task/1192
// connected components in a 2D grid
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m; cin >> n >> m;
  vector<vector<char>> g(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  vector<vector<int>> vis(n, vector<int>(m, 0));
  vector<vector<array<int, 2>>> cc;
  vector<array<int, 2>> cur;
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  function<void(int, int)> dfs = [&](int x, int y){
    vis[x][y] = 1;
    cur.push_back({x, y});
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (nx >= 0 and nx < n and
          ny >= 0 and ny < m and
          !vis[nx][ny] && g[nx][ny] != '#') {
        dfs(nx, ny);
      }
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '.' && !vis[i][j]) {
        cur.clear();
        dfs(i, j);
        cc.push_back(cur);
      }
    }
  }
  cout << cc.size();
}
