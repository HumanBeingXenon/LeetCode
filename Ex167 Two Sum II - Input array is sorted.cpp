#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);
int binarySearch(vector<int>& nums, int left, int target);

int main() {
	vector<int> nums = {3, 3};
	int target = 6;
	vector<int> result(2);
	result = twoSum(nums, target);
	cout << result[0] << " " << result[1] << endl;
	return 0;
}

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result(2);
	for(int i = 0; i < nums.size(); i++) {
		//cout << i << " " << nums[i] << endl;
		int com = binarySearch(nums, i + 1, target - nums[i]);

		if(com != -1) {
			result[0] = i + 1;
			result[1] = com + 1;
			//cout << result[0] << " " << result[1] << endl;
			break;
		}
	}
	return result;
}

int binarySearch(vector<int>& nums, int leftbound, int target) {
	int left = leftbound, right = nums.size() - 1;
	while(left <= right) {
		int mid = left + (right - left) / 2;
		if(nums[mid] == target) return mid;
		if(nums[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}
