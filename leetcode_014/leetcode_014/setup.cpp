#include<iostream>
#include<string>
#include<vector>

using namespace std;

size_t min(vector<string>& strs) { 
	if (strs.size() == 0) return 0;
	size_t t = strs[0].size();
	for (size_t i = 1; i < strs.size(); i++)
		if (strs[i].size() < t) t = strs[i].size();
	return t;
}

bool equal_n(vector<string>& strs, int n) {
	char s = strs[0][n];
	for (size_t i = 1; i < strs.size(); i++)
		if (s != strs[i][n]) return false;
	return true;
}


class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		//size_t size = strs.size();
		string st = "";
		for (size_t i = 0; i < min(strs) && equal_n(strs, i); i++)
			st += strs[0][i];
		return st;
	}
};

int main() {
	vector<string> strs;
	Solution so;
	cout << so.longestCommonPrefix(strs) << endl;
}