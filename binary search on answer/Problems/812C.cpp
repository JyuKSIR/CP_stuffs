#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

ll cost = 0;

bool f(ll m, ll s, ll n, ll a[]){
  ll c[n];
  for(int i = 0; i < n; i++){
    c[i] = (a[i] + (i + 1) * m);
  }
  sort(c, c + n);
  ll sum = 0;
  for(int i = 0; i < m; i++){
    sum += c[i];
  }
  if(sum <= s){
    cost = max(sum, cost);
    return 0;
  }
  else return 1;

}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, s; cin >> n >> s;
  ll a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  int l = 0, r = n;
  while (l <= r) {
    int m = (l + r) / 2;
    if(f(m, s, n, a)) r = m - 1;
    else l = m + 1;
  }
  cout << r << " " << cost << "\n";
  
  return 0;
}
