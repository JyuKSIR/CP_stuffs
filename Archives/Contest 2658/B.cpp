#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  int x = 1000, y = 1000, z = 1000;
  while(n--){
    int ar[3];
    for(int i = 0; i < 3; i++){
      cin >> ar[i];
    }
    sort(ar, ar + 3);
    x = min(x, ar[0]);
    y = min(y, ar[1]);
    z = min(z, ar[2]);
  }
  cout << x * y * z;
  
  return 0;
}
// https://qoj.ac/contest/2658/problem/15408
