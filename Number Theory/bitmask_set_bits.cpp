#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    int ar[n]{};

    for(int i=0; i<n; i++){
        int x; cin >> x;
        for(int j=0; j<x; j++){
            int y; cin >> y;
            ar[i] |= (1 << y); // setting yth bit
        }
    }

    // for(int i=0; i<n; i++){
    //     cout << ar[i] << "\n";
    //     cout << bitset<30>(ar[i]) << "\n";
    // }

    int mdays = 0,p1 = -1, p2 = -1;

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int same = __builtin_popcount(ar[i] & ar[j]);
            if(mdays < same){
                mdays = same;
                p1 = i;
                p2 = j;            }
        }
    }

    cout << p1 << " " << p2 << " " << mdays;

  return 0;
}
