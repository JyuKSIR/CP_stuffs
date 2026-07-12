// https://cses.fi/problemset/task/2216/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  int a[n], fq[n + 1]{};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    fq[a[i]] = i + 1;
  }
  int ct = 1;
  for (int i = 1; i < n; i++) {
    if (fq[i] > fq[i + 1]) {
      ct++;
    }
  }
  cout << ct << '\n';
}
