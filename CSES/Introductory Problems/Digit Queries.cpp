// https://cses.fi/problemset/task/2431/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char kthdigit(ll k) {
  ll dct = 1; // digit count
  ll s = 1; // statrting of each group
  ll ct = 9; // number count in each group
  while (k > dct * ct) {
    k -= dct * ct;
    dct++;
    ct *= 10;
    s *= 10;
  }
  ll digit = s + ((k - 1) / dct);
  ll in = (k - 1) % dct;
  string ans = to_string(digit);
  return ans[in];
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  ll q; cin >> q;
  while (q--) {
    ll n; cin >> n;
    cout << kthdigit(n) << '\n';
  }
}
// https://www.youtube.com/watch?v=RF2vLHdk4Rs&t=1054s
