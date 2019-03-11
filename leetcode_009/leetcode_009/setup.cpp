#include<iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		long int sum = 0, tem = x;
		while (x) {
			sum = sum * 10 + x % 10;
			x /= 10;
		}
		if (sum == tem) return true;
		else return false;
	}
};

int main() {
	int a = 34543;
	Solution so;
	if (so.isPalindrome(a))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}