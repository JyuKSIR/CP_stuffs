#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);

	string s; getline(cin, s);
	vector<string> v;
	string ss = "";
	for(int i = 0; i < (int)s.size(); i++){
    if(s[i] == 44 || s[i] == 46 || s[i] == ' '){
      if(!ss.empty()) v.push_back(ss);
      ss = "";
    }
    else ss += s[i];
	}
	if(!ss.empty())v.push_back(ss);
	ll ans = 0;
	for(auto x : v){
    ans += (x.size() + 5 - 1) / 5;
	}
	cout << ans;
}
