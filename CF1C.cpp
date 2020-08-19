#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const double pi = acos(-1.0);
double A_x, A_y, B_x, B_y, C_x, C_y;
double yf(double a, double b) {
	if (b < 0.001) {
		return a;
	}
	return yf(b, fmod(a, b));
}
int main() {
	cin >> A_x >> A_y >> B_x >> B_y >> C_x >> C_y;
	double a = sqrt((B_x - C_x)*(B_x - C_x) + (B_y - C_y)*(B_y - C_y));
	double b = sqrt((A_x - C_x)*(A_x - C_x) + (A_y - C_y)*(A_y - C_y));
	double c = sqrt((A_x - B_x)*(A_x - B_x) + (A_y - B_y)*(A_y - B_y));
	double cosA = (c*c + b * b - a * a) / (2 * b*c);
	double r = (a*b*c) / sqrt((a + b + c)*(a + b - c)*(a + c - b)*(b + c - a));
	double A = acos(1 - (a * a) / (2 * r*r));
	double B = acos(1 - (b * b) / (2 * r*r));
	double C = 2 * pi - A - B;
	double t = yf(yf(A, B), C);
	double S = (pi*r*r*sin(t)) / t;
	cout << std::fixed << std::setprecision(6) << S << endl;
	return 0;
}
