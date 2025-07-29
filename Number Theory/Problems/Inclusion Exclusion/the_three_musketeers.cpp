#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){
    int n; cin >> n;
    string ar[n];
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    function<bool(char)> vow = [](char p){
        return p == 'a' || p == 'e' || p == 'i' || p == 'o' || p == 'u';
    };
    function<vector<string>(string)> bitsubset = [](string s){
        vector<string> v;
        int sz = (int)s.size();
        for(int i = 1; i < (1 << sz); i++){
            string subset;
            for(int j = 0; j < sz; j++){
                if(i & (1 << j)) subset += s[j];
            }
            v.push_back(subset);
        }
        return v;
    };
    unordered_map <string,ll> um;
    for(int i = 0; i < n; i++){
        // only taking the distinct vowels from i th string
        set<char> dis_vl;
        for(auto c : ar[i]){
            if(vow(c)){
                dis_vl.insert(c);
            }
        }
        // making another string using the distinct vowels
        string only_vl;
        for(auto c : dis_vl){
            only_vl += c;
        }
        vector<string> subsets = bitsubset(only_vl);
        for(auto subs : subsets){
            um[subs]++;
        }
    }
    // for(auto [a,b] : um){
    //     cout << a << " " << b << "\n";
    // }
    // from here inclusion exclusion and must work with ct >= 3
    ll ans = 0;
    for(auto [a,b] : um){
        if(b < 3) continue;
        ll ct = b;
        ll way = (b * (b-1) * (b-2)) / 6;
        if((int)a.size() & 1) ans += way;
        else ans -= way;
    }
    cout << ans << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    
    while(t--){
       solve();
    }

  return 0;
}
// https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/
