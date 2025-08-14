#include<bits/stdc++.h>
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

void solve(){
  int n,q; scanf("%d%d", &n, &q);
  ST tree;
  tree.bld(0,0,n-1);
  while(q--){
    int c; 
    scanf("%d", &c);
    if (c == 0) {
      int l, r; ll k;
      scanf("%d%d%lld", &l, &r, &k);
      l--; r--;
      tree.upd(0, 0, n-1, l, r, k);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      l--; r--;
      ll ans = tree.qry(0, 0, n-1, l, r);
      printf("%lld\n", ans);
    }
  }
}

int main(){
  int t; 
  scanf("%d", &t);
  while(t--){
    solve();
  }
 return 0;
}

// https://www.spoj.com/problems/HORRIBLE/
