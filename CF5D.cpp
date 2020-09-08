#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double a, v, l, d, w, t;
int main() {
	cin >> a >> v >> l >> d >> w;
	if (w >= v) {
		if (((v*v) / (2 * a) <= l)) {
			t = v / (2 * a) + l / v;
		}
		else {
			t = sqrt(2 * l / a);
		}
	}
	else {
		if (((w*w) / (2 * a)) <= d) {
			if (((2 * v*v - w * w) / (2 * a)) <= d) {
				t += (v - w) / a + d / v + (w*w) / (2 * a*v);
			}
			else {
				t += (sqrt(2 * w*w + 4 * a*d) - w) / a;
			}
			if (((v*v - w * w) / (2 * a)) <= (l - d)) {
				t += (v - w) / a + (l - d) / v + (w*w - v * v) / (2 * a*v);
			}
			else {
				t += (sqrt(2 * a*(l - d) + w * w) - w) / a;
			}
		}
		else {
			t += sqrt(2 * d / a);
			w = sqrt(2 * a*d);
			if (((v*v - w * w) / (2 * a)) <= (l - d)) {
				t += (v - w) / a + (l - d) / v + (w*w - v * v) / (2 * a*v);
			}
			else {
				t += (sqrt(2 * a*(l - d) + w * w) - w) / a;
			}
		}
	}
	cout << fixed << setprecision(12) << t;
	return 0;
}
