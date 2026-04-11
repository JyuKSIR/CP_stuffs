// https://atcoder.jp/contests/abc453/tasks/abc453_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool zero(double x, double y){
  double mn = min(x, y);
  double mx = max(x, y);
  if(mn < 0.0 and 0.0 < mx){
    return 1;
  }
  return 0;
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  int sz = (1 << n);
  int ans = -1e9;
  for(int msk = 0; msk < sz; msk++){
    int ct = 0;
    double nw = 0.5;
    double pv = 0.0;
    for(int i = 0; i < n; i++){
      double pv = nw;
      if(msk & (1 << i)) nw += a[i];
      else nw -= a[i];
      if(zero(nw, pv)){
        ct++;
      }
    }
    ans = max(ans, ct);
  }
  cout << ans << "\n";
}
