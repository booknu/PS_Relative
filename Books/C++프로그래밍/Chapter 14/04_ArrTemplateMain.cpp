/************
<주소>		: p561
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include "04_ArrTemplate.h"
#include "04_Point.h"
class Main {
public:
	static int main() {
		// Point<int>
		Array<Point<int>> iArr(3);
		iArr[0] = Point<int>(3, 4);
		iArr[1] = Point<int>(5, 6);
		iArr[2] = Point<int>(7, 8);

		for (int i = 0; i < iArr.length; i++) {
			cout << iArr[i] << endl;
		}

		// Point<double>
		Array<Point<double>> dArr(3);
		dArr[0] = Point<double>(3.14, 4.31);
		dArr[1] = Point<double>(1.11, 2.22);
		dArr[2] = Point<double>(11.11, 10.11);

		for (int i = 0; i < dArr.length; i++) {
			dArr[i].print();
		}

		// Point<int*>
		typedef Point<int>* POINT_PTR;
		Array<POINT_PTR> pArr(3);
		pArr[0] = new Point<int>(3, 4);
		pArr[1] = new Point<int>(5, 6);
		pArr[2] = new Point<int>(7, 8);

		for (int i = 0; i < pArr.length; i++) {
			pArr[i]->print();
			delete pArr[i];
		}

		return 0;
	}
};