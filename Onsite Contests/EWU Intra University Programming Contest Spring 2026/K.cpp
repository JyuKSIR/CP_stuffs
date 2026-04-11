#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; 
  cin >> n >> m;

  vector<string> g(n);
  vector<array<int, 2>> s, l;

  for(int i = 0; i < n; i++){
    cin >> g[i];
    for(int j = 0; j < m; j++){
      if(g[i][j] == 'S') s.push_back({i, j});
      if(g[i][j] == 'L') l.push_back({i, j});
    }
  }

  if(s.empty()){
    cout << 0;
    return 0;
  }

  vector<vector<int>> d(n, vector<int>(m, -1));

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  auto mulbfs = [&](vector<array<int, 2>>& src){
    queue<array<int, 2>> q;

    for(auto [x, y] : src){
      q.push({x, y});
      d[x][y] = 0;
    }

    while(!q.empty()){
      auto [x, y] = q.front();
      q.pop();

      for(int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx >= 0 && nx < n && ny >= 0 && ny < m &&
           g[nx][ny] != '#' && d[nx][ny] == -1){
          d[nx][ny] = d[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }
  };

  mulbfs(l);

  int ans = 0;

  for(auto [x, y] : s){
    if(d[x][y] == -1){
      cout << -1;
      return 0;
    }
    ans = max(ans, d[x][y]);
  }

  cout << ans;
}
