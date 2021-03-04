#include <iostream>

using namespace std;

void make_next(string, int[]);
int strStr(string, string);

int main() {
	string haystack = "aaaaa", needle = "bba";
	cout << strStr(haystack, needle) << endl;
	return 0;
}

void make_next(string p, int next[]) {
	int n = p.length();
	next[0] = -1;
	int k = -1, ptrP = 0;
	while(ptrP < n - 1) {
		if(k == -1 || p[k] == p[ptrP]) {
			k++;
			ptrP++;
			next[ptrP] = k;
		} else {
			k = next[k];
		}
	}
}

int strStr(string haystack, string needle) {
	int slen = haystack.length(), plen = needle.length();
	
	if(plen == 0) return 0;
	
	//printf("%d %d\n", slen, plen);
	int next[plen] = {0};
	make_next(needle, next);
	int ptrS = 0, ptrP = 0;

	//for(int i = 0; i < plen; i++)
		//cout << next[i] << endl;

	while(ptrS < slen && ptrP < plen) {
		//printf("%d %d\n", ptrS, ptrP);
		//cout << haystack << endl;
		//for(int i = 0; i < ptrS - ptrP; i++) cout << " ";
		//cout << needle << endl;
		//cout << "----------" << endl;

		if(ptrP == -1 || haystack[ptrS] == needle[ptrP]) {
			ptrS++;
			ptrP++;
		} else {
			ptrP = next[ptrP];
		}
	}
	if(ptrP == plen)
		return ptrS - ptrP;
	else
		return -1;
}
