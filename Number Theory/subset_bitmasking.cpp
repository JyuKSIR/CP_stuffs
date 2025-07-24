// let you have an array of n numbers and
// you have to print all the subsets of the array

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    int ar[n];
    for(auto &_ : ar) cin >> _;
    vector<vector<int>> v;
    int sz = (1 << n);
    for(int i = 0; i < sz; i++){
        vector<int> t;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                t.push_back(ar[j]);
            }
        }
        v.push_back(t);
    }

    for(auto x : v){
        for(auto a : x){
            printf("%d ",a);
        }
        printf("\n");
    }


  return 0;
}

// TC - O(n*(2^n))