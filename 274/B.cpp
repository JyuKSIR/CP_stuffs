#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m; cin >> n >> m;
  int a[n][n]{};
  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    u--, v--;
    a[u][v] = a[v][u] = 1;
  }
  int ans = 1;
  for(int msk = 0; msk < (1 << n); msk++){
    bool ok = 1;
    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        if((msk & ( 1 << i)) && (msk & (1 << j))){
          if(!a[i][j]){
            ok = 0;
            break;
          }
        }
      }
    }
    if(ok) ans = max(ans, __builtin_popcount(msk));
  }
  cout << ans << "\n";
}
// Represent groups with a bitmask.
// Each integer mask from 0 to 2^n - 1 is a subset of vertices.
// Bit i = 1 means vertex i is included in the current group.

// Loop over all subsets.
// The outer loop runs mask = 0 … (1<<n)-1, meaning every possible subset of vertices.

// Assume the subset is a clique.
// ok = true at the start for that subset.

// Check all vertex pairs in that subset.
// For every pair (i, j):

// First check if both vertices are in the subset using
// (mask & (1<<i)) && (mask & (1<<j)).

// If both are included, verify there is an edge between them:
// edge[i][j].

// Invalidate if a pair is not connected.
// If any pair inside the subset lacks an edge, it cannot be a clique → ok = false.

// If it survived all checks, it’s a clique.
// Count how many vertices are in that subset using
// __builtin_popcount(mask).

// Update the best answer.
// ans = max(ans, size_of_this_clique).
