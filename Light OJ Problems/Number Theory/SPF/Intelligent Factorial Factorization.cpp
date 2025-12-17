// https://lightoj.com/problem/intel-factor-factorization
// ---> n * (n - 1) prime factors of n and (n - 1) then add the power of common factors

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

const int N = 105;

vector<bool> vis(N, 1);
vector<int> spf(N);
vector<array<int,2>> ans[N];

void sieve(){
  vis[0] = vis[1] = 0;
  iota(spf.begin(), spf.end(), 0);
  for(int i = 2; i * i < N; i++){
    if(vis[i]){
      for(int j = i * i; j < N; j += i){
        vis[j] = 0;
        if(spf[j] == j) spf[j] = i;
      }
    }
  }
}

void pre() {
  for (int i = 2; i < N; i++) {
    ans[i] = ans[i - 1];
    int x = i;
    while (x > 1) {
      int p = spf[x];
      int ct = 0;
      while (x % p == 0) {
        x /= p;
        ct++;
      }
      bool f = 0;
      for (auto &e : ans[i]) {
        if (e[0] == p) {
          e[1] += ct;
          f = 1;
          break;
        }
      }
      if (!f) ans[i].push_back({p, ct});
    }
  }
}

void solve() {
  ll n; cin >> n;
  cout << n << " = ";
  int sz = ans[n].size(), ct = 0;
  for (auto &p : ans[n]) {
    cout << p[0] << " (" << p[1] << ") ";
    ct++;
    if(ct != sz) cout << "* ";
  }
  cout << '\n';

}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  sieve(), pre();
  int t, i = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << i << ": ";
    solve();
    i++;
  }
  return 0;
}
