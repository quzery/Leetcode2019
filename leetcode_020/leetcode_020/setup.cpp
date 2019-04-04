#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		map<char, char> m{ {'(', ')'}, {'[', ']'}, {'{', '}'} };
		string str;
		if (s == "") return true;
		str.push_back(s[0]);
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == m[str[str.size() - 1]])
				str.pop_back();
			else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				str.push_back(s[i]);
			else
				return false;
		}
		if (str == "") return true;
		else return false;
	}
};

int main() {
	Solution so;
	string aa = "{[]}";
	cout << so.isValid(aa) << endl;
}