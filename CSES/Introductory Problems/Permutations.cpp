// https://cses.fi/problemset/task/1070/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  if (n == 2 or n == 3) {
    cout << "NO SOLUTION";
    return 0;
  }
  for (int i = 2; i <= n; i += 2) {
    cout << i << ' ';
  }
  for (int i = 1; i <= n; i += 2) {
    cout << i << ' ';
  }
}
