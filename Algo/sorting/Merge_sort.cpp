#include <iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int> &l, vector<int> &r){
  int n = l.size(), m = r.size();
  vector<int> ans;
  int i = 0, j = 0;
  while(i < n && j < m){
    if(l[i] < r[j]){
      ans.push_back(l[i]);
      i++;
    }
    else{
      ans.push_back(r[j]);
      j++;
    }
  }
  while(i < n){
    ans.push_back(l[i]);
    i++;
  }
  while(j < m){
    ans.push_back(r[j]);
    j++;
  }
  return ans;
}
vector<int> v;
vector<int> merge_sort(int l, int r){
  // cout << "To sort : [" << l << "," << r << "] --> ";
  // for(int i = l; i <= r; i++) cout << v[i] << " ";
  // cout << "\n";   
  if(l == r) return {v[l]};
  int mid = (l + r) / 2;
  vector<int> left = merge_sort(l, mid);
  vector<int> right = merge_sort(mid + 1, r);
  // debug
  // for(auto x : left) cout << x << " ";
  // cout << "+ ";
  // for(auto x : right) cout << x << " ";
  // cout << "\n";
  return merge(left, right);
}

int main(){
  int n; cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  vector<int> ans = merge_sort(0, n - 1);
  for(int i = 0; i < n; i++){
    cout << ans[i] << " ";
  }
}
