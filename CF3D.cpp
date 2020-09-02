#include<iostream>
#include<string>
#include<algorithm>
# define ll long long
using namespace std;
struct arr {
	ll id;
	ll date;
	bool friend operator <(arr x, arr y) {
		return x.date < y.date;
	}
}tidai[50001];
inline ll read() {
	char ch = getchar();
	ll f = 1, x = 0;
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
	string str;
	cin >> str;
	ll snum = str.size(), num = 0, l, r, ans = 0, flag = 0;
	for (ll i = 0;i < snum;i++) {
		if (str[i] == '?') {
			str[i] = ')';
			tidai[++num].id = i;
			l = read();
			r = read();
			tidai[num].date = l - r;
			ans += r;
		}
	}
	sort(tidai + 1, tidai + 1 + num);
	for (ll i = 0;i < snum;i++) {
		if (str[i] == '(') {
			flag++;
		}
		else {
			flag--;
		}
		if (flag < 0) {
			bool f = true;
			for (ll j = 1;j <= num;j++) {
				if (tidai[j].id <= i) {
					str[tidai[j].id] = '(';
					ans += tidai[j].date;
					tidai[j].id = snum * 2;
					flag += 2;
					f = false;
					break;
				}
			}
			if (f) {
				cout << -1;
				return 0;
			}
		}
	}
	if (flag == 0) {
		cout << ans << endl;
		cout << str;
	}
	else {
		cout << -1;
	}
	return 0;
}
