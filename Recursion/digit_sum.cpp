#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  function<int(int)> ds = [&](int n){
    if(n == 0) return 0;
    return ds(n / 10) + n % 10;
  };
  cout << ds(n);
}

