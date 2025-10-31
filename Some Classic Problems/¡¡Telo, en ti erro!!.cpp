#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<ll> d(n), e(n);
  for (int i = 0; i < n; ++i) cin >> d[i];
  for (int i = 0; i < n; ++i) cin >> e[i];

  vector<int> next(n, -1);
  stack<int> st;
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && d[st.top()] >= d[i]){
        st.pop();
    }
    if (!st.empty()) next[i] = st.top();
    st.push(i);
  }

  vector<int> v;
  for (int i = 0; i < n; i++){
    if (next[i] == -1 || e[i] > e[next[i]]){
      v.push_back(i + 1);
    }
  }
    

  cout << v.size() << "\n";
  for (int i = 0; i < (int)v.size(); ++i){
    cout << v[i] << " ";
  }
  cout << "\n";
}
// https://codeforces.com/gym/106017/problem/E
// Monotonic stack
