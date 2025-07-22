#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    // dividing n by 2; (right shift)
    cout << (n >> 1) << "\n";
    // multiplying n by 2; (left shift)
    cout << (n << 1) << "\n";

    char c = 'A',
    d = 'a';

    c |= ' ';  // upper case to lower case or with ' '
    d &= '_';  // lower case to upper case and with '_'

    cout << c << " " << d << "\n";

    // checking power of 2

    int k; cin >> k;

    if((k & (k-1)) == 0){
        cout << "power of 2";
    }
    else cout << "not power of 2";

    // xor xor xor !!!!!

    // xor of two same number is 0 (x ^ x = 0)
    // xor with 0 is (x ^ 0 = x)
    // x ^ y ^ z = x ^ z ^ y = y ^ x ^ z

  return 0;
}