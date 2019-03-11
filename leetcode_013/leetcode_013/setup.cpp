#include<iostream>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		map<char, int> RTI;
		int sum = 0;
		RTI['I'] = 1;
		RTI['V'] = 5;
		RTI['X'] = 10;
		RTI['L'] = 50;
		RTI['C'] = 100;
		RTI['D'] = 500;
		RTI['M'] = 1000;
		for (size_t i = 0; i < s.size() - 1; i++) {
			if (RTI[s[i]] >= RTI[s[i + 1]]) sum += RTI[s[i]];
			else sum -= RTI[s[i]];
		}
		sum += RTI[s[s.size() - 1]];
		return sum;
	}
};

int main() {
	string s = "MCMXCIV";
	Solution so;
	cout << so.romanToInt(s) << endl;
}