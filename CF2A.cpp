#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
map<string, int> mymap, mymap2;
string name[1000];
int sc[1000];
int m = 0;
string ans;
int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> name[i] >> sc[i];
		mymap[name[i]] += sc[i];
	}
	for (int i = 0;i < n;i++) {
		m = max(m, mymap[name[i]]);
	}
	for (int i = 0;i < n;i++) {
		mymap2[name[i]] += sc[i];
		if ((mymap[name[i]] == m) && (mymap2[name[i]] >= m)) {
			ans = name[i];
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
