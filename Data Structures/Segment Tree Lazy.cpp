#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5+10;
ll a[N];
array<ll,2> t[4*N]; // t[n][0] = sum, t[n][1] = lazy

struct ST {
  void bld(int n, int b, int e) {
    t[n][1] = 0;
    if (b == e) {
      t[n][0] = a[b];
      return;
    }
    int m = (b + e) >> 1, l = (n << 1) + 1, r = (n << 1) + 2;
    bld(l, b, m);
    bld(r, m+1, e);
    t[n][0] = t[l][0] + t[r][0];
  }

  void upd(int n, int b, int e, int i, int j, ll x) {
    if (i > e || j < b) return;
    if (i <= b && e <= j) {
      t[n][0] += (e - b + 1) * x;
      t[n][1] += x;
      return;
    }
    int m = (b + e) >> 1, l = (n << 1) + 1, r = (n << 1) + 2;
    upd(l, b, m, i, j, x);
    upd(r, m+1, e, i, j, x);
    t[n][0] = t[l][0] + t[r][0] + t[n][1] * (e - b + 1);
  }

  ll qry(int n, int b, int e, int i, int j, ll c = 0) {
    if (i > e || j < b) return 0;
    if (i <= b && e <= j) return t[n][0] + c * (e - b + 1);
    int m = (b + e) >> 1, l = (n << 1) + 1, r = (n << 1) + 2;
    ll L = qry(l, b, m, i, j, c + t[n][1]);
    ll R = qry(r, m+1, e, i, j, c + t[n][1]);
    return L + R;
  }
};

int main() {
 
  return 0;
}
TC :-
  Segment Tree with Lazy Propagation:
- Build: O(N)
- Update (range): O(log N)
- Query (range): O(log N)
- Space: O(N)

