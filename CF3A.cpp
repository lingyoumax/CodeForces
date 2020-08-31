#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string t, s;
	cin >> t;
	cin >> s;
	int clum = t[0] - s[0];
	int row = t[1] - s[1];
	string c = "";
	string r = "";
	if (clum < 0) {
		c = "R";
	}
	else {
		c = "L";
	}
	if (row < 0) {
		r = "U";
	}
	else {
		r = "D";
	}
	clum = abs(clum);
	row = abs(row);
	cout << max(clum, row) << endl;
	int i = 0;
	while ((i < clum) || (i < row)) {
		if (i < clum) {
			cout << c;
		}
		if (i < row) {
			cout << r ;
		}
		cout << endl;
		i++;
	}
	return 0;
}
