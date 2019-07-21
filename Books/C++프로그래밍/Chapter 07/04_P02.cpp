///************
//<�ּ�>		: p312 - ���� 2
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Book {
//private:
//	char *title; // ����
//	char *isbn; // ���� ��ȣ
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
//		cout << "����: " << title << endl;
//		cout << "ISBN: " << isbn << endl;
//		cout << "����: " << price << endl;
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
//		cout << "����Ű: " << DRMKey << endl;
//	}
//
//	~EBook() {
//		delete[] DRMKey;
//	}
//};
//
//int main() {
//	Book b("���� C++", "555-12345-890-0", 20000);
//	b.print();
//	cout << endl;
//
//	EBook eb("���� C++ E-Book ������", "555-12345-890-1", 10000, "wjsjnd12ax");
//	eb.print();
//
//	return 0;
//}