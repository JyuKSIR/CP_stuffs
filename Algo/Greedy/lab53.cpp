#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  double c;
  cin >> n >> c;
  double v[n], w[n], r[n];
  for(int i = 0; i < n; i++) cin >> w[i];
  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 0; i < n; i++) r[i] = v[i] / w[i];
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < n - i - 1; j++){
      if(r[j] < r[j + 1]) {
        swap(r[j], r[j + 1]);
        swap(v[j], v[j + 1]);
        swap(w[j], w[j + 1]);
      }
    }
  }

  double t = 0.0;

  for(int i = 0; i < n; i++){
    if(w[i] <= c){
      t += v[i];
      c -= w[i];
    }
    else{
      t += v[i] * ((double)c / w[i]);
      break;
    }
  }

  cout << "Maximum value = " << t;

  return 0;
}