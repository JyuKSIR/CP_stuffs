// the problem is you will be give two matrices each n x m rows and columns, and given q queries, each queries contains 4 integers r1, c1, r2, c2
// you have to output the sum of the rectangle created in the range 
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n,m; cin >> n >> m;
  int a[n][m], b[n][m], d[n][m], ps[n + 1][m + 1]{};

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> b[i][j];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      d[i][j] = abs(a[i][j] - b[i][j]);
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      ps[i][j] = d[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
    }
  }

  int q; cin >> q;
  while(q--){
    int r1, c1, r2, c2, ans; cin >> r1 >> c1 >> r2 >> c2;
    if(r1 > r2) swap(r1, r2);
    if(c1 > c2) swap(c1, c2);
    ans = ps[r2][c2] - ps[r1 - 1][c2] - ps[r2][c1 - 1] + ps[r1 - 1][c1 - 1];
    cout << ans << "\n";
  }

  return 0;
}

// TC
// 6 5
// -9 8 9 -9 -3 
// 2 -8 5 1 1 
// -1 -2 -5 -9 -1 
// -4 -6 1 1 -10 
// 1 0 4 -7 2 
// 9 -3 -2 -3 7

// -5 -5 9 5 -8 
// -9 -4 -4 3 8 
// -5 -10 3 -7 -3 
// -7 0 9 -10 1 
// -1 -3 5 -1 7 
// 1 -4 2 6 10 
// 3
// 5 3 6 2
// 3 4 2 3
// 5 1 2 4
