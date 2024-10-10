// https://lightoj.com/problem/mathematically-hard

#include <bits/stdc++.h>
using namespace std;

#define dbg(a) cerr << __LINE__ << " no. line: " << #a << " = " << a << endl

const int N = 5e6;
int phi[N+2];
unsigned long long sum[N+2];

void totient() {

    for (int i = 0; i <= N; i++) {
        phi[i] = i;  
    }

    for (int i = 2; i <= N; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= N; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

void calclulate_sum(){

    sum[1] = 0;

    for(int i=2; i<=N; i++){

        sum[i] = phi[i];
        sum[i] *= phi[i];
        sum[i] += sum[i-1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    totient();
    calclulate_sum();

    int t,a,b; 
    cin >> t; 
    for (int i = 1; i <= t; i++) {
        cin >> a >> b;
        cout << "Case " << i << ": " << sum[b] - sum[a-1] << "\n";
    }
    return 0;
}
