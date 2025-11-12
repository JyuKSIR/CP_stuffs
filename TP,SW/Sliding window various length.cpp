// Variable length sliding window
// we are given an array we have to find the maximum subarray length with all unique element

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  map<int,int> mp;
  deque<int> dq;
  int mx = 0;
  for(int i = 0; i < n; i++){
    if(mp[a[i]]){
      while(1){
        int x = dq.front();
        dq.pop_front();
        mp[x] = 0;
        if(x == a[i]) break;
      }
    }
    dq.push_back(a[i]);
    mp[a[i]] = 1;
    mx = max(mx, (int)dq.size());
  }
  cout << mx << "\n";
  return 0;
}
