#include <iostream>

using namespace std;

string countAndSay(int n);

int main() {
	cout << countAndSay(5) << endl;
	return 0;
}

string countAndSay(int n) {
	if(n == 1) return "1";
	else if(n == 2) return "11";
	else if(n == 3) return "21";
	string s = "21";
	int k;
	for(int i = 3; i < n; i++) {
		string t = "";
		for(int j = 0; j < s.length(); j = k){
			k = j;
			while(s[k] == s[j] && k < s.length()) k++;
			t += to_string(k-j);
			t += s[j];
		}
		s = t;
		//cout << s << endl;
	}
	return s;
}
