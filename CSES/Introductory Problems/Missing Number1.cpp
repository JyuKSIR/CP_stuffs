#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

  int n; cin >> n;
  n--;
  vector<int> v;
  for(int i = 1; i <= n; i++){
    int x; cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());

  for(int i = 0; i <= n; i++){
    if(v[i] != i + 1){
      cout << i + 1;
      break;
    }
  }
 return 0;
}
