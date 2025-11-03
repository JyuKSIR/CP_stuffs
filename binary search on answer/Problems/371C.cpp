#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;
  ll nb, ns, nc; cin >> nb >> ns >> nc;
  ll pb, ps, pc; cin >> pb >> ps >> pc;
  ll r; cin >> r;
  ll a[3]{};
  for(auto c : s){
    if(c == 'B') a[0]++;
    if(c == 'S') a[1]++;
    if(c == 'C') a[2]++;
  }

  auto f = [&](ll m){
    ll nnb = m * a[0];
    ll nns = m * a[1];
    ll nnc = m * a[2];
    ll hb = (nnb - nb);
    ll hs = (nns - ns);
    ll hc = (nnc - nc);
    ll cost = 0;
    if(hb > 0) cost += (hb * pb);
    if(hs > 0) cost += (hs * ps);
    if(hc > 0) cost += (hc * pc);
    if(cost <= r) return 0;
    else return 1;
  };

  ll lo = 0, hi = 1e13;
  while(lo <= hi){
    ll m = (lo + hi) / 2;
    if(f(m)) hi = m - 1;
    else lo = m + 1;
  }
  cout << hi;
  
  return 0;
}
