#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

void solve() {
  ll n, k; cin >> n >> k;
  string s; cin >> s;
  vector<ll> v;
  for(ll i = 0; i < n; i++){
    if(s[i] == '1') v.push_back(i + 1);
  }
  ll ct = (ll)v.size();
  if(ct == 0){
    cout << "Sleep > Chocolate\n";
    return;
  }
  ll in = k % ct;
  if(in == 0){
    cout << v[(ll)v.size()-1] << "\n";
  }
  else{
    in--;
    cout << v[in] << "\n";
  }
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
// https://toph.co/arena?practice=6931a8d614df1845b23b4841#!/p/691403398b05feb382d26c89
