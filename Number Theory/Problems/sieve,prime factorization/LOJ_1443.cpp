#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

void solve(){

  int n; scanf("%d", &n);
  unordered_set<int> div, vis;
  set<int> pf;

  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      div.insert(i);
      if(i != n / i) {
        div.insert(n / i);
      }
    }
  }

  int t = n;
  for (int i = 2; i * i <= t; i++) {
    while (t % i == 0){
      pf.insert(i);
      t /= i;
    } 
  }
  if (t > 1) pf.insert(t);

  vector<int> ans;
  int x = 1, ct = (int)div.size() - 1;
  ans.push_back(x);
  vis.insert(x);

  for (int i = 0; i < ct;) {
    bool ok = 0;
    for (auto p : pf) {
      int a = x * p,
      b = x / p;
      if (div.count(a) && !vis.count(a)) {
        ans.push_back(a);
        vis.insert(a);
        x = a;
        i++; 
        ok = 1;
        break;
      }
      if (x % p == 0 && div.count(b) && !vis.count(b)) {
        ans.push_back(b);
        vis.insert(b);
        x = b; i++;
        ok = 1;
        break;
      }
    }
    if (!ok) break;
  }

  if(ans.size() == 2 && n != 2){
    printf("impossible\n");
    return;
  }

  for (auto k : ans) printf("%d ", k);

  printf("\n");
}

int main(){

  int t, i = 1; 
  scanf("%d", &t);
  while(t--){
    printf("Case %d: \n", i);
    solve();
    i++;
  }

 return 0;
}
// https://lightoj.com/problem/printing-divisors
