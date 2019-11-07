
#include <cstdio>
#include <cctype>
class FastIO {
	int fd, bufsz;
	char *buf, *cur, *end;
public:
	FastIO(int _fd = 0, int _bufsz = 1 << 20) : fd(_fd), bufsz(_bufsz) {
		buf = cur = end = new char[bufsz];
	}
	~FastIO() { delete[] buf; }
	bool readbuf() {
		cur = buf;
		end = buf + bufsz;
		while(true) {
			size_t res = fread(cur, sizeof(char), end - cur, stdin);
			if(res == 0) break;
			cur += res;
		}
		end = cur;
		cur = buf;
		return buf != end;
	}
	bool hasNext() {
		while(true) {
			if(cur == end && !readbuf()) return false;
			if(isdigit(*cur) || *cur == '-') break;
			++cur;
		}
		return true;
	}
	int r() {
		while(true) {
			if(cur == end) readbuf();
			if(isdigit(*cur) || *cur == '-') break;
			++cur;
		}
		bool sign = true;
		if(*cur == '-') {
			sign = false;
			++cur;
		}
		int ret = 0;
		while(true) {
			if(cur == end && !readbuf()) break;
			if(!isdigit(*cur)) break;
			ret = ret * 10 + (*cur - '0');
			++cur;
		}
		return sign ? ret : -ret;
	}
} sc;



// 
inline int readInt() {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while(true) {
		if(ch == '-') break;
		if(ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if(ch == '-') minus = true; else result = ch-'0';
	while(true) {
		ch = getchar();
		if(ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if(minus)
		return -result;
	else
		return result;
}