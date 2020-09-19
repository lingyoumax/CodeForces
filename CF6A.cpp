#include<iostream>
#include<algorithm>
using namespace std;
int arr[4];
inline int read() {
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
	for (int i = 0;i < 4;i++) {
		arr[i] = read();
	}
	sort(arr, arr + 4);
	if ((arr[0] + arr[1] > arr[2]) || (arr[1] + arr[2] > arr[3])) {
		cout << "TRIANGLE";
	}
	else {
		if ((arr[0] + arr[1] == arr[2]) || (arr[1] + arr[2] == arr[3])) {
			cout << "SEGMENT";
		}
		else {
			cout << "IMPOSSIBLE";
		}
	}
	return 0;
}
