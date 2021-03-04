#include <iostream>
#include <vector>

using namespace std; 

int findLeft(vector<int>& nums, int target);
int findRight(vector<int>& nums, int target);
vector<int> searchRange(vector<int>& nums, int target);

int main() {
	vector<int> nums = {5, 5, 5, 5, 5, 5};
	int target = 5;
	vector<int> result = searchRange(nums, target);
	printf("[%d,%d]\n", result[0], result[1]);
	return 0;
}

int findLeft(vector<int>& nums, int target) {
	int low = 0, high = nums.size(), mid;
	while(low < high){
		mid = low + (high - low) / 2;
		if(nums[mid] > target || nums[mid] == target) high = mid;
		else low = mid + 1;
	}
	return low;
}

int findRight(vector<int>& nums, int target) {
	int low = 0, high = nums.size(), mid;
	while(low < high){
		mid = low + (high - low) / 2;
		if(nums[mid] > target) high = mid;
		else low = mid + 1;
	}
	return low;
} 

vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> result = {-1, -1};
	
	int left = findLeft(nums, target);
	int right = findRight(nums, target) - 1;
	
	if(left == nums.size() || nums[left] != target) {
		return result;
	}
	
	result[0] = left;
	result[1] = right;
	
	return result;
}
