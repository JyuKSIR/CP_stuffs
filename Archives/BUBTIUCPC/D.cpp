#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = 1e8;

  int p[10][11];
  for(int x = 0; x <= 9; x++) {
    int val = 1;
    for (int d = 1; d <= 10; d++) {
      val *= x;
      p[x][d] = val;
    }
  }

  for (int i = 1; i <= n; i++) {
    int num = i;
    int d = (int)log10(i) + 1;
    int sum = 0;
    while (num) {
      int x = num % 10;
      sum += p[x][d];
      num /= 10;
    }
    if (sum == i)
      cout << i << " ";
  }

  return 0;
}
// this problem is based on armstrong numbers so first we have to compute armstrong numbers till 1e8 and then store it and then binary search
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

void solve() {
  vector<int> v = {1,2,3,4,5,6,7,8,9,153,370,371,407,1634,8208,9474,54748,92727,93084,548834,1741725,4210818,9800817,9926315,24678050,24678051,88593477};
  int l, r; cin >> l >> r;
  if(l > r) swap(l,r);
  int x = lower_bound(v.begin(), v.end(), l) - v.begin();
  int y = upper_bound(v.begin(), v.end(), r) - v.begin();
  cout << y - x << "\n";
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
// https://toph.co/arena?practice=69328cb8ac9eedc4e59a6174#!/s/1859821
