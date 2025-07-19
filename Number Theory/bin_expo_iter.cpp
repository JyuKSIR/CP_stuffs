#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    int a,b; cin >> a >> b;   // a = 4 , b = 15
    const int m = 1e9+7;
    function<int(int,int)> expo = [](int a,int b){
        int ans = 1;
        while(b){
            if(b & 1) ans = (ans * 1LL * a) % m;
            a = (a * 1LL * a) % m;
            b = b >> 1;
        }
        return ans;
    };


    cout << expo(a,b);

  return 0;
}

   // b        a      ans

// 1 1 1 1    4     1*4 = 4
// 1 1 1      4^2   4*4^2 = 4^3
// 1 1        4^4   4^3 * 4^4 = 4^7
// 1          4^8   4^7 * 4^8 = 4^15
