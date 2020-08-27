#include<iostream>
#include<string>
using namespace std;
long arr[1010][2];
string way[1010][2];
int read() {
	char ch = getchar();
	int f = 1, x = 0;
	while (ch<'0' || ch>'9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0'&&ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return f * x;
}
int main() {
	int n;
	int best;
	n = read();
	int flag = 0;
	int i;
	long t;
	t = read();
	if (!t) {
		arr[0][0] = 1;
		arr[0][1] = 1;
		best = 0;
		flag = 1;
	}
	else {
		while (t && (t % 2 == 0)) {
			arr[0][0]++;
			t /= 2;
		}
		while (t && (t % 5 == 0)) {
			arr[0][1]++;
			t /= 5;
		}
	}
	for (i = 1;i < n;i++) {
		t = read();
		way[i][0] = way[i - 1][0] + "R";
		way[i][1] = way[i][0];
		if (!t) {
			arr[i][0] = 1;
			arr[i][1] = 1;
			best = i;
			flag = 1;
		}
		else {
			arr[i][0] = arr[i - 1][0];
			arr[i][1] = arr[i - 1][1];
			while (t && (t % 2 == 0)) {
				arr[i][0]++;
				t /= 2;
			}
			while (t && (t % 5 == 0)) {
				arr[i][1]++;
				t /= 5;
			}
		}
	}
	for (int j = 1;j < n;j++) {
		way[0][0] = way[0][0] + "D";
		way[0][1] = way[0][0];
		t = read();
		if (!t) {
			arr[0][0] = 1;
			arr[0][1] = 1;
			best = 0;
			flag = 1;
		}
		else {
			while (t && (t % 2 == 0)) {
				arr[0][0]++;
				t /= 2;
			}
			while (t && (t % 5 == 0)) {
				arr[0][1]++;
				t /= 5;
			}
		}
		for (i = 1;i < n;i++) {
			t = read();
			if (!t) {
				arr[i][0] = 1;
				arr[i][1] = 1;
				way[i][0] = way[i][0] + "D";
				way[i][1] = way[i][0];
				best = i;
				flag = 1;
			}
			else {
				if (arr[i - 1][0] < arr[i][0]) {
					arr[i][0] = arr[i - 1][0];
					way[i][0] = way[i - 1][0] + "R";
				}
				else {
					way[i][0] = way[i][0] + "D";
				}
				if (arr[i - 1][1] < arr[i][1]) {
					arr[i][1] = arr[i - 1][1];
					way[i][1] = way[i - 1][1] + "R";
				}
				else {
					way[i][1] = way[i][1] + "D";
				}
				while (t && (t % 2 == 0)) {
					arr[i][0]++;
					t /= 2;
				}
				while (t && (t % 5 == 0)) {
					arr[i][1]++;
					t /= 5;
				}
			}
		}
	}
	if ((flag == 1) && (flag < arr[n - 1][0]) && (flag < arr[n - 1][1])) {
		cout << 1 << endl;
		best++;
		for (i = 1;i < best;i++) {
			cout << "R";
		}
		for (i = 1;i < n;i++) {
			cout << "D";
		}
		for (i = best;i < n;i++) {
			cout << "R";
		}
		cout << endl;
	}
	else {
		if (arr[n - 1][0] < arr[n - 1][1]) {
			cout << arr[n - 1][0] << endl;
			cout << way[n - 1][0] << endl;
		}
		else {
			cout << arr[n - 1][1] << endl;
			cout << way[n - 1][1] << endl;
		}
	}
	return 0;
}
