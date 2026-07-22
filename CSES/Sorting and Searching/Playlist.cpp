// https://cses.fi/problemset/task/1141/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  set<int> st;
  int l = 0, r = 0, ans = 0 ;
  while (r < n) {
    while (st.count(a[r])) {
      st.erase(a[l]);
      l++;
    }
    st.insert(a[r]);
    ans = max(ans, r - l + 1);
    r++;
  }
  cout << ans;
}
