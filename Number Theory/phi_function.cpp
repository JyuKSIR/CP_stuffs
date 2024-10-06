#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

const int N = 1e5 + 9;

int phi[N];

void totient_by_prime(){
    
    for(int i=1; i< N; i++){
        phi[i] = i;
    }

    for(int i = 2; i < N; i++){
        if(phi[i] == i){
           for(int j = i; j < N; j += i){
            //cout << "i: " << i << " " <<phi[j] << "\n";
            phi[j] -= phi[j]/i;
            //cout << "j: " << j << " " << phi[j] << "\n";
           } 
        }
    }

    for(int i = 2; i<1000; i++){
        cout << phi[i] << " ";
    }

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    totient_by_prime();

  return 0;
}