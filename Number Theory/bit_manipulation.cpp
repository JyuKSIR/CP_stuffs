#include<bits/stdc++.h>
using namespace std;

int main(){

    // 2^n = (1 << n)

    // printing a number in binary

    int n; cin >> n;

    auto print = [](int num) -> void{
        for(int i = 30; ~i; i--){
            cout << ((num >> i) & 1);
        }
    };

    //print(n); // when printing( right shift ( >> ))

    // given n numbers count how many set bits are there in which index

    int ar[n], ct[30]{};

    for(int i=0; i<n; i++) cin >> ar[i];

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < 30 ; j++){
            if((ar[i] & (1 << j))) ct[j]++; //(left shift)
        }
    }

    for(int i = 0 ; i < 30 ; i++){
        cout << i << " " << ct[i] << "\n";
    }

    // set 6th bit of all n numbers (or, left shift)

    for(int i = 0; i < n; i++){
        (ar[i] |= (1 << 6));
    }
    int ct2[30]{};

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < 30 ; j++){
            if((ar[i] & (1 << j))) ct2[j]++;
        }
    }

    for(int i = 0 ; i < 30 ; i++){
        cout << i << " " << ct2[i] << "\n";
    }

    // unset 6th bit of all n numbers (and,left shift)

    for(int i = 0; i < n; i++){
        (ar[i] &= ~(1 << 6));
    }

    int ct2[30]{};

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < 30 ; j++){
            if((ar[i] & (1 << j))) ct2[j]++;
        }
    }

    for(int i = 0 ; i < 30 ; i++){
        cout << i << " " << ct2[i] << "\n";
    }
    // toggle 6th bit of all n numbers

    for(int i = 0; i < n; i++){
        (ar[i] ^= (1 << 6));
    }
    // let a is a number and we want to find msb of a in which index we will write
    // __lg(a) thats how we got it in integer from
    // let a = 9 = 1001
    // here msb in 3rd index it will return 3
  return 0;
}
