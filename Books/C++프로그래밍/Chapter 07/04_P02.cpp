///************
//<주소>		: p312 - 문제 2
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Book {
//private:
//	char *title; // 제목
//	char *isbn; // 도서 번호
//	int price;
//
//public:
//	Book(char *title, char *isbn, int price) : price(price) {
//		int len = strlen(title) + 1;
//		this->title = new char[len];
//		strcpy_s(this->title, len, title);
//		
//		len = strlen(isbn) + 1;
//		this->isbn = new char[len];
//		strcpy_s(this->isbn, len, isbn);
//	}
//
//	void print() {
//		cout << "제목: " << title << endl;
//		cout << "ISBN: " << isbn << endl;
//		cout << "가격: " << price << endl;
//	}
//
//	~Book() {
//		delete[] title;
//		delete[] isbn;
//	}
//};
//
//class EBook : public Book {
//private:
//	char *DRMKey;
//
//public:
//	EBook(char *title, char *isbn, int price, char *DRM)
//		: Book(title, isbn, price) {
//		int len = strlen(DRM) + 1;
//		DRMKey = new char[len];
//		strcpy_s(DRMKey, len, DRM);
//	}
//
//	void print() {
//		Book::print();
//		cout << "인증키: " << DRMKey << endl;
//	}
//
//	~EBook() {
//		delete[] DRMKey;
//	}
//};
//
//int main() {
//	Book b("좋은 C++", "555-12345-890-0", 20000);
//	b.print();
//	cout << endl;
//
//	EBook eb("좋은 C++ E-Book 개정판", "555-12345-890-1", 10000, "wjsjnd12ax");
//	eb.print();
//
//	return 0;
//}