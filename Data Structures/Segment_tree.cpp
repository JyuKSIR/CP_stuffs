#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

const int N = 3e5 + 5;
int a[N];

struct ST{
  int t[4*N];
  static const int inf = 1e9;

  ST(){
    memset(t, 0, sizeof(t));
  }

  void build(int n, int b, int e){
    if(b == e){
      t[n] = a[b];
      return;
    }
    int m = (b + e) >> 1, l = (n << 1) + 1 , r = (n << 1) + 2;
    build(l, b, m);
    build(r, m+1, e);
    t[n] = min(t[l], t[r]);
  }

  void upd(int n, int b, int e, int i, int x){
    if (b > i || e < i) return;
    if(b == e && b == i){
      t[n] = x;
      return;
    }
    int m = (b + e) >> 1, l = (n << 1) + 1 , r = (n << 1) + 2;
    upd(l, b, m, i, x);
    upd(r, m+1, e, i, x);
    t[n] = min(t[l], t[r]);
  }

  int query(int n, int b, int e, int i, int j){
    if(b > j || e < i) return inf;
    if(b >= i && e <= j) return t[n];
    int m = (b + e) >> 1, l = (n << 1) + 1 , r = (n << 1) + 2;
    int L = query(l, b, m, i, j);
    int R = query(r, m + 1, e, i, j);
    return min(L, R);
  }
};

int main(){
  int z,q; scanf("%d%d", &z, &q);
  for(int i = 0; i < z; i++){
    scanf("%d", &a[i]);
  }
  ST tree;
  tree.build(0,0,z-1);
  while(q--){
    int l, r; scanf("%d%d", &l, &r);
    l--,r--;
    int p = tree.query(0,0,z-1,l,r);
    printf("%d\n", p);
  }

 return 0;
}
TC :-
  build tree - O(n)
  point update - O(log(n))
  range update - O(rlog(n)) [till range r]
  query - O(log(n))
