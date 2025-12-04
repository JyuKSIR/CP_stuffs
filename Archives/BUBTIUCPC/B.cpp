#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

void solve() {
  int n; cin >> n;
  if(n & 1){
    cout << "second\n";
  }
  else cout << "first\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
// https://toph.co/arena?practice=6931a8d614df1845b23b4841#!/p/69289cd96ab12aa665e8c9c9
