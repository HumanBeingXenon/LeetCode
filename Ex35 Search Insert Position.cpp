#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>&, int);
int searchInsert2(vector<int>&, int);

int main() {
	vector<int> nums = {1, 3, 5, 6};
	int target = 4;
	cout << searchInsert2(nums, target) << endl;
	return 0;
} 

int searchInsert(vector<int>& nums, int target) {
	for(int i = 0; i < nums.size(); i++)
		if(nums[i] >= target) 
			return i;
	
	return nums.size();
}

int searchInsert2(vector<int>& nums, int target) {
	int low = 0, high = nums.size() - 1, mid;
	while(low < high){
		mid = (low + high) / 2;
		if(nums[mid] == target) return mid;
		if(nums[mid] > target) high = mid - 1;
		else low = mid + 1;
	}
	return nums[low] < target ? low + 1 : low;
}