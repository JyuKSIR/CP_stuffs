#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    int a,b; cin >> a >> b;
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