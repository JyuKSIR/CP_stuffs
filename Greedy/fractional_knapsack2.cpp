#include <bits/stdc++.h>
using namespace std;

bool jinish(pair<int, int> a, pair<int, int> b) {
	return a.second * b.first > a.first * b.second;
}

int main() {
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), jinish);

    double ans = 0.0;
    for (int i = 0; i < n && w > 0; i++) {
        int z = min(w, v[i].first);
        ans += z * (double)v[i].second / v[i].first;
        w -= z;
    }

    cout << ans << "\n";
}
