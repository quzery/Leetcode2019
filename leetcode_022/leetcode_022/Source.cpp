#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		string str = "";
		func(res, n, str);
		return res;
	}

	void func(vector<string> &res, int n, string &str) {
		if (str.size() == 2 * n) {
			res.push_back(str);
			return;
		}
		string tmp = "()";
		for (char w : tmp) {
			str += w;
			if (count(str) <= n && count(str) * 2 >= str.size()) 
				func(res, n, str);
			str.pop_back();
		}
		return;
	}

	int count(const string &s) {
		int con = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') ++con;
		}
		return con;
	}
};


void printm(const vector<string> &m) {
	for (int i = 0; i < m.size(); ++i)
		cout << m[i] << endl;
}


int main() {
	Solution so;
	int n = 3;
	printm(so.generateParenthesis(n));
}