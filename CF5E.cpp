#include<iostream>
#include<stack>
using namespace std;
int arrh[1000001], num, lef[1000001], rig[1000001], cnt[1000001], p, arr[1000001], maxn;
long long ans;
stack<int>l, r;
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
	num = read();
	for (int i = 0;i < num;i++) {
		arr[i] = read();
		if (arr[i] > maxn) {
			maxn = arr[i];
			p = i;
		}
	}
	for (int i = 0;i < num;i++) {
		arrh[i] = arr[(i + p) % num];
	}
	for (int i = 0;i < num;i++) {
		while ((!l.empty()) && (arrh[l.top()] < arrh[i])) {
			l.pop();
		}
		if (!l.empty()) {
			if ((i) != l.top()) {
				lef[i] = l.top() + 1;
				if (arrh[i] == arrh[l.top()]) {
					cnt[i] = cnt[l.top()] + 1;
					lef[i] = lef[lef[i] - 1];
				}
				l.push(i);
			}
		}
		else {
			l.push(i);
		}
	}
	for (int i = num;i >= 1;i--) {
		while ((!r.empty()) && (arrh[r.top()] <= arrh[i%num])) {
			r.pop();
		}
		if (!r.empty()) {
			if ((i%num) != r.top()) {
				rig[i%num] = r.top() + 1;
				r.push(i%num);
			}
		}
		else {
			r.push(i%num);
		}
	}
	for (int i = 0;i < num;i++) {
		if (lef[i] && rig[i] && (lef[i] != rig[i])) {
			ans += 2;
		}
		else {
			if (lef[i] || rig[i]) {
				ans += 1;
			}
		}
		ans += cnt[i];
	}
	cout << ans;
	return 0;
}
