#include <iostream>
#include <vector>
using namespace std;

const int inf = -1e9 + 7;

vector<int> merge(vector<int> &l, vector<int> &r){
  int n = l.size(), m = r.size();
  vector<int> L = l, R = r;
  L.push_back(inf);
  R.push_back(inf);
  vector<int> ans;
  int i = 0, j = 0;
  for(int k = 0; k < n + m; k++){
    if(L[i] >= R[j]){
      ans.push_back(L[i]);
      i++;
    }
    else{
      ans.push_back(R[j]);
      j++;
    }
  }
  return ans;
}

vector<int> v;
vector<int> merge_sort(int l, int r){
  if(l == r) return {v[l]};
  int mid = (l + r) / 2;
  vector<int> left = merge_sort(l, mid);
  vector<int> right = merge_sort(mid + 1, r);
  return merge(left, right);
}

int main(){
  int n;
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  vector<int> ans = merge_sort(0, n - 1);
  for(int x : ans) cout << x << " ";
}
