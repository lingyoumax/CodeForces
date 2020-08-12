#include<iostream>
#include<string>
#include<stack>
using namespace std;
int n;
void change1(string str) {
	int a1 = 0;
	int a2 = 0;
	int i = 1;
	char c = str[i];
	while (true) {
		int it = c - '0';
		a1 *= 10;
		a1 += it;
		c = str[++i];
		if ((c > '9') || (c < '0')) {
			break;
		}
	}
	i++;
	while (i < str.size()) {
		c = str[i++];
		a2 *= 10;
		int it = c - '0';
		a2 += it;
	}
	stack<char> mystack;
	while (a2) {
		int it = a2 % 26;
		a2 /= 26;
		char c;
		if (!it) {
			c = 'Z';
			a2--;
		}
		else {
			c = 'A' + it - 1;
		}
		mystack.push(c);
	}
	while (!mystack.empty()) {
		cout << mystack.top();
		mystack.pop();
	}
	cout << a1 << endl;
}
void change2(string str) {
	int i = 0;
	int a1 = 0;
	int a2 = 0;
	char c = str[i];
	while (true) {
		int it = c - 'A' + 1;
		a1 *= 26;
		a1 += it;
		c = str[++i];
		if ((c < 'A') || (c > 'Z')) {
			break;
		}
	}
	while (i < str.size()) {
		c = str[i++];
		int it = c - '0';
		a2 *= 10;
		a2 += it;
	}
	cout << 'R' << a2 << 'C' << a1 << endl;
}
void test() {
	string str;
	cin >> str;
	bool flag = 0;
	for (int i = 1;i < str.size();i++) {
		if ((str[i - 1] >= '0') && (str[i - 1] <= '9') && (str[i] >= 'A') && (str[i]) <= 'Z') {
			flag = 1;
		}
		else {
			continue;
		}
	}
	if (flag) {
		change1(str);
	}
	else {
		change2(str);
	}
}
int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		test();
	}
	return 0;
}
