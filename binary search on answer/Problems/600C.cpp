#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k; cin >> n >> k;
  int a[n + 1]{}, pf[n + 1]{}; // 1 based indexing
  int s = -1, e = -1;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    pf[i] = pf[i - 1] + a[i];
  }
  auto f = [&](int m){
    int c = m;
    for(int i = 1; c <= n; i++, c++){
      int zc = m - (pf[c] - pf[i - 1]);
      if(zc <= k){
        s = i, e = c;
        return 0;
      }
    }
    return 1;
  };
  int l = 1, r = n;
  while(l <= r){
    int m = (l + r) / 2;
    if(f(m)) r = m - 1; // if we can make segment size of mid
    else l = m + 1;     // when we can make segment size of mid?
  }                     // if the segment has zero count <= k
  cout << r << "\n";

  for(int i = s; i <= e; i++){
    a[i] = 1;
  }
  for(int i = 1; i <= n; i++) cout << a[i] << " ";
  
  return 0;
}
