#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string, int>mymap;
int n;
int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		string name;
		cin >> name;
		if ((++mymap[name]) == 1) {
			cout << "OK" << endl;
		}
		else {
			cout << name << (mymap[name] - 1) << endl;
		}
	}
	return 0;
}
