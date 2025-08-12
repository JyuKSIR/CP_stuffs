#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){

  ordered_set<int> s;

  // Insert elements
  s.insert(10);
  s.insert(20);
  s.insert(30);
  s.insert(40);

  // order_of_key(x) -> # of elements strictly less than x
  cout << "order_of_key(25) = " << s.order_of_key(25) << "\n"; // 2 (10, 20)
  cout << "order_of_key(40) = " << s.order_of_key(40) << "\n"; // 3

  // find_by_order(k) -> iterator to k-th smallest (0-indexed)
  cout << "find_by_order(0) = " << *s.find_by_order(0) << "\n"; // 10
  cout << "find_by_order(2) = " << *s.find_by_order(2) << "\n"; // 30

  // Erase element
  s.erase(20);

  // After erasing 20
  cout << "order_of_key(25) = " << s.order_of_key(25) << "\n"; // 1 (only 10)
  cout << "find_by_order(1) = " << *s.find_by_order(1) << "\n"; // 30

 return 0;
}

TC:
insert(x)        → O(log n)
erase(x)         → O(log n)
find(x)          → O(log n)
order_of_key(x)  → O(log n)   // # of elements strictly less than x
find_by_order(k) → O(log n)   // iterator to k-th smallest element (0-indexed)
iterate all      → O(n)

