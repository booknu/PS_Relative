/************
<주소>		: p200
**********
<해결방안>	:

iter = erase(p)		: p자리에 있는 원소를 지우고, 지운 자리에 있는 원소의 iter 반환
iter = erase(b, e)	: b ~ e 구간의 원소를 지우고, 지운 자리에 있는 원소의 iter 반환

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
using namespace std;
void printVector(const vector<int> &v) {
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(void) {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	printVector(v);

	vector<int>::iterator iter1 = v.begin() + 2;
	vector<int>::iterator iter2;
	iter2 = v.erase(iter1); // iter1의 위치에 있는 원소를 지우고, 그 후 그 자리에 있는 원소의 iter을 반환
	printVector(v);

	iter1 = v.begin() + 1;
	iter2 = iter1 + 2;
	v.erase(iter1, iter2); // iter1 ~ iter2의 위치에 있는 원소를 지우고, 그 자리에 있는 원소의 iter을 반환
	printVector(v);

	return 0;
}