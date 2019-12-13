#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	string s;
	char seq[10], chknum;
	int len, weight = 1, sum = 0;
	cin >> s;
	len = s.length();
	for (int i = 0; i < len - 2; ++i) {
		if (s[i] == '-') continue;
		sum += (s[i] - '0') * (weight++);
	}
	if (sum % 11 == 10) {
		chknum = 'X';
	}
	else {
		chknum = sum % 11 + '0';
	}
	if (chknum == s[len - 1]) cout << "Right" << endl;
	else {
		for (int i = 0; i < len - 1; ++i) {
			cout << s[i];
		}
		cout << chknum << endl;
	}
	return 0;
}
