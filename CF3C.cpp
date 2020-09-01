#include<iostream>
using namespace std;
int arr[3][3], num1, num2;
int win() {
	int flag1 = 0, flag2 = 0;
if ((arr[0][0] == 1) && (arr[0][1] == 1) && (arr[0][2] == 1)) {
	flag1 = 1;
}
if ((arr[0][0] == 2) && (arr[0][1] == 2) && (arr[0][2] == 2)) {
	flag2 = 2;
}
if ((arr[1][0] == 1) && (arr[1][1] == 1) && (arr[1][2] == 1)) {
	flag1 = 1;
}
if ((arr[1][0] == 2) && (arr[1][1] == 2) && (arr[1][2] == 2)) {
	flag2 = 2;
}
if ((arr[2][0] == 1) && (arr[2][1] == 1) && (arr[2][2] == 1)) {
	flag1 = 1;
}
if ((arr[2][0] == 2) && (arr[2][1] == 2) && (arr[2][2] == 2)) {
	flag2 = 2;
}
if ((arr[0][0] == 1) && (arr[1][0] == 1) && (arr[2][0] == 1)) {
	flag1 = 1;
}
if ((arr[0][0] == 2) && (arr[1][0] == 2) && (arr[2][0] == 2)) {
	flag2 = 2;
}
if ((arr[0][1] == 1) && (arr[1][1] == 1) && (arr[2][1] == 1)) {
	flag1 = 1;
}
if ((arr[0][1] == 2) && (arr[1][1] == 2) && (arr[2][1] == 2)) {
	flag2 = 2;
}
if ((arr[0][2] == 1) && (arr[1][2] == 1) && (arr[2][2] == 1)) {
	flag1 = 1;
}
if ((arr[0][2] == 2) && (arr[1][2] == 2) && (arr[2][2] == 2)) {
	flag2 = 2;
}
if ((arr[0][0] == 1) && (arr[1][1] == 1) && (arr[2][2] == 1)) {
	flag1 = 1;
}
if ((arr[0][0] == 2) && (arr[1][1] == 2) && (arr[2][2] == 2)) {
	flag2 = 2;
}
if ((arr[0][2] == 1) && (arr[1][1] == 1) && (arr[2][0] == 1)) {
	flag1 = 1;
}
if ((arr[0][2] == 2) && (arr[1][1] == 2) && (arr[2][0] == 2)) {
	flag2 = 2;
}
return (flag1 + flag2);
}
int main() {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			char c;
			cin >> c;
			if (c == 'X') {
				arr[i][j] = 1;
				num1++;
			}
			else {
				if (c == '0') {
					arr[i][j] = 2;
					num2++;
				}
			}
		}
	}
	int w = win();
	if (w == 3) {
		cout << "illegal" << endl;
	}
	else {
		if (w == 0) {
			if (((num1 - num2) > 1) || (num1 < num2)) {
				cout << "illegal" << endl;
			}
			else {
				if (num1 + num2 == 9) {
					cout << "draw" << endl;
				}
				else {
					if (num1 == num2) {
						cout << "first" << endl;
					}
					else {
						cout << "second" << endl;
					}
				}
			}
		}
		else {
			if (w == 1) {
				if (((num1 - num2) != 1)) {
					cout << "illegal" << endl;
				}
				else {
					cout << "the first player won" << endl;
				}
			}
			else {
				if ((num1 != num2)){
					cout << "illegal" << endl;
                }
				else {
					cout << "the second player won" << endl;
				}
			}
		}
	}
	return 0;
}
