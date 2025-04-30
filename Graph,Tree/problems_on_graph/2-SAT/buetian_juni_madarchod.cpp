//--> input 
// 73
// q e
// e ~v
// b ~h
// ~b ~k
// ~u a
// ~c ~v
// v ~q
// r ~q
// q ~x
// f a
// ~y a
// ~e l
// s n
// ~g ~x
// ~r j
// ~v v
// d ~c
// ~k m
// ~c s
// z x
// ~b ~w
// ~c ~s
// g t
// ~f ~h
// ~x ~z
// ~v ~a
// d s
// ~q h
// h ~r
// j ~o
// e ~e
// ~z e
// ~o ~e
// ~e ~x
// j ~v
// ~c ~p
// f z
// x ~n
// d i
// ~n j
// ~k ~d
// ~o ~m
// ~q ~a
// r s
// z ~n
// ~y c
// ~f x
// v ~r
// ~w ~n
// ~n i
// ~y p
// e y
// m u
// y a
// t ~o
// e q
// t ~s
// ~r ~r
// n ~v
// ~c ~u
// f b
// e z
// s n
// y t
// ~g ~i
// ~i ~d
// t ~o
// z ~f
// ~v o
// a l
// ~w ~f
// ~q ~o
// ~v r

// --> output
// 26
// a b c d e f g h i j k l m n o p q r s t u v w x y z 
// a -> 1
// b -> 1
// c -> 0
// d -> 0
// e -> 1
// f -> 0
// g -> 0
// h -> 0
// i -> 1
// j -> 1
// k -> 0
// l -> 1
// m -> 1
// n -> 0
// o -> 0
// p -> 0
// q -> 0
// r -> 0
// s -> 1
// t -> 1
// u -> 0
// v -> 0
// w -> 0
// x -> 0
// y -> 0
// z -> 1


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    vector<string> v;
    set<char> st;

    for(int i=1; i<=n; i++){
        string s; getline(cin,s);
        v.push_back(s);
        if(s.size() == 3){
            st.insert(s[0]);
            st.insert(s[2]);
        }
        if(s.size() == 4){
            if(s[0] == '~'){
                st.insert(s[1]);
                st.insert(s[3]);
            }
            if(s[2] == '~'){
                st.insert(s[0]);
                st.insert(s[3]);
            }
            
        }
        if(s.size() == 5){
            st.insert(s[1]);
            st.insert(s[4]);
        }
    }

    cout << st.size() << "\n";

    int m = (int)st.size();

    vector<int> g[2*m],gr[2*m],f;
    int vis[2*m]{},who[2*m];
    int ans[m];

    for(auto s : v){
        if(s.size() == 3){
            int a = s[0] - 'a';
            int b = s[2] - 'a';
            a*=2;
            b*=2;
            g[a^1].push_back(b);
            g[b^1].push_back(a);
            gr[b].push_back(a^1);
            gr[a].push_back(b^1);
        }
        if(s.size() == 4){
            if(s[0] == '~'){
                int a = s[1] - 'a';
                int b = s[3] - 'a';
                a*=2;
                b*=2;
                a^=1;
                g[a^1].push_back(b);
                g[b^1].push_back(a);
                gr[b].push_back(a^1);
                gr[a].push_back(b^1);
            }
            if(s[2] == '~'){
                int a = s[0] - 'a';
                int b = s[3] - 'a';
                a*=2;
                b*=2;
                b^=1;
                g[a^1].push_back(b);
                g[b^1].push_back(a);
                gr[b].push_back(a^1);
                gr[a].push_back(b^1);
            }
            
        }
        if(s.size() == 5){
            int a = s[1] - 'a';
            int b = s[4] - 'a';
            a*=2;
            b*=2;
            a^=1;
            b^=1;
            g[a^1].push_back(b);
            g[b^1].push_back(a);
            gr[b].push_back(a^1);
            gr[a].push_back(b^1);
        }
    }

    function<void(int)> dfs1 = [&](int p){
        vis[p] = 1;
        for(auto c : g[p]){
            if(!vis[c]){
                dfs1(c);
            }
        }
        f.push_back(p);
    };

    for(int i=0; i<2*m; i++){
        if(!vis[i]){
            dfs1(i);
        }
    }

    function<void(int,int)> dfs2 = [&](int p,int r){
        vis[p] = 0;
        who[p] = r;
        for(auto c : gr[p]){
            if(vis[c]){
                dfs2(c,r);
            }
        }
    };

    int ct = 0;

    for(int i = 2*m-1; ~i; i--){
        if(vis[f[i]]){
            dfs2(f[i],ct);
            ct++;
        }
    }


    for(int i=0; i<m; i++){
        if(who[2*i] == who[2*i+1]){
            cout << "-1\n";
        }
        ans[i] = (who[2*i] > who[2*i+1]) ? 1 : 0;
    }

    for(auto x : st) cout << x << " ";
    cout << "\n";
    for(int i=0; i<m; i++){
        char c = (char)('a'+i);
        cout << c << " -> " << ans[i] << "\n";
    }

  return 0;
}
