// we are given a string consisting of letter a,b,c where we have to print minimum length
// a substring which contains a, b, c;

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;
  int n = (int)s.size();
  queue<char> q;
  deque<char> dq;
  map<char, int> mp;
  for(int i = 0; i < n; i++){
    q.push(s[i]);
  }
  while(1){
    char c = q.front();
    dq.push_back(c);
    mp[c]++;
    q.pop();
    if(mp.size() == 3) break;
  }
  int mn = n;
  while(1){
    mn = min(mn, (int)dq.size());
    // for(auto l : dq) cout << l;
    // cout << "\n";
    char c = dq.front();
    if(mp[c] == 1){
      while(!q.empty()){
        char cc = q.front();
        dq.push_back(cc);
        mp[cc]++;
        q.pop();
        if(mp[c] > 1) break;
      }
    }
    dq.pop_front();
    mp[c]--;
    if(mp[c] == 0) break;
  }
  cout << mn << "\n";
  
  return 0;
}
