#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

const ll N = 3e5 + 5;
ll a[N];

struct ST{

  ll t[4*N];
  static const ll inf = 1e9;

  ST(){
    memset(t, 0, sizeof(t));
  }

  void build(ll n, ll b, ll e){
    if(b == e){
      t[n] = a[b];
      return;
    }
    ll m = (b + e) >> 1, l = (n << 1) + 1 , r = (n << 1) + 2;
    build(l, b, m);
    build(r, m+1, e);
    t[n] = t[l] + t[r];
  }

  void upd(ll n, ll b, ll e, ll i, ll x){
    if (b > i || e < i) return;
    if(b == e && b == i){
      t[n] = x;
      return;
    }
    ll m = (b + e) >> 1, l = (n << 1) + 1 , r = (n << 1) + 2;
    upd(l, b, m, i, x);
    upd(r, m+1, e, i, x);
    t[n] = t[l] + t[r];
  }

  ll qry(ll n, ll b, ll e, ll i, ll j){
    if(b > j || e < i) return 0LL;
    if(b >= i && e <= j) return t[n];
    ll m = (b + e) >> 1, l = (n << 1) + 1 , r = (n << 1) + 2;
    ll L = qry(l, b, m, i, j);
    ll R = qry(r, m + 1, e, i, j);
    return L + R;
  }
};

int main(){
  ll z,q; scanf("%lld%lld", &z, &q);
  for(ll i = 0; i < z; i++){
    scanf("%lld", &a[i]);
  }
  ST tree;
  tree.build(0,0,z-1);
  while(q--){
    ll ty; scanf("%lld", &ty);
    if(ty == 1){
      ll k,u; scanf("%lld%lld", &k, &u);
      k--;
      tree.upd(0,0,z-1,k,u);
      continue;
    }
    ll l,r; scanf("%lld%lld", &l, &r);
    l--,r--;
    ll p = tree.qry(0,0,z-1,l,r);
    printf("%lld\n", p);
  }

 return 0;
}
// https://cses.fi/problemset/task/1648
