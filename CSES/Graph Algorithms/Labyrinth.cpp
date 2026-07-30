// https://cses.fi/problemset/task/1193
// BFS + backtrack (finding shortest distance and the path)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m; cin >> n >> m;
  int sx = -1, sy = -1, tx = -1, ty = -1;
  vector<vector<char>> g(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
      if (g[i][j] == 'A') {
        sx = i;
        sy = j;
      }
      if (g[i][j] == 'B') {
        tx = i;
        ty = j;
      }
    }
  }
  // UDLR
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  char dir[4] = {'U', 'D', 'L', 'R'};
  int dis = 0;
  string move = "";
  auto bfs = [&](int sx, int sy, int tx, int ty) -> bool {
    vector<vector<int>> d(n, vector<int>(m, -1));
    vector<vector<int>> v(n, vector<int>(m, 0));
    vector<vector<char>> par(n, vector<char>(m, '?'));
    queue<array<int, 2>> q;
    q.push({sx, sy});
    v[sx][sy] = 1;
    d[sx][sy] = 0;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      if (x == tx and y == ty) {
        dis = d[x][y];
        while (x != sx or y != sy) {
          char c = par[x][y];
          move += c;
          if (c == 'U') {
            x++;
          } else if (c == 'D') {
            x--;
          } else if (c == 'L') {
            y++;
          } else if (c == 'R') {
            y--;
          }
        }
        reverse(move.begin(), move.end());
        return 1;
      }
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 and nx < n and
            ny >= 0 and ny < m and
            !v[nx][ny] and g[nx][ny] != '#') {
          v[nx][ny] = 1;
          d[nx][ny] = d[x][y] + 1;
          par[nx][ny] = dir[k];
          q.push({nx, ny});
        }
      }
    }
    return 0;
  };
  bool f = bfs(sx, sy, tx, ty);
  if (f) {
    cout << "YES\n";
    cout << dis << '\n';
    cout << move;
  } else {
    cout << "NO";
  }
}
