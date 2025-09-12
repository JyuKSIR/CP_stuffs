#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  string s; cin >> s;
  stack<char> st;

  for(int i = 0; i < s.size(); i++){
    if(s[i] == '(' || s[i] == '{' || s[i] == '['){
      st.push(s[i]);
    }
    else{
      if(st.empty()){
        cout << "No\n";
        return 0;
      }
      if(s[i] == ')'){
        if(st.top() == '(') st.pop();
      }
      if(s[i] == '}'){
        if(st.top() == '{') st.pop();
      }
      if(s[i] == ']'){
        if(st.top() == '[') st.pop();
      }
    }
  }
  if(st.empty()) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}
// https://toph.co/p/matching-brackets
