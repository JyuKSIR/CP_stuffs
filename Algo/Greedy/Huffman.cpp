#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
using namespace std;

void gen(int u, string s, vector<int>& l, vector<int>& r,
         vector<char>& ch, map<char,string>& cd){
  if(l[u] == -1 && r[u] == -1){
    cd[ch[u]] = s;
    cout << ch[u] << ": " << s << "\n";
    return;
  }

  if(l[u] != -1) gen(l[u], s + "0", l, r, ch, cd);
  if(r[u] != -1) gen(r[u], s + "1", l, r, ch, cd);
}

int main(){
  string t;
  getline(cin, t);

  map<char,int> fr;
  for(char c : t) fr[c]++;

  int n = fr.size();
  int mx = 2 * n;

  vector<int> l(mx, -1), r(mx, -1), f(mx);
  vector<char> ch(mx);

  int id = 0;

  for(auto p : fr){
    ch[id] = p.first;
    f[id] = p.second;
    id++;
  }

  priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
  > pq;

  for(int i = 0; i < n; i++)
    pq.push({f[i], i});

  while(pq.size() > 1){
    auto a = pq.top(); pq.pop();
    auto b = pq.top(); pq.pop();

    int u = id++;

    f[u] = a.first + b.first;
    l[u] = a.second;
    r[u] = b.second;

    pq.push({f[u], u});
  }

  int rt = pq.top().second;

  map<char,string> cd;

  cout << "Huffman Codes:\n";
  gen(rt, "", l, r, ch, cd);

  string en = "";
  for(char c : t) en += cd[c];

  cout << "\nOriginal String:\n" << t << "\n";
  cout << "\nEncoded Data:\n" << en << "\n";

  string de = "";
  int u = rt;

  for(char b : en){
    if(b == '0') u = l[u];
    else u = r[u];

    if(l[u] == -1 && r[u] == -1){
      de += ch[u];
      u = rt;
    }
  }

  cout << "\nDecoded Data:\n" << de << "\n";

  return 0;
}
