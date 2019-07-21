/************
<�ּ�>		: p453 - ���� 2
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char *title; // ����
	char *isbn; // ���� ��ȣ
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

	// ���� ������
	Book(Book &copy) : price(copy.price) {
		cout << "Book copy const: " << copy.title << endl;
		int len = strlen(copy.title) + 1;
		this->title = new char[len];
		strcpy_s(this->title, len, copy.title);

		len = strlen(copy.isbn) + 1;
		this->isbn = new char[len];
		strcpy_s(this->isbn, len, copy.isbn);
	}

	// ���� ������
	virtual Book& operator=(const Book &copy) {
		cout << "Book& operator=" << endl;
		// �ϴ� �޸� ����
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
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
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

	// ���� ������
	EBook(EBook &copy) : Book(copy) {
		cout << "EBook copy const" << endl;
		int len = strlen(copy.DRMKey) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, copy.DRMKey);
	}

	// ���� ������
	virtual EBook& operator=(const EBook &copy) {
		cout << "EBook& operator=" << endl;
		// Base�� operator= ������ ����� ȣ��
		Book::operator=(copy);

		// �޸� ����
		delete[] DRMKey;

		// ���� ����
		int len = strlen(copy.DRMKey) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, copy.DRMKey);

		return *this;
	}

	virtual void print() {
		Book::print();
		cout << "����Ű: " << DRMKey << endl;
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

		Book b("���� C++", "555-12345-890-0", 20000);
		b.print();
		cout << endl;

		EBook eb("���� C++ E-Book ������", "555-12345-890-1", 10000, "wjsjnd12ax");
		eb.print();
		cout << endl;

		cout << "[ copy constructor ]" << endl;
		Book c1 = b;
		Book &c2 = eb; // ������ c2�� eb�� �����ϰ� �� (���� ������X)
		c1.print();
		cout << endl;
		c2.print();
		cout << endl;

		cout << "[ operator= ]" << endl;
		EBook eb2("E-BOOK", "111-111-111", 9999, "pass");
		c1 = b;
		c2 = eb2; // Book::operator= ���Ǽ� ����� (������) (DRM�� ������� �ʰ�, ���� �ִ� DRM�� �������� ����) (���� �Ҹ��ڵ� Book�� �Ҹ��ڷ� �Ҹ�)
				  // c2�� �����ϰ� �ִ� ��ü�� �ٲٴ� ����.
		c1.print();
		cout << endl;
		c2.print();
		cout << endl;


		return 0;
	}
};
