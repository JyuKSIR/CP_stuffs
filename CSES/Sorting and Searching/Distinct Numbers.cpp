// https://cses.fi/problemset/task/1621
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  int a[n];
  map<int,int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  cout << mp.size();
}
