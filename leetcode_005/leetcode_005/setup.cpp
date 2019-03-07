#include<iostream>
#include<string>

using namespace std;

string check(const string &, size_t);
bool is_palindromic(const string&, size_t, size_t);

class Solution {
public:
	string longestPalindrome(string s) {
		auto size = s.size();
		string max;
		size_t wind;
		for (size_t i = 0; ( wind = size - i) > 1; i++) {
			if ((max = check(s, wind)) != "") return max;
		}
		max.push_back(s[0]);
		return max;
	}
};

string check(const string & s, size_t wind) {
	string s0;
	//bool flag = true;
	for (size_t j = 0; wind + j <= s.size(); j++) {
		if (is_palindromic(s, wind, j)) {
			for (size_t k = 0; k < wind; k++)
				s0.push_back(s[j + k]);
			return s0;
		}
	}
	return s0;
}

bool is_palindromic(const string& s, size_t wind, size_t be) {
	for (size_t i = 0; i < wind / 2; i++) {
		if (s[be + i] != s[be + wind - 1 - i])  return false;
	}
	return true;
}

int main() {
	string s("cbbd");
	//string s1("babad");
	Solution so;
	cout << so.longestPalindrome(s) << endl;
	//cout << so.longestPalindrome(s1) << endl;
}