#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double x1, y11, r1, x2, y2, r2, x3, y3, r3;
int main() {
	cin >> x1 >> y11 >> r1;
	cin >> x2 >> y2 >> r2;
	cin >> x3 >> y3 >> r3;
	if ((r1 != r2) && (r2 != r3) && (r1 != r3)) {
		double x12, y12, x23, y23, r12, r23;
		x12 = (x1*r2*r2 - x2 * r1*r1) / (r2*r2 - r1 * r1);
		y12 = (y11*r2*r2 - y2 * r1*r1) / (r2*r2 - r1 * r1);
		x23 = (x3*r2*r2 - x2 * r3*r3) / (r2*r2 - r3 * r3);
		y23 = (y3*r2*r2 - y2 * r3*r3) / (r2*r2 - r3 * r3);
		r12 = sqrt(x12*x12 + y12 * y12 - (x1*x1*r2*r2 - x2 * x2*r1*r1) / (r2*r2 - r1 * r1) - (y11*y11*r2*r2 - y2 * y2*r1*r1) / (r2*r2 - r1 * r1));
		r23 = sqrt(x23*x23 + y23 * y23 - (x3*x3*r2*r2 - x2 * x2*r3*r3) / (r2*r2 - r3 * r3) - (y3*y3*r2*r2 - y2 * y2*r3*r3) / (r2*r2 - r3 * r3));
		if (sqrt((x12 - x23)*(x12 - x23) + (y12 - y23)*(y12 - y23)) == (r12 + r23)) {
			double x = (x12*r23 + x23 * r12) / (r12 + r23);
			double y = (y12*r23 + y23 * r12) / (r12 + r23);
			if (x == 0) {
				x = 0;
			}
			if (y == 0) {
				y = 0;
			}
			cout << fixed << setprecision(5) << x << " " << fixed << setprecision(5) << y << endl;
		}
		else {
			if (sqrt((x12 - x23)*(x12 - x23) + (y12 - y23)*(y12 - y23)) < (r12 + r23)) {
				if (sqrt((x12 - x23)*(x12 - x23) + (y12 - y23)*(y12 - y23)) > abs(r12 - r23)) {
					double a1 = 2 * (x12 - x23);
					double b1 = 2 * (y12 - y23);
					double c1 = x23 * x23 + y23 * y23 - r23 * r23 - x12 * x12 - y12 * y12 + r12 * r12;
					double a2 = y12 - y23;
					double b2 = x23 - x12;
					double c2 = x12 * y23 - x23 * y12;
					double len = sqrt(r12*r12 - ((a1*x12 + b1 * y12 + c1)*(a1*x12 + b1 * y12 + c1) / (a1*a1 + b1 * b1)));
					double xx = (b2*c1 - b1 * c2) / (a2*b1 - a1 * b2);
					double yy = (a1*c2 - a2 * c1) / (a2*b1 - a1 * b2);
					double x01 = xx + len * b1 / sqrt(a1*a1 + b1 * b1);
					double y01 = yy - len * a1 / sqrt(a1*a1 + b1 * b1);
					double x02 = xx - len * b1 / sqrt(a1*a1 + b1 * b1);
					double y02 = yy + len * a1 / sqrt(a1*a1 + b1 * b1);
					double len1 = (x01 - x1)*(x01 - x1) + (y01 - y11)*(y01 - y11);
					double len2 = (x02 - x1)*(x02 - x1) + (y02 - y11)*(y02 - y11);
					if (len1 < len2) {
						if (x01 == 0) {
							x01 = 0;
						}
						if (y01 == 0) {
							y01 = 0;
						}
						cout << fixed << setprecision(5) << x01 << " " << fixed << setprecision(5) << y01 << endl;
					}
					else {
						if (x02 == 0) {
							x02 = 0;
						}
						if (y02 == 0) {
							y02 = 0;
						}
						cout << fixed << setprecision(5) << x02 << " " << fixed << setprecision(5) << y02 << endl;
					}
				}
			}
		}
	}
	else {
		if (r2 == r3) {
			double t = x1;
			x1 = x3;
			x3 = t;
			t = y11;
			y11 = y3;
			y3 = t;
			t = r1;
			r1 = r3;
			r3 = t;
		}
		else {
			if (r1 == r3) {
				double t = x2;
				x2 = x3;
				x3 = t;
				t = y2;
				y2 = y3;
				y3 = t;
				t = r2;
				r2 = r3;
				r3 = t;
			}
		}
		if ((r1 == r2) && (r2 == r3)) {
			double a1 = 2 * (x2 - x1);
			double b1 = 2 * (y2 - y11);
			double c1 = x1 * x1 - x2 * x2 + y11 * y11 - y2 * y2;
			double a2 = 2 * (x2 - x3);
			double b2 = 2 * (y2 - y3);
			double c2 = x3 * x3 - x2 * x2 + y3 * y3 - y2 * y2;
			if ((a1*b2) != (a2 * b1)) {
				double x = (b2*c1 - b1 * c2) / (a2*b1 - a1 * b2);
				double y = (a1*c2 - a2 * c1) / (a2*b1 - a1 * b2);
				if (x == 0) {
					x = 0;
				}
				if (y == 0) {
					y = 0;
				}
				cout << fixed << setprecision(5) << x << " " << fixed << setprecision(5) << y << endl;
			}
		}
		else {
			double a = 2 * (x2 - x1);
			double b = 2 * (y2 - y11);
			double c = x1 * x1 - x2 * x2 + y11 * y11 - y2 * y2;
			double x0 = (x3*r2*r2 - x2 * r3*r3) / (r2*r2 - r3 * r3);
			double y0 = (y3*r2*r2 - y2 * r3*r3) / (r2*r2 - r3 * r3);
			double r = sqrt(x0*x0 + y0 * y0 - (x3*x3*r2*r2 - x2 * x2*r3*r3) / (r2*r2 - r3 * r3) - (y3*y3*r2*r2 - y2 * y2*r3*r3) / (r2*r2 - r3 * r3));
			double len = abs(a*x0 + b * y0 + c) / sqrt(a*a + b * b);
			if (len == r) {
				double x = (b*b*x0 - a * b*y0 - a * c) / (a*a + b * b);
				double y = (a*a*y0 - a * b*x0 - b * c) / (a*a + b * b);
				if (x == 0) {
					x = 0;
				}
				if (y == 0) {
					y = 0;
				}
				cout << fixed << setprecision(5) << x << " " << fixed << setprecision(5) << y << endl;
			}
			else {
				if (len < r) {
					double xx = (b*b*x0 - a * b*y0 - a * c) / (a*a + b * b);
					double yy = (a*a*y0 - a * b*x0 - b * c) / (a*a + b * b);
					double xa = xx + b * sqrt(r*r - len * len) / sqrt(a*a + b * b);
					double ya = yy - a * sqrt(r*r - len * len) / sqrt(a*a + b * b);
					double xb = xx - b * sqrt(r*r - len * len) / sqrt(a*a + b * b);
					double yb = yy + a * sqrt(r*r - len * len) / sqrt(a*a + b * b);
					double len1 = (xa - x3)*(xa - x3) + (ya - y3)*(ya - y3);
					double len2 = (xb - x3)*(xb - x3) + (yb - y3)*(yb - y3);
					if (len1 <= len2) {
						if (xa == 0) {
							xa = 0;
						}
						if (ya == 0) {
							ya = 0;
						}
						cout << fixed << setprecision(5) << xa << " " << fixed << setprecision(5) << ya << endl;
					}
					else {
						if (xb == 0) {
							xb = 0;
						}
						if (yb == 0) {
							yb = 0;
						}
						cout << fixed << setprecision(5) << xb << " " << fixed << setprecision(5) << yb << endl;
					}
				}
			}
		}
	}
	return 0;
}
