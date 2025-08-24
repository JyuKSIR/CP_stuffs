#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll pow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1ll) {
      ans = ans * a;
    }
    a = a * a;
    b >>= 1ll;
  }
  return ans;
}
 
ll digitsumtilln(ll n, vector<ll> &a) {
  if (n < 10) return n * (n + 1) / 2;
  ll d = (ll)(log10(n));
  ll p = pow(10, d);
  ll msd = n / p;
  return (msd * a[d] + (msd * (msd - 1) / 2) * p + msd * (1 + n % p) +
          digitsumtilln(n % p, a));
}
 
ll digitsum(ll n) {
  ll d = max((ll)(log10(n)), 1ll);
  vector<ll> a(d + 1);
  a[0] = 0;
  a[1] = 45;
  for (int i = 2; i <= d; i++) {
    a[i] = a[i - 1] * 10 + 45 * (pow(10, i - 1));
  }
  return digitsumtilln(n, a);
}

int main() {
  
  int n = 328;
  cout << digitsum(n);
}
//https://www.geeksforgeeks.org/dsa/count-sum-of-digits-in-numbers-from-1-to-n/
TC :- O((log n) · log log n)
