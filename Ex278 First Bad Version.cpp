#include <iostream>
#define BAD 3

using namespace std;

bool isBadVersion(int version);
int firstBadVersion(int n);

int main() {
	cout << firstBadVersion(10) << endl;
	return 0;
} 

int firstBadVersion(int n) {
	int low = 0, high = n, mid;
	while(low < high) {
		mid = low + (high - low) / 2;
		if(isBadVersion(mid))
			if(!isBadVersion(mid-1))
				return mid;
			else
				high = mid - 1;
		else low = mid + 1;
	}
	return low;
}

bool isBadVersion(int v) {
	return v >= BAD;
}
