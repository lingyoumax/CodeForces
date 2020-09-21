#include<iostream>
using namespace std;
int num, time_a, time_b, time[100001], num_a, num_b;
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
int main(){
	num = read();
	for (int i = 0;i < num;i++) {
		time[i] = read();
	}
	while ((num_a + num_b) < num) {
		if (time_a <= time_b) {
			time_a += time[num_a++];
		}
		else {
			time_b += time[num - 1 - (num_b++)];
		}
	}
	cout << num_a << " " << num_b;
	return 0;
}
