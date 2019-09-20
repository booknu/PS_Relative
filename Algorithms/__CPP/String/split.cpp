#ifndef ONLINE_JUDGE
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;

// ........................macro.......................... //
// [i, n)
#define FOR(i, f, n) for(int (i) = (f); (i) < (int)(n); ++(i))
// [i, n]
#define RFOR(i, f, n) for(int (i) = (f); (i) >= (int)(n); --(i))
#define pb push_back
#define emb emplace_back
#define fi first
#define se second
#define ENDL '\n'
#define ALL(A) A.begin(), A.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef long long i64;
typedef unsigned long long ui64;
inline i64 GCD(i64 a, i64 b) { while(b != 0) { int t = a; a = b; b = t % b; } return a; }
inline i64 LCM(i64 a, i64 b) { if(a == 0 || b == 0) return GCD(a, b); return a*b / GCD(a, b); }
inline i64 CEIL(i64 n, i64 d) { return n / d + n % d != 0; }
inline i64 ROUND(i64 n, i64 d) { return n / d + (i64)((n % d)*2 >= d); }
inline i64 POW(i64 a, i64 n) {
	if(n < 0) return 0;
	i64 ret = 1;
	while(n) { if(n % 2) ret *= a; a = a * a; n /= 2; }
	return ret;
}

// ....................................................... //

// regex 사용한 split
vector<string> split(string& target, string regex) {
	vector<string> ret;
	std::regex rgx(regex);
	std::sregex_token_iterator iter(target.begin(),
		target.end(),
		rgx,
		-1);
	std::sregex_token_iterator end;
	for( ; iter != end; ++iter) ret.pb(*iter);
	return ret;
}

// 공백 단위로 split
vector<string> space_split(string& s) {
	istringstream iss(s);
	vector<string> ret(istream_iterator<string>{iss}, istream_iterator<string>());
	return ret;
}

// 애초에 입력 받을 때 split 해서 받기
void input_split() {
	vector<string> strings;
	istringstream f("denmark;sweden;india;us");
	string s;
	while(getline(f, s, ';')) {
		cout << s << endl;
		strings.push_back(s);
	}
}

vector<string> split(const string& s, char seperator) {
	vector<string> output;
	string::size_type prev_pos = 0, pos = 0;
	while((pos = s.find(seperator, pos)) != string::npos) {
		string substring(s.substr(prev_pos, pos-prev_pos));
		output.push_back(substring);
		prev_pos = ++pos;
	}
	output.push_back(s.substr(prev_pos, pos-prev_pos)); // Last word
	return output;
}

// #include <boost/tokenizer.hpp>
// #include <boost/foreach.hpp>
// typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
// std::string str("denmark;sweden;india;us");
// boost::char_separator<char> sep(";");
// tokenizer tokens(str, sep);
// BOOST_FOREACH(std::string const& token, tokens) {
//     std::cout << "<" << *tok_iter << "> " << "\n";
// }

void easy() {
	string s = "Somewhere down the road";
	istringstream iss(s);
	do {
		string subs;
		iss >> subs;
		cout << "Substring: " << subs << endl;
	} while(iss);
}

/// 좋음!!!!!: https://stackoverflow.com/questions/16749069/c-split-string-by-regex
void usingRegex() {
	string s("123123");
	std::regex rgx("(==|!=)");
	std::sregex_token_iterator iter(
		s.begin(), s.end(),
		rgx,
		-1);
	std::sregex_token_iterator endpos;
	for(; iter != endpos; ++iter) {
		cout << *iter << ENDL;
	}
}