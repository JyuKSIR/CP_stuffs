// https://cses.fi/problemset/task/1622/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  string s; cin >> s;
  vector<string> v;
  sort(s.begin(), s.end());
  do {
    v.push_back(s);
  } while (next_permutation(s.begin(), s.end()));
  cout << (int)v.size() <<'\n';
  for (auto &s : v) {
    cout << s << '\n';
  }
}
