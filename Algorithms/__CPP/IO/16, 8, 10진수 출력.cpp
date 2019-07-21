/****** std ��� Ȱ�� ******/
#include <iostream>

int main() {
	int input;

	std::cout<<"10���� ���� �Է�: ";
	std::cin>>input;

	std::cout<<"8����: "<< std::oct <<input<<"\n";
	std::cout<<"10����: "<< std::dec <<input<<"\n";
	std::cout<<"16����: "<< std::hex <<input<<"\n";
}


/****** bitset Ȱ�� ******/
#include <bitset>
//----- 10->2 -----//
cout << bitset<4>(5) << endl;    //0101 :4 bit �ڸ��� Ȯ��, 2������ ���
bitset<4>(6).to_string();  //6 �� ��0110�� �� string ���� ��ȯ
//----- 2->10 -----//
bitset<4>("0110").to_ulong; //0 �� 1�� �� ���ڿ� �Ǵ� string �� unsigned long ���� ��ȯ


/****** iomanip Ȱ�� ******/
#include <iomanip>
//----- 1ȸ�� -----//
cout << setw(����);  //���� ��ŭ �ڸ����� Ȯ���ϰ� �� ���� ���� ���� ���
//----- ��������� -----//
cout << showbase;
cout << oct;        // ���λ� 0 ���
cout << hex;        // ���λ� 0x ���
cout << dec;        // ���λ� ����
cout << left;       // �ڸ��� Ȯ���� ��� ������
cout << right;      // �ڸ��� Ȯ���� ��� ������(�⺻ ����)
cout << setfill('c'); // Ȯ���� �ڸ������� ��µ��� ���� �κ��� ��ȣ ���� ���ڷ� ä��
cout << internal;	// �ڸ����� Ȯ���ؼ� ����ϴ� ��� Ȯ���� �ڸ��� �ֿ����� ���ξ ���, ���� �����ķ� ����Ͽ� ���� ������ Ȯ����
cout << uppercase;  // 16������ �빮�ڷ� ���
cout << nouppercase;// 16 ������ �ҹ��ڷ� ���. lowercase�� �ƴԿ� ����

std::ios_base::fmtflags oldFlags = std::cout.flags(); // cout ��� ���Ŀ� ���� �÷��׸� ��ȯ���ش� (fmtflags �� �����δ� int ��)
char oldFillChar = cout.fill(); // setfill(�����ڡ�) �� ����� �����ڡ��� �����Ѵ�. �⺻���� �� ���̴�.

cout.flags(oldFlags); // ��ó�� �����ߴ� ���� �־ �ǰ�, �ʱⰪ�� 513(0x0201)�̹Ƿ� �� ���� �μ��� �ѱ�� �⺻���� ��»��°� �ȴ�.
cout.fill('c') //�̰� ���� �����ߴ� ���� �ٽ� �־ �ǰ�, �ʱ� ������ �� ��(32) �� ������ ��������, Ȯ���� �ڸ����� ä������. 

cout << showbase << internal << setfill('0') << hex; cout << setw(6) << 100 << endl; cout.flags(513); cout.fill(' '); cout << setw(6) << 100 << endl;