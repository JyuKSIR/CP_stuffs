#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,k; cin >> n >> k;
    int ar[n], lewra[n];

    memset(lewra,-1,sizeof(lewra));

    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    
    function<int(int)> frog = [&](int i){

        if(i == 0) return lewra[i] = 0;

        if(lewra[i] != -1) return lewra[i];

        int cost = INT_MAX;

        for(int j = 1; j<=k; j++){
            if(i-j >= 0) 
                cost = min(cost, frog(i-j) + abs(ar[i]-ar[i-j]));
        }
        return lewra[i] = cost;

    };

    frog(n-1);

    // for(int i=0; i<n; i++){
    //     cout << lewra[i] << " ";
    // }

    cout << lewra[n-1] << "\n";

  return 0;
}
