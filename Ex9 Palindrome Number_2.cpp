#include <iostream>

using namespace std;

bool isPalindrome(int);

int main(){
	cout << isPalindrome(0) << endl;
	return 0;
}

bool isPalindrome(int x) {
	if(x < 0 || (x % 10 == 0 && x)) return false;
	int ori = x, rev = 0;
	while(x > rev){
		rev = rev * 10 + x % 10;
		x /= 10;
		printf("%-12d %12d\n", x, rev);
	}
	return x == rev || x == rev / 10;
}
