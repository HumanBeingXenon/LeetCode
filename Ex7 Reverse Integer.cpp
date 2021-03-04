#include <iostream>

using namespace std;

int reverse(int);

int main(){
	//cout << reverse(-2147483412) << endl;
	cout<<reverse(123)<<endl;
	//cout << INT_MAX << endl;
	return 0;
}

int reverse(int x) {
	int rev = 0, prev = 0;
	while(x){
		int rem = x % 10;
		x /= 10;
		//if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && rem > 7)) return 0;
        //if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && rem < -8)) return 0;
		rev = rev * 10 + rem;
		//cout << rev << endl;
	}
	return rev;
}
