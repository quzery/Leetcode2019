#include<iostream>
#include<string>
#include<vector>

using namespace std;
//size_t max(const vector<size_t>);
bool compare(const string, char);

class Solution {
public:
	//Solution(string a):s(a){}
	int lengthOfLongestSubstring(string s) {
		size_t size = s.size();
		string str;
		size_t max = 0, tem;
		for (size_t i = 0; i < size - max; i++) {
			for (size_t j = 0; compare(str, s[i+j]) && j < size-i; j++) {
				//str[j] = s[i + j];
				str.push_back(s[i + j]);
			}
			if ((tem = str.size()) > max) max = tem;
			str.erase(0);
		}
		return max;
	}

//private:
//	string s;
};

bool compare(const string s, char a) {
	bool flag = true;
	for (auto b : s) {
		if (b == a) { 
			flag = false; 
			break;
		}
	}
	return flag;
}


int main() {
	//string a1 = "ssdfsgdrgdgsdfgsd";
	string a2 = "pwwkew";
	Solution so;
	//cout << so.lengthOfLongestSubstring(a1) << endl;
	cout << so.lengthOfLongestSubstring(a2) << endl;
	return 0;
}