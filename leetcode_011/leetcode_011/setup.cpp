#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b) {
	if (a > b)return a;
	else return b;
}

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

class Solution {
public:
	int maxArea(vector<int>& height) {
		size_t size = height.size();
		int maxnum = 0;
		//vector<vector<int>> map(size -1);
		for(size_t i=0;i<size-1;i++)
			for (size_t j = 0; j < size - i -1; j++) {
				int tmp = (j + 1 )*min(height[i], height[i+j+1]);
					//map[i].push_back(tmp);
				maxnum = max(tmp, maxnum);
			}
		return maxnum;
	}
};

int main() {
	vector<int> aa{ 1,8,6,2,5,4,8,3,7 };
	Solution so;
	cout << so.maxArea(aa) << endl;
}