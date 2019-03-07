#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(const int a, const int b) {
	return a < b;
}

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		for (size_t i = 0; i < nums2.size(); i++) {
			nums1.push_back(nums2[i]);
		} 
		sort(nums1.begin(), nums1.end(), [](int &a, int &b) {return a < b; });
		//sort(nums1.begin(), nums1.end(), compare);
		auto size1 = nums1.size();
		if (size1 % 2)
			return nums1[size1 / 2];
		else
			return (double(nums1[size1 / 2 - 1]) + double(nums1[size1 / 2])) / 2;
	}
};


int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	vector<int> b;
	b.push_back(3);
	b.push_back(4);
	Solution so;
	cout << so.findMedianSortedArrays(a, b);
	return 0;
}