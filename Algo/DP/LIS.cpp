#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int main() {
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  int a[n + 1], dp[n + 1], parent[n + 1];

  cout << "Enter elements: ";
  for(int i = 1; i <= n; i++) cin >> a[i];

  a[0] = INT_MIN;
  dp[0] = 0;
  parent[0] = -1;

  for(int i = 1; i <= n; i++) {
    dp[i] = 1;
    parent[i] = 0;
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < i; j++) {
      if(a[j] < a[i] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        parent[i] = j;
      }
    }
  }

  int maxLen = 0, maxIdx = 0;
  for(int i = 1; i <= n; i++) {
    if(dp[i] > maxLen) {
      maxLen = dp[i];
      maxIdx = i;
    }
  }

  cout << "\nIndex:  ";
  for(int i = 0; i <= n; i++) cout << setw(4) << i;

  cout << "\nInput:  ";
  cout << setw(4) << 0;
  for(int i = 1; i <= n; i++) cout << setw(4) << a[i];

  cout << "\nLength: ";
  cout << setw(4) << dp[0];
  for(int i = 1; i <= n; i++) cout << setw(4) << dp[i];

  cout << "\nPrev:   ";
  cout << setw(4) << parent[0];
  for(int i = 1; i <= n; i++) cout << setw(4) << parent[i];

  int seq[n];
  int count = 0;

  int cur = maxIdx;
  while(cur != -1 && cur != 0) {
    seq[count++] = a[cur];
    cur = parent[cur];
  }

  cout << "\n\nLIS Length: " << maxLen << endl;

  cout << "LIS: ";
  for(int i = count - 1; i >= 0; i--) {
    cout << seq[i];
    if(i != 0) cout << " -> ";
  }
  cout << endl;

  return 0;
}