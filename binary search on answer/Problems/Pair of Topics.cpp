#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n; cin >> n;
  ll a[n], b[n], c[n], d[n];
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
   cin >> b[i];
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
   c[i] = a[i] - b[i];
   d[i] = b[i] - a[i];
   if(c[i] > d[i]) ans--;
  }
  sort(c, c + n);
  for (int i = 0; i < n; i++) {
   ans += n - ((upper_bound(c, c + n, d[i])) - c);
  }
  cout << ans / 2;
  
  return 0;
}
