#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    int ar[n], lewra[n];

    memset(lewra,-1,sizeof(lewra));

    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    
    function<int(int)> frog = [&](int i){

        if(i == 0) return lewra[i] = 0;

        if(lewra[i] != -1) return lewra[i];

        int cost = INT_MAX;

        cost = min(cost, frog(i-1) + abs(ar[i]-ar[i-1]));

        if(i > 1) cost = min(cost, frog(i-2) + abs(ar[i]-ar[i-2]));

        return lewra[i] = cost;

    };

    frog(n-1);

    // for(int i=0; i<n; i++){
    //     cout << lewra[i] << " ";
    // }

    cout << lewra[n-1] << "\n";

  return 0;
}
