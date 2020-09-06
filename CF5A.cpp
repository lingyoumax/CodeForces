#include<iostream>
#include<string>
using namespace std;
string str;
int num, ans;
int main() {
	while (getline(cin, str)) {
		if (str[0] == '+') {
			num++;
		}
		else {
			if (str[0] == '-') {
				num--;
			}
			else {
				int z = str.find(':');
				ans += num * (str.size() - z - 1);
			}
		}
	}
	cout << ans;
	return 0;
}
