#include <iostream>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string);

int main(){
	string s = "pwwkeww";
	cout << lengthOfLongestSubstring(s) << endl;
	return 0;
} 

int lengthOfLongestSubstring(string s) {
    int n = s.length(), ans = 0;
    map<char, int> m;
	for(int i = 0, j = 0; j < n; j++){
		
		if(m.find(s[j]) != m.end()) i = max(m[s[j]], i);
		
		ans = max(ans, j - i + 1);
		m[s[j]] = j + 1;
		cout << i << "," << j << " " << s.substr(i, j - i + 1) << endl;
	}
	return ans;
}
