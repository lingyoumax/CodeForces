#include<iostream>
#include <string>
#include<algorithm>
using namespace std;
string arr[1001];
int maxn, num, len[1001];
bool flag = false;
int main() {
	while (getline(cin, arr[num])) {
		len[num] = arr[num].size();
		maxn = max(maxn, len[num++]);
	}
	string s1(maxn + 2, '*');
	cout << s1 << endl;
	for (int i = 0;i < num;i++) {
		cout << "*";
		int l = (maxn - len[i]) / 2, r = l;
		if ((maxn - len[i]) % 2) {
			l += flag;
			r += !flag;
			flag = !flag;
		}
		string s(l, ' ');
		cout << s;
		cout << arr[i];
		string t(r, ' ');
		cout << t;
		cout << "*" << endl;
	}
	string s2(maxn + 2, '*');
	cout << s2 ;
	return 0;
}
