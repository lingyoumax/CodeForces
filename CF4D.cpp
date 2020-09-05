#include<iostream>
#include<algorithm>
using namespace std;
struct node {
	int w = 0, h = 0, id = 0;
	node* last = nullptr;
	bool friend operator <(node a, node b) {
		return ((a.w < b.w) || ((a.w == b.w) && (a.h > b.h)));
	}
}arr[5001];
node * line[5001];
int n, num = 0, W, H, len = 0;
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
int lower(node a) {
	int l = 1, r = len;
	while (r - l > 1) {
		int b = line[(l + r) / 2]->h;
		if (b >= a.h) {
			r = (l + r) / 2;
		}
		else {
			l = (l + r) / 2;
		}
	}
	if (line[l]->h >= a.h) {
		return l;
	}
	else {
		return r;
	}
}
int main() {
	n = read();
	W = read();
	H = read();
	for (int i = 1;i <= n;i++) {
		int a = read(), b = read();
		if ((a > W) && (b > H)) {
			arr[++num].id = i;
			arr[num].w = a;
			arr[num].h = b;
		}
	}
	sort(arr + 1, arr + 1 + num);
	for (int i = 1;i <= num;i++) {
		int a = arr[i].w;
		int b = arr[i].h;
		if ((line[len] != nullptr) && (a == (line[len]->w))) {
			if (b == line[len]->h) {
				continue;
			}
			else {
				int p = lower(arr[i]);
				arr[i].last = line[p - 1];
				line[p] = &(arr[i]);
			}
		}
		else {
			if ((line[len] == nullptr) || (b > line[len]->h)) {
				arr[i].last = line[len];
				line[++len] = &(arr[i]);
			}
			else {
				if (b == line[len]->h) {
					continue;
				}
				else {
					int p = lower(arr[i]);
					arr[i].last = line[p - 1];
					line[p] = &(arr[i]);

				}
			}
		}
	}
	cout << len << endl;
	if (len) {
		for (int i = len;i > 1;i--) {
			line[i - 1] = line[i]->last;
		}
		for (int i = 1;i <= len;i++) {
			cout << line[i]->id << " ";
		}
	}
	return 0;
}
