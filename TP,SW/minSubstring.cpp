#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

int main(){

    string s; cin >> s;
    int n = (int)s.size();
    unordered_set<char> us(s.begin(), s.end());
    int sz = (int)us.size();
    int need[26]{};
    for (auto c : us) {
        need[c - 'a'] = 1;
    }
    int have[26]{};
    int i = 0, j = 0, mn = INT_MAX, in = -1, ct = 0;
    while (j < n) {
        have[s[j] - 'a']++;
        if (have[s[j] - 'a'] == 1 && need[s[j] - 'a']) ct++;
        while (ct == sz) {
            if (j - i + 1 < mn) {
                mn = j - i + 1;
                in = i;
            }
            have[s[i] - 'a']--;
            if (have[s[i] - 'a'] == 0 && need[s[i] - 'a']) ct--;
            i++;
        }
        j++;
    }

    printf("%d ", mn);
    return 0;
}
// https://coderoj.com/problems/min-substring
