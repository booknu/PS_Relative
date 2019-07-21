// https://codeforces.com/blog/entry/11080
// http://codeforces.com/blog/entry/13279

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> treeset;

int main() {
	treeset s;
	s.insert(1);
	s.insert(2);
	s.insert(4);
	s.insert(8);
	s.insert(16);
	cout << *s.find_by_order(0) << endl; // 1
	cout << *s.find_by_order(1) << endl; // 2
	cout << *s.find_by_order(4) << endl; // 16
	cout << (s.end() == s.find_by_order(999)) << endl; // have no element: true

	cout<< s.order_of_key(-5) <<endl;  // 0
	cout<< s.order_of_key(1) <<endl;   // 0
	cout<< s.order_of_key(3) <<endl;   // 2
	cout<< s.order_of_key(4) <<endl;   // 2
	cout<< s.order_of_key(400) <<endl; // 5
}