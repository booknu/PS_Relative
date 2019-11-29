int main(void) {
	int n;
	// cin 사용시
	while(cin >> n);
	// cin 사용시 이렇게 하면 데이터 마지막에 공백이 있는 경우 while loop가 한 번 더 돈다!!!
	while(!cin.eof());
	// scanf 사용시
	while(scanf("%d", &n) > 0);
	// 소수점 출력 (반올림된다.)
	printf("%.2lf", x);
	
	cout << fixed;
	cout.precision(2);
}