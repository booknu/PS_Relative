/************
<주소>		: p618 - OOP 프로젝트 11단계
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include "OOP_Exceptions.h"
#include <iostream>
using namespace std;

void Exception::printStackTrace(char *msg) {
	cout << "Exception: " << msg << endl;
}

void IllegalArgumentException::printStackTrace(char *msg) {
	cout << "IllegalArgumentException: " << msg << endl;
}

void NegativeArgumentException::printStackTrace(char *msg) {
	cout << "NegativeArgumentException: " << msg << endl;
}

void LimitExceedException::printStackTrace(char *msg) {
	cout << "LimitExceedException: " << msg << endl;
}