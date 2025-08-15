#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

const int N = 5e5+10;
const int mod = 998244353;

ll aa[N], bb[N];
array<ll,5> t[4*N]; 
// t[n][0] = asum, t[n][1] = alazy
// t[n][2] = bsum, t[n][3] = blazy
// t[n][4] = sum of aa[i]*bb[i] over the segment

struct ST {
  void bld(int n, int b, int e){
    t[n][1] = 0; // alazy
    t[n][3] = 0; // blazy
    if (b == e) {
      t[n][0] = aa[b] % mod;
      t[n][2] = bb[b] % mod;
      t[n][4] = (aa[b] * bb[b]) % mod;
      return;
    }
    int m = (b + e) >> 1;
    int l = (n << 1) + 1, r = (n << 1) + 2;
    bld(l, b, m);
    bld(r, m+1, e);
    t[n][0] = (t[l][0] + t[r][0]) % mod;
    t[n][2] = (t[l][2] + t[r][2]) % mod;
    t[n][4] = (t[l][4] + t[r][4]) % mod;
  }
  void add_node(int n, int b, int e, int id, ll x) {
    ll len = e - b + 1; // length of the current segment
    if(id == 0){
    // Adding x to all aa[i] in this segment
      t[n][0] = (t[n][0] + len * x % mod) % mod; // update sum of aa
      t[n][1] = (t[n][1] + x) % mod;            // mark lazy for aa
      t[n][4] = (t[n][4] + x * t[n][2] % mod) % mod; // update sum of aa[i]*bb[i]
    }
    else{  
    // Adding x to all bb[i] in this segment
      t[n][2] = (t[n][2] + len * x % mod) % mod; // update sum of bb
      t[n][3] = (t[n][3] + x) % mod;            // mark lazy for bb
      t[n][4] = (t[n][4] + x * t[n][0] % mod) % mod; // update sum of aa[i]*bb[i]
    }
  }
  void push(int n, int b, int e) {
    if (b == e) return; // leaf node, no children to push to
    int m = (b + e) >> 1;
    int l = (n << 1) + 1, r = (n << 1) + 2; // left and right children
    // Propagate lazy value of aa to children if it exists
    if(t[n][1] != 0) {
      add_node(l, b, m, 0, t[n][1]); // add lazy to left child
      add_node(r, m+1, e, 0, t[n][1]); // add lazy to right child
      t[n][1] = 0; // clear lazy of current node
    }
    // Propagate lazy value of bb to children if it exists
    if(t[n][3] != 0) {
      add_node(l, b, m, 1, t[n][3]); // add lazy to left child
      add_node(r, m+1, e, 1, t[n][3]); // add lazy to right child
      t[n][3] = 0; // clear lazy of current node
    }
  }
  void upd(int n, int b, int e, int i, int j, int id, ll x) {
    if (i > e || j < b) return;
    if (i <= b && e <= j) {
      add_node(n, b, e, id, x);
      return;
    }
    push(n, b, e);
    int m = (b + e) >> 1;
    int l = (n << 1) + 1, r = (n << 1) + 2;
    upd(l, b, m, i, j, id, x);
    upd(r, m+1, e, i, j, id, x);
    t[n][0] = (t[l][0] + t[r][0]) % mod;
    t[n][2] = (t[l][2] + t[r][2]) % mod;
    t[n][4] = (t[l][4] + t[r][4]) % mod;
  }
  ll qry(int n, int b, int e, int i, int j) {
    if (i > e || j < b) return 0;
    if (i <= b && e <= j) return t[n][4] % mod;
    push(n, b, e);
    int m = (b + e) >> 1;
    int l = (n << 1) + 1, r = (n << 1) + 2;
    return (qry(l, b, m, i, j) + qry(r, m+1, e, i, j)) % mod;
  }
};

int main() {
  int n,q;
  scanf("%d%d", &n, &q);
  for(int i=0;i<n;i++) scanf("%lld", &aa[i]);
  for(int i=0;i<n;i++) scanf("%lld", &bb[i]);
  ST tree;
  tree.bld(0,0,n-1);
  while(q--) {
    int tp,l,r;
    ll x;
    scanf("%d%d%d", &tp, &l, &r);
    l--; r--;
    if(tp == 1) {
      scanf("%lld", &x);
      tree.upd(0,0,n-1,l,r,0,x); // add to aa
    }
    else if(tp == 2) {
      scanf("%lld", &x);
      tree.upd(0,0,n-1,l,r,1,x); // add to bb
    }
    else{
      printf("%lld\n", tree.qry(0,0,n-1,l,r));
    }
  }
  return 0;
}
// https://atcoder.jp/contests/abc357/tasks/abc357_f
