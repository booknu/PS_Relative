/****** std 기능 활용 ******/
#include <iostream>

int main() {
	int input;

	std::cout<<"10진수 정수 입력: ";
	std::cin>>input;

	std::cout<<"8진수: "<< std::oct <<input<<"\n";
	std::cout<<"10진수: "<< std::dec <<input<<"\n";
	std::cout<<"16진수: "<< std::hex <<input<<"\n";
}


/****** bitset 활용 ******/
#include <bitset>
//----- 10->2 -----//
cout << bitset<4>(5) << endl;    //0101 :4 bit 자리를 확보, 2진수로 출력
bitset<4>(6).to_string();  //6 을 “0110” 로 string 으로 반환
//----- 2->10 -----//
bitset<4>("0110").to_ulong; //0 과 1로 된 문자열 또는 string 을 unsigned long 으로 변환


/****** iomanip 활용 ******/
#include <iomanip>
//----- 1회용 -----//
cout << setw(정수);  //정수 만큼 자릿수를 확보하고 그 범위 내에 값을 출력
//----- 여러번사용 -----//
cout << showbase;
cout << oct;        // 접두사 0 출력
cout << hex;        // 접두사 0x 출력
cout << dec;        // 접두사 없음
cout << left;       // 자릿수 확보한 경우 좌정렬
cout << right;      // 자릿수 확보한 경우 우정렬(기본 설정)
cout << setfill('c'); // 확보한 자릿수에서 출력되지 않은 부분을 괄호 안의 문자로 채움
cout << internal;	// 자릿수를 확보해서 출력하는 경우 확보한 자리의 최우측에 접두어를 출력, 값은 우정렬로 출력하여 사이 공간을 확보함
cout << uppercase;  // 16진수를 대문자로 출력
cout << nouppercase;// 16 진수를 소문자로 출력. lowercase가 아님에 주의

std::ios_base::fmtflags oldFlags = std::cout.flags(); // cout 출력 형식에 대한 플래그를 반환해준다 (fmtflags 는 실제로는 int 형)
char oldFillChar = cout.fill(); // setfill(‘문자’) 로 적용된 ‘문자’를 저장한다. 기본값은 ‘ ‘이다.

cout.flags(oldFlags); // 이처럼 저장했던 값을 넣어도 되고, 초기값이 513(0x0201)이므로 이 값을 인수로 넘기면 기본값의 출력상태가 된다.
cout.fill('c') //이것 역시 저장했던 값을 다시 넣어도 되고, 초기 설정인 ‘ ‘(32) 를 넣으면 공백으로, 확보한 자릿수가 채워진다. 

cout << showbase << internal << setfill('0') << hex; cout << setw(6) << 100 << endl; cout.flags(513); cout.fill(' '); cout << setw(6) << 100 << endl;