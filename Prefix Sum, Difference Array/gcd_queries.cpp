#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  int a[n + 1]{}, p[n + 1]{}, s[n + 1]{};

  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }

  for(int i = 1; i <= n; i++){
    p[i] = gcd(p[i - 1], a[i]);
  }

  for(int i = n; i >= 1; i--){
    s[i] = gcd(s[i + 1], a[i]);
  }

  while(q--){
    int l, r;
    cin >> l >> r;
    cout << gcd(p[l - 1], s[r + 1]) << "\n";
  }
}
