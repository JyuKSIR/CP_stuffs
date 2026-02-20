#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  function<int(int)> as = [&](int n){
    if(n < 0) return 0;
    return as(n - 1) + a[n];
  };
  cout << as(n - 1);
}

