#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int targes) {
		sort(nums.begin(), nums.end());
		if (nums.size() < 3) return {};
		int closest = nums[0] + nums[1] + nums[2];
		for(int k = 0; k < nums.size() - 2; ++k){
			if (k > 0 && nums[k] == nums[k - 1]) continue;
			int i = k + 1, j = nums.size() - 1;
			while (i < j) {
				int three_sum = nums[i] + nums[j] + nums[k];
				if(abs(three_sum - targes) < abs(closest - targes))
					closest = three_sum;
				if (three_sum < targes) ++i;
				else if (three_sum > targes) --j;
				else return targes;
			}
		}
		return closest;
	}
};

int main() {
	Solution so;
	vector<int> aa{ -1, 2, 1, 4 };
	cout << so.threeSumClosest(aa, 1) << endl;
}