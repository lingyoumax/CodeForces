#include<iostream>
#include<set>
using namespace std;
int n, m;
char c, s[105][105];
set<char> se;
int main()
{
	cin >> n >> m >> c;
	for (int i = 0;i < n;i++) {
		cin >> s[i];
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (s[i][j] == c) {
				if (s[i][j + 1] != c && s[i][j + 1] != '.'&&j + 1 < m) {
					se.insert(s[i][j + 1]);
				}
				if (s[i + 1][j] != c && s[i + 1][j] != '.'&&i + 1 < n) {
					se.insert(s[i + 1][j]);
				}
				if (s[i][j - 1] != c && s[i][j - 1] != '.'&&j - 1 >= 0) {
					se.insert(s[i][j - 1]);
				}
				if (s[i - 1][j] != c && s[i - 1][j] != '.'&&i - 1 >= 0) {
					se.insert(s[i - 1][j]);
				}
			}
		}
	}
	cout << se.size() << endl;
	return 0;
}
