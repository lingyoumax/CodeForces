#include<iostream>
using namespace std;
int main() {
	long long m, n, a;
	cin >> m >> n >> a;
	long long ans  = m / a;
	if (m%a != 0) {
		ans++;
	}
	long long an = n / a;
	if (n%a != 0) {
		an++;
	}
	cout << (ans*an) << endl;
	return 0;
}
