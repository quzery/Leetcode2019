#include<iostream>
#include<math.h>

#define max pow(2,31)

using namespace std;

class Solution {
public:
	int reverse(int x) {
		
		long int sum = 0;
		while (x) {
			sum = 10 * sum + x % 10;
			x /= 10;
		}
		if (sum > max-1 || sum < -max) return 0;
		return sum;
	}
};

int main() {
	int a;
	Solution so;
	cin >> a;
	cout << so.reverse(a) << endl;
}