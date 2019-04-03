#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int>>  fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		if (nums.size() < 4) return {};
		sort(nums.begin(), nums.end());
		//if (target < nums[0]) return {};
		for (int l = 0; l < nums.size() - 3; ++l) {
			if (l > 0 && nums[l] == nums[l - 1]) continue;
			for (int k = l + 1; k < nums.size() - 2; ++k) {
				if (k > l + 1 && nums[k] == nums[k - 1]) continue;
				int tmp = target - nums[l] - nums[k];
				int i = k + 1, j = nums.size() - 1;
				while (i < j) {
					if (nums[i] + nums[j] == tmp) {
							res.push_back(vector<int>{nums[l], nums[k], nums[i], nums[j]});
							while (i < j && nums[++i] == nums[i - 1]) {}
							while (i < j && nums[--j] == nums[j + 1]) {}
						}
					
					else if (nums[i] + nums[j] < tmp) {
						while (i < j && nums[++i] == nums[i - 1]) {}
					}
					else
						while (i < j && nums[--j] == nums[j + 1]) {}
				}
			}
		}
		return res;
	}
};

void printm(vector<vector<int>> const& m) {
	for (size_t i = 0; i < m.size(); ++i) {
		for (size_t j = 0; j < m[i].size(); ++j)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

int main() {
	Solution so;
	vector<int> aa{ 1, 0, -1, 0, -2, 2 }, bb{ -1,0,1,2,-1,-4 };
	int target = 0, tar_00 = -1;
	//vector<vector<int>> m = so.fourSum(aa, target);
	//printm(so.fourSum(aa, target));
	printm(so.fourSum(bb, tar_00));
}