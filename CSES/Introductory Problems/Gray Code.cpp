// https://cses.fi/problemset/task/2205/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  vector<string> v;
  for (int i = 0; i < (1 << n); i++) {
    int x = i ^ (i >> 1); // this makes sure the bit is unique
    string t = "";
    for (int j = 0; j < n; j++) {
      if (x & (1 << j)) t += '1';
      else t += '0';
    }
    reverse(t.begin(), t.end());
    v.push_back(t);
  }
  for (auto &s : v) {
    cout << s << '\n';
  }
}
