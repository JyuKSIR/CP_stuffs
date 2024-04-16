#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a=1,p,n;
    cin>>n;
    while(a>0){
      string k=to_string(n),s;
      int step=0;
      for(int i=0; i<k.size(); ++i){
        if(k[i]=='0' || k[i]=='1'){
            step++;
        }
      }
      if(step==k.size()){
        cout<<"YES"<<endl;
        break;
      }
      else{
            if(n%11==0){
            n=n/11;
        }    
        else{
            s=to_string(n);
            int count=0;
            for(int j=0; j<s.size(); ++j){
                if(s[j]=='0' || s[j]=='1'){
                    count++;
                }
            }
            if(s.size()==count){
                cout<<"YES"<<endl;
                break;
            }
            else{
                cout<<"NO"<<endl;
                break;
            }
        }
      }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }


return 0;
}