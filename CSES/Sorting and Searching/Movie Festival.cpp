// https://cses.fi/problemset/task/1629
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  vector<array<int, 2>> v;
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    v.push_back({b, a});
  }
  sort(v.begin(), v.end());
  for (auto &[a, b] : v) swap(a, b);
  int ct = 1, l = v[0][1]; 
  for (int i = 1; i < n; i++) {
    if (v[i][0] >= l) {
      ct++;
      l = v[i][1];
    }
  }
  cout << ct;
}
