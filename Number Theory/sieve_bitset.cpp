#include <bits/stdc++.h>
using namespace std;

bitset<10000> bs;
vector<int> primes;

void sieve(long long n) {
    bs.set();
    bs[0] = bs[1] = 0;

    for (long long i = 2; i*i <= n; i++) {
        if (bs[i]) {
            primes.push_back((int)i);
            for (long long j = i * i; j < n; j += i) {
                bs[j] = 0;
            }
        }
    }
}

int main() {
    sieve(10000);

    for (int a : primes) {
        cout << a << " ";
    }

    return 0;
}
