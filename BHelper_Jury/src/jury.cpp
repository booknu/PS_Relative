// Jury 컴파일 옵션
// "cpp": "cd $dirWithoutTrailingSlash && g++ $fileName -g -o ./$fileNameWithoutExt && ./$fileNameWithoutExt.exe \"D:\\____Development\\Projects\\Cpp\\BHelper_Jury\\test\\TestContest\\A\" 3 3",

#include <iostream>
#include <unistd.h>
#include <ctime>
#include <fstream>
#include <cassert>
#include <vector>
using namespace std;

// 나중에 JSON으로 만드는게 나을듯
const int RESULT_SIZE = 6;
enum RESULT { AC, WA, TLE, RTE, MLE, OTE };
const string RESULT_MSG[RESULT_SIZE] = {
		"AC",
		"Wrong Answer",
		"Time Limit Exceed",
		"Runtime Error",
		"Memory Limit Exceed",
		"Output Type Error"
};
const string EXE_FILE_DIR = "\\exe";
const string EXE_FILE_NAME = "submit";
const string IO_FILE_NAME[2] = { "\\IO\\in_", "\\IO\\out_" };
const string IO_FILE_TYPE = ".txt";

bool fileExists(const char* str) {
	return access(str, F_OK) != -1;
}

// type 0 = in, 1 = out
string getIOFileName(const string& dir, int tc, int type) {
	return dir + IO_FILE_NAME[type] + to_string(tc) + IO_FILE_TYPE;
}

void verdict(RESULT type, clock_t execTime, long long code = 0) {
	cerr << "  Verdict: " << RESULT_MSG[type];
	switch(type) {
		case AC: cerr << " !!"; break;
		case MLE: cerr << " (" << (code/0.000001) << "MB" << ")"; break;
	}
	cerr << " --> " << 0.001*execTime << " s.";
}

void trim(string& str) {
	str.erase(str.find_last_not_of(" \n\r\t")+1);
}

// prLimit 만큼의 문자만을 출력한다.
class FileIO {
	size_t prLimit, bufsz;
	char *buf;
public: 
	FileIO(size_t _prLimit, size_t _bufsz = 1) : prLimit(_prLimit) {
		bufsz = min(_bufsz, prLimit);
		buf = new char[bufsz+1];
	}
	~FileIO() {
		delete[] buf;
	}
	// ignore ifs's CR, LF, blank
	void ignoreCRLF(ifstream& ifs) {
		while(ifs.peek() == 10 || ifs.peek() == 13 || ifs.peek() == ' ') ifs.get(); 
	}
	// print ifs no more than 
	void print(ifstream& ifs) {
		size_t tot = 0, cur = 0;
		ignoreCRLF(ifs);
		while(tot < prLimit && ifs.peek() != -1) {
			tot += (cur = ifs.read(buf, bufsz).gcount());
			buf[cur] = 0; // mark string's end
			cerr << buf;
		}
		if(ifs.peek() != -1) cerr << "...\n";
	}
	void print(const string& filePath) {
		assert(fileExists(filePath.c_str()));
		ifstream ifs(filePath);
		print(ifs);
	}
};

// [1] = problem path, [2] = print IAO/AO/O/verdict?, [3] = live output mode, [4] = cut print length, 
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	// check arguments
	if(argc != 5) cerr << "ERROR: malformed arguments for Jury !\n", exit(-1);
	if(!fileExists(argv[1])) cerr << "ERROR: problem directory not exists !\n", exit(-2);
	long long printOption = stoll(string(argv[2]), 0, 0), liveOutput = stoll(string(argv[3]), 0, 0);
	FileIO filePrinter(stoll(string(argv[4]), 0, 0));
	string probDir(argv[1]);
	int tc = 1;
	vector<int> res[RESULT_SIZE];
	clock_t totalTime = 0;
	while(fileExists(getIOFileName(probDir, tc, 0).c_str())) {
		string inp = getIOFileName(probDir, tc, 0), outp = getIOFileName(probDir, tc, 1);
		cerr << "================ Test #" << tc << " ================\n";
		if(printOption <= 0) {
			cerr << "[ Input ] :\n";
			filePrinter.print(inp);
			cerr << "\n\n";
		}
		if(printOption <= 1) {
			cerr << "[ Expected Output ] :\n";
			filePrinter.print(outp);
			cerr << "\n\n";
		}
		if(printOption <= 2) {
			cerr << "[ Execution Result ] : \n";
		}
		clock_t start, end;
		RESULT resType = AC;
		long long errorCode = 0;
		// TEST Code
		if(printOption <= 2){
			// console output
			start = clock();
			if(liveOutput) {
				// live output : print all output
				errorCode = system((probDir + EXE_FILE_DIR + "\\" + EXE_FILE_NAME + " < " + inp).c_str());
			} else {
				// cutoff output : for big output
				errorCode = system((probDir + EXE_FILE_DIR + "\\" + EXE_FILE_NAME + " < " + inp + " 1> console_out.txt 2>&1").c_str());
				string outFilePath("console_out.txt");
				filePrinter.print(outFilePath);
			}
			end = clock();
		}
		
		if(!errorCode) {
			// ignore cerr output
			start = clock();
			system((probDir + EXE_FILE_DIR + "\\" + EXE_FILE_NAME + " < " + inp + " 1> res_" + to_string(tc) + ".txt 2>&3").c_str());
			end = clock();
		}
		// RTE
		if(errorCode) {
			resType = RTE;
		} else {
			// Check answer
			ifstream ans(outp), tout("res_" + to_string(tc) + ".txt");
			while(1) {
				filePrinter.ignoreCRLF(ans), filePrinter.ignoreCRLF(tout);
				if(ans.eof() || tout.eof()) {
					// OTE
					if(!ans.eof() || !tout.eof()) resType = OTE;
					break; 
				}
				string ansStr, toutStr;
				getline(ans, ansStr), getline(tout, toutStr);
				trim(ansStr), trim(toutStr);
				// WA
				if(ansStr != toutStr) {
					resType = WA;
					break;
				}
			}
		}
		// print verdict
		totalTime += end-start;
		res[resType].push_back(tc);
		cerr << '\n';
		verdict(resType, end-start, errorCode);
		++tc;
		cerr << "\n\n";
	}
	cerr << "-----------------------------------------\n";
	cerr << "=========================================\n";
	--tc;
	cerr << "Test results: " << tc << " tests / " << 0.001*totalTime << " s\n";
	if(res[AC].size() == tc) cerr << "ALL TEST PASSED !" << "\n\n\n";
	else {
		for(int i = 0; i < RESULT_SIZE; ++i) {
			if(res[i].size()) {
				cerr << res[i].size() << ' ' << RESULT_MSG[i] << ": ";
				for(int j = 0; j < res[i].size(); ++j) {
					cerr << '#' << res[i][j];
					if(j+1 < res[i].size()) cerr << ", ";
				}
				cerr << '\n';
			}
		}
	}
	cerr << "\n\n";
}