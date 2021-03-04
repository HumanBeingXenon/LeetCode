#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height);

int main() {
	vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	cout << maxArea(height) << endl;
	return 0;
}

int maxArea(vector<int>& height) {
	int left = 0, right = height.size() - 1, maxArea = 0;
	while(left < right) {
		maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
		if(height[left] < height[right]) left++;
		else right--;
	}
	return maxArea;
}
