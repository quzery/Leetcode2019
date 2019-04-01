#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

//class Solution {
//public:
//	vector<string> letterCombinations(string digits) {
//		vector<string> result;
//		map<char, string> letter_map;
//		string infra = "abc";
//		letter_map['2'] = infra;
//		letter_map['9'] = "wxyz";
//		for (char i = '3'; i >= '2' && i < '9'; ++i) {
//			for (int k = 0; k < 3; ++k)
//				infra[k] += 3;
//			letter_map[i] = infra;
//		}
//		size_t size = digits.size();
//		
//	}
//};
void printm(vector<string> & m) {
	for (size_t i = 0; i < m.size(); ++i) 
		cout << m[i] << endl;
	
}

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		unordered_map<char, string> table{
			{'0', " "}, {'1',"*"}, {'2', "abc"},
			{'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
			{'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
			{'9',"wxyz"} };
		vector<string> res;
		if (digits == "") return res;
		func(res, "", digits, table, 0);
		return res;
	}

	void func(vector<string> &res, string str, string &digits, unordered_map<char, string> &m, int k) {
		if (str.size() == digits.size()) {
			res.push_back(str);
			return;
		}
		string tmp = m[digits[k]];
		for (char w : tmp) {
			str += w;
			func(res, str, digits, m, k + 1);
			str.pop_back();
		}
		return;
	}
};


int main() {
	Solution so;
	string aa = "237";
	vector<string> m = so.letterCombinations(aa);
	printm(m);
}