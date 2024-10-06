// https://www.spoj.com/problems/COMDIV/

#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl


// basic 

// void solve(){

//     int n,m,count=0;
//     cin >> n >> m;
    
//     vector<int> first;
//     vector<int> second;

//     for(int i=1; i*i <= n; i++){
//         if(n%i == 0){
//             first.push_back(i);
//             first.push_back(n/i);
//         }
//     }

//     for(int j=1; j*j <= m; j++){
//         if(m%j == 0){
//             second.push_back(j);
//             second.push_back(m/j);
//         }
//     }

//     sort(first.begin(),first.end());
//     sort(second.begin(),second.end());
    
//     for(int i=0; i< first.size(); i++){
//         for(int j=0; j< second.size(); j++){
//             if(first[i] == second[j]){
//                 count++;
//             }
//         }
//     }
//     cout << count << "\n";
// }

// optimized

// if 30, 45 have common divisors their gcd's(15) divisors count will be their common divisor count

void solve(){

    int n,m,count = 0; cin >> n >> m;

    int x = __gcd(n,m);

    for(int i=1; i*i <= x; i++){
        if(x%i == 0){
            if(x/i == i){
                count++;
            }
            else{
                count +=2;
            }
        }
    }

    cout << count << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
      solve();
    }

  return 0;
}