#include<iostream>
#include<string>
#include<map>

using namespace std;

//string addstring(string &s, string s0, int n) {
//	for (int i = 0; i < n; i++) {
//		s += s0;
//	}
//}

class Solution {
public:
	string intToRoman(int num) {
		map<int, string> ma;
		ma[1] = "I";
		ma[2] = "II";
		ma[3] = "III";
		ma[4] = "IV";
		ma[5] = "V";
		ma[6] = "VI";
		ma[7] = "VII";
		ma[8] = "VIII";
		ma[9] = "IX";
		ma[10] = "X";
		ma[20] = "XX";
		ma[30] = "XXX";
		ma[40] = "XL";
		ma[50] = "L";
		ma[60] = "LX";
		ma[70] = "LXX";
		ma[80] = "LXXX";
		ma[90] = "XC";
		ma[100] = "C";
		ma[200] = "CC";
		ma[300] = "CCC";
		ma[400] = "CD";
		ma[500] = "D";
		ma[600] = "DC";
		ma[700] = "DCC";
		ma[800] = "DCCC";
		ma[900] = "CM";
		ma[1000] = "M";
		ma[2000] = "MM";
		ma[3000] = "MMM";
		if (num < 1 || num > 3999) return "error";
		int q, b, s, g;
		string str;
	
		str += ma[num / 1000 * 1000];
		str += ma[num % 1000 / 100 * 100];
		str += ma[num % 100 / 10 * 10];
		str += ma[num % 10];
		return str;
	}
};

int main() {
	int test = 2342;
	Solution so;
	cout << so.intToRoman(test) << endl;
}