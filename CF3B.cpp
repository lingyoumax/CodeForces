#include<iostream>
#include<algorithm>
using namespace std;
int num1 = 0;
int num2 = 0;
int n, v;
int ans = 0;
int flag1 = 0;
int flag2 = 0;
int sum1[100005], sum2[100005];
struct arr {
	int id, key;
	bool friend operator <(arr x, arr y) {
		return x.key > y.key;
	}
}arr1[100005], arr2[100005];
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
	n = read();
	v = read();
	for (int i = 1;i <= n;i++) {
		int t = read();
		int p = read();
		if (t == 1) {
			arr1[++num1].id = i;
			arr1[num1].key = p;
		}
		else {
			arr2[++num2].id = i;
			arr2[num2].key = p;
		}
	}
	sort(arr1 + 1, arr1 + 1 + num1);
	sort(arr2 + 1, arr2 + 1 + num2);
	int len1 = min(num1, v);
	int len2 = min(num2, v / 2);
	for (int i = 1;i <= len1;i++) {
		sum1[i] = sum1[i - 1] + arr1[i].key;
	}
	for (int i = 1;i <= len2;i++) {
		sum2[i] = sum2[i - 1] + arr2[i].key;
	}
	flag1 = 0;
	flag2 = v / 2;
	for (int j = len2;j >= 0;j--) {
		int a = sum1[min(v - 2 * j, num1)] + sum2[j];
		if (a > ans) {
			ans = a;
			flag1 = min(v - 2 * j, num1);
			flag2 = j;
		}
	}
	cout << ans << endl;
	for (int i = 1;i <= flag1;i++) {
		cout << arr1[i].id << " ";
	}
	for (int i = 1;i <= flag2;i++) {
		cout << arr2[i].id << " ";
	}
	return 0;
}
