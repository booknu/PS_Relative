/************
<주소>		: p453 - 문제 2
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char *title; // 제목
	char *isbn; // 도서 번호
	int price;

public:
	Book(char *title, char *isbn, int price) : price(price) {
		int len = strlen(title) + 1;
		this->title = new char[len];
		strcpy_s(this->title, len, title);
		
		len = strlen(isbn) + 1;
		this->isbn = new char[len];
		strcpy_s(this->isbn, len, isbn);
	}

	// 복사 생성자
	Book(Book &copy) : price(copy.price) {
		cout << "Book copy const: " << copy.title << endl;
		int len = strlen(copy.title) + 1;
		this->title = new char[len];
		strcpy_s(this->title, len, copy.title);

		len = strlen(copy.isbn) + 1;
		this->isbn = new char[len];
		strcpy_s(this->isbn, len, copy.isbn);
	}

	// 대입 연산자
	virtual Book& operator=(const Book &copy) {
		cout << "Book& operator=" << endl;
		// 일단 메모리 해제
		delete[] title;
		delete[] isbn;

		// deep copy
		int len = strlen(copy.title) + 1;
		this->title = new char[len];
		strcpy_s(this->title, len, copy.title);

		len = strlen(copy.isbn) + 1;
		this->isbn = new char[len];
		strcpy_s(this->isbn, len, copy.isbn);

		price = copy.price;

		return *this;
	}

	virtual void print() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}

	virtual ~Book() {
		cout << "dest Book" << endl;
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book {
private:
	char *DRMKey;

public:
	EBook(char *title, char *isbn, int price, char *DRM)
		: Book(title, isbn, price) {
		int len = strlen(DRM) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, DRM);
	}

	// 복사 생성자
	EBook(EBook &copy) : Book(copy) {
		cout << "EBook copy const" << endl;
		int len = strlen(copy.DRMKey) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, copy.DRMKey);
	}

	// 대입 연산자
	virtual EBook& operator=(const EBook &copy) {
		cout << "EBook& operator=" << endl;
		// Base의 operator= 연산자 명시적 호출
		Book::operator=(copy);

		// 메모리 해제
		delete[] DRMKey;

		// 깊은 복사
		int len = strlen(copy.DRMKey) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, copy.DRMKey);

		return *this;
	}

	virtual void print() {
		Book::print();
		cout << "인증키: " << DRMKey << endl;
	}

	virtual ~EBook() {
		cout << "dest EBook: " << DRMKey << endl;
		delete[] DRMKey;
	}
};

class Main {
public:
	static int main() {
		cout << "[ originals ]" << endl;

		Book b("좋은 C++", "555-12345-890-0", 20000);
		b.print();
		cout << endl;

		EBook eb("좋은 C++ E-Book 개정판", "555-12345-890-1", 10000, "wjsjnd12ax");
		eb.print();
		cout << endl;

		cout << "[ copy constructor ]" << endl;
		Book c1 = b;
		Book &c2 = eb; // 참조자 c2가 eb를 참조하게 됨 (복사 생성자X)
		c1.print();
		cout << endl;
		c2.print();
		cout << endl;

		cout << "[ operator= ]" << endl;
		EBook eb2("E-BOOK", "111-111-111", 9999, "pass");
		c1 = b;
		c2 = eb2; // Book::operator= 사용되서 복사됨 (오류임) (DRM이 복사되지 않고, 원래 있던 DRM은 삭제되지 않음) (또한 소멸자도 Book의 소멸자로 불림)
				  // c2가 참조하고 있는 객체를 바꾸는 것임.
		c1.print();
		cout << endl;
		c2.print();
		cout << endl;


		return 0;
	}
};
