#include<bits/stdc++.h>
using namespace std;

bool jinish(pair<int,int> a,pair<int,int> b){ 
	return a.second * b.first > a.first * b.second;
}

int main(){

	int n,w; cin >> n >> w;

	vector<pair<int,int>> v;

    for(int i=0; i<n; i++){
		int weight,price; cin >> weight >> price;
		v.push_back({weight,price});
	}

    sort(v.begin(),v.end(),jinish);

	double ans = 0.0; 
    for (auto p : v) {
		cout << p.first << " " << p.second << "\n"; 
        if (w >= p.first) {
            w -= p.first;
            ans += p.second;
        } else {
            ans += p.second * w / (double)p.first;
        }
    }
	cout << ans << "\n";
    	
}
