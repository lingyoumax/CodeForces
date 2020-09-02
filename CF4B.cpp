#include<iostream>
using namespace std;
int t[30][2], d, s, mi, ma;
int main() {
	cin >> d >> s;
	for (int i = 0;i < d;i++) {
		cin >> t[i][0] >> t[i][1];
		mi += t[i][0];
		ma += t[i][1];
	}
	if ((mi > s) || (ma < s)) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		s -= mi;
		for (int i = 0;i < d;i++) {
			s -= t[i][1] - t[i][0];
			t[i][0] = t[i][1];
			if (s <= 0) {
				t[i][0] += s;
				break;
			}
		}
		for (int i = 0;i < d;i++) {
			cout << t[i][0] << " ";
		}
	}
	return 0;
}
