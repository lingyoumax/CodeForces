#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str;
int num[1000001], len, maxn, cot = 1, mystack[1000001], n;
int main() {
	cin >> str;
	len = str. size();
	str = " " + str;
	for (int i = 1;i <= len;i++) {
		if (str[i] == '(') {
			mystack[++n] = i;
		}
		else {
			if (n) {
				num[i] = i - mystack[n] + 1 + num[mystack[n] - 1];
				n--;
				if (num[i] > maxn) {
					maxn = num[i];
					cot = 1;
				}
				else {
					if (num[i] == maxn) {
						cot++;
					}
				}
			}
		}
	}
	cout << maxn << " " << cot;
	return 0;
}
