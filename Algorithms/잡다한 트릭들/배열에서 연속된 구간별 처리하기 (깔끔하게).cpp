int main(void) {
	// delim ������ �����ϴ� ���
	int p = 0;
	FOR(i, 0, n+1) {
		if(i == n || ar[i] == delem) {
			// ���� ���� ó���ϰ� [p, i)
			// .... DO SOMETHING .... //
			// ���� ���� �������� ���� ������
			p = i+1;
		}
	}

	// ���� ���� ������ �����ϴ� ���
	int p = 0;
	FOR(i, 1, n+1) {
		if(i == n || ar[i] != ar[i-1]) {
			// ���� ���� ó���ϰ� [p, i)
			// .... DO SOMETHING .... //
			// ���� ���� �������� ���� ������
			p = i;
		}
	}
}

// online���� ����ϰ� ó���ϴ� ��
int main(void) {
	int p = 0, pp = 0; // p: ���� ������ ������, p2: ���� ������ ������
	FOR(i, 0, n) {
		if(ar[p] != ar[i]) { // change seg start points
			pp = p;
			p = i;
		}
		// .... DO SOMETHING: [pp, p), [p, i) --> prev/cur segs .... //
	}
}