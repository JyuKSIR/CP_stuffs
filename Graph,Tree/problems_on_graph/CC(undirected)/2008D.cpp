#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;  scanf("%d", &n);
  vector<int> a(n), vis(n+1, 0), fq(n+1, 0), ans(n+1, 0), g[n+1], cc;

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    g[i+1].push_back(a[i]);
    g[a[i]].push_back(i+1);
  }

  string s; cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') fq[a[i]] = 1;
  }

  function<void(int)> dfs = [&](int p) {
    vis[p] = 1;
    cc.push_back(p);
    for (auto c : g[p]) {
      if (!vis[c]) dfs(c);
    }
  };

  for(int i = 1; i <= n; i++){
    if (!vis[i]) {
      cc.clear();
      dfs(i);
      int ct = 0;
      for (int x : cc) if (fq[x]) ct++;
      for (int x : cc) ans[x] = ct;
    }
  }

  for(int i = 1; i <= n; i++){
    printf("%d ", ans[i]);
  }
  printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--){
    solve();
  }
  return 0;
}
