#include <bits/stdc++.h>
using namespace std;

void odd(int a){
    for (int i = 1; i <= a; ++i){
        if (i % 2 == 1){
            cout << "##";
        }
        else{
            cout << "..";
        }
    }
}
void even(int b){
    for (int i = 1; i <= b; ++i){
        if (i % 2 == 1){
            cout << "..";
        }
        else{
            cout << "##";
        }
    }
}
int main(){
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n;
        for (int j = 1; j <= n; ++j){
            if (j % 2 == 1){
                odd(n);
                cout << endl;
                odd(n);
                cout << endl;
            }
            else{
                even(n);
                cout << endl;
                even(n);
                cout << endl;
            }
        }
    }
    return 0;
}