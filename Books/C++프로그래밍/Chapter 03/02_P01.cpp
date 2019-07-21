///************
//<ÁÖ¼Ò>		: p135 - ¹®Á¦ 1
//**********
//<ÇØ°á¹æ¾È>	:
//
//**********
//<¿À´ä³ëÆ®>	:
//
//*/
//
//#include <iostream>
//
//using namespace std;
//
//namespace CALC_CONST {
//	enum Oper{
//		ADD, SUB, MUL, DIV, NUM
//	};
//}
//
//class Calc {
//private:
//	int used[CALC_CONST::NUM];
//public:
//	void init();
//	double add(double a, double b);
//	double sub(double a, double b);
//	double mul(double a, double b);
//	double div(double a, double b);
//	void showStatus();
//};
//
//void Calc::init() {
//	// used¸¦ ¸ðµÎ 0À¸·Î ÃÊ±âÈ­
//	for (int i = 0; i < CALC_CONST::NUM; i++) {
//		used[i] = 0;
//	}
//}
//
//double Calc::add(double a, double b) {
//	used[CALC_CONST::ADD]++;
//	return a + b;
//}
//
//double Calc::sub(double a, double b) {
//	used[CALC_CONST::SUB]++;
//	return a - b;
//}
//
//double Calc::mul(double a, double b) {
//	used[CALC_CONST::MUL]++;
//	return a * b;
//}
//
//double Calc::div(double a, double b) {
//	used[CALC_CONST::DIV]++;
//	return a / b;
//}
//
//void Calc::showStatus() {
//	cout << "µ¡¼À: " << used[CALC_CONST::ADD];
//	cout << " »¬¼À: " << used[CALC_CONST::SUB];
//	cout << " °ö¼À: " << used[CALC_CONST::MUL];
//	cout << " ³ª´°¼À: " << used[CALC_CONST::DIV] << endl;
//}
//
//int main(void) {
//	Calc cal;
//	cal.init();
//	cout << "3.2 + 2.4 = " << cal.add(3.2, 2.4) << endl;
//	cout << "3.5 / 1.7 = " << cal.div(3.5, 1.7) << endl;
//	cout << "2.2 - 1.5 = " << cal.sub(2.2, 1.5) << endl;
//	cout << "4.9 / 1.2 = " << cal.div(4.9, 1.2) << endl;
//	cal.showStatus();
//}