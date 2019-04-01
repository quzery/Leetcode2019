#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
bool is_exsit(vector<vector<int>> &, vector<int> &);
bool is_equal(vector<int>&, vector<int>&);
void print(vector<vector<int>>&);
void sort(vector<int>&);
void swapt(int&, int&);


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		size_t size = nums.size();
		vector<int> sum_sun(3);
		vector<vector<int>> sum;
		if (size < 3) return sum;
		/*for(size_t i=0;i<size-2;i++)
			for(size_t j=i+1;j<size-1;j++)
				for(size_t k=j+1;k<size;k++)
					if (nums[i] + nums[j] + nums[k] == 0) {
						sum_sun[0] = nums[i];
						sum_sun[1] = nums[j];
						sum_sun[2] = nums[k];
						sort(sum_sun);
						if (!is_exsit(sum, sum_sun)) 
							sum.push_back(sum_sun);
					}
		return sum;

		sort(nums.begin(), nums.end(), [](int a, int b) {return a < b; });
		for(size_t i=0;nums[i]<=0 && i<size-2;i++)
				for (size_t j = i + 1; j < size - 1; j++)
					for (size_t k = size - 1; nums[k] >= 0 && k > j; k--)
						if (nums[i] + nums[j] + nums[k] == 0) {
							sum_sun[0] = nums[i];
							sum_sun[1] = nums[j];
							sum_sun[2] = nums[k];
							if (!is_exsit(sum, sum_sun))
								sum.push_back(sum_sun);
						}
		return sum;
	}
};


bool is_exsit(vector<vector<int>> &sum, vector<int> &sum_sun) {
	for (size_t i = 0; i < sum.size(); i++) {
		if (is_equal(sum[i], sum_sun))
			return true;
	}
	return false;
}

bool is_equal(vector<int>& a, vector<int>& b) {
	for (size_t i = 0; i < 3; i++)
		if (a[i] != b[i]) return false;
	return true;
}

void sort(vector<int>& a) {
	if (a[0] > a[1]) swapt(a[0], a[1]);
	if (a[0] > a[2]) swapt(a[0], a[2]);
	if (a[1] > a[2]) swapt(a[1], a[2]);
}

void swapt(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
*/
void print(vector<vector<int>>& sum) {
	for (size_t i = 0; i < sum.size(); i++) {
		for (size_t j = 0; j < sum[i].size(); j++)
			cout << sum[i][j] << " ";
		cout << endl;
	}
}


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
		for (int k = 0; k < nums.size(); ++k) {
			if (nums[k] > 0) break;
			if (k > 0 && nums[k] == nums[k - 1]) continue;
			int target = 0 - nums[k];
			int i = k + 1, j = nums.size() - 1;
			while (i < j) {
				if (nums[i] + nums[j] == target) {
					res.push_back({ nums[k], nums[i], nums[j] });
					while (i < j && nums[i] == nums[i + 1]) ++i;
					while (i < j && nums[j] == nums[j - 1]) --j;
					++i; --j;
				}
				else if (nums[i] + nums[j] < target) ++i;
				else --j;
			}
		}
		return res;
	}
};

int main() {
	vector<int> aa{ -1, 0, 1, 2, -1, -4 };
	Solution so;
	auto b = so.threeSum(aa);
	print(b);
}