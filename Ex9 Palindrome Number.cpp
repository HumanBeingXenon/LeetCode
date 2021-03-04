#include <iostream>

using namespace std;

bool isPalindrome(int);

int main(){
	cout << isPalindrome(2147483647) << endl;
	return 0;
}

bool isPalindrome(int x) {
	if(x < 0) return false;
	int ori = x, rev = 0;
	while(x){
		rev = rev * 10 + x % 10;
		x /= 10;
		cout << rev << endl;
	}
	return ori == rev;
}
