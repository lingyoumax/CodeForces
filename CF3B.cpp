//方法一
#include<iostream>
#include<algorithm>
using namespace std;
int num1 = 0;
int num2 = 0;
int n, v;
int ans = 0;
int flag1 = 0;
int flag2 = 0;
int sum1[100005], sum2[100005];
struct arr {
	int id, key;
	bool friend operator <(arr x, arr y) {
		return x.key > y.key;
	}
}arr1[100005], arr2[100005];
inline int read() {
	char ch = getchar();
	int f = 1, x = 0;
	while (ch<'0' || ch>'9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0'&&ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return f * x;
}
int main() {
	n = read();
	v = read();
	for (int i = 1;i <= n;i++) {
		int t = read();
		int p = read();
		if (t == 1) {
			arr1[++num1].id = i;
			arr1[num1].key = p;
		}
		else {
			arr2[++num2].id = i;
			arr2[num2].key = p;
		}
	}
	sort(arr1 + 1, arr1 + 1 + num1);
	sort(arr2 + 1, arr2 + 1 + num2);
	int len1 = min(num1, v);
	int len2 = min(num2, v / 2);
	for (int i = 1;i <= len1;i++) {
		sum1[i] = sum1[i - 1] + arr1[i].key;
	}
	for (int i = 1;i <= len2;i++) {
		sum2[i] = sum2[i - 1] + arr2[i].key;
	}
	flag1 = 0;
	flag2 = v / 2;
	for (int j = len2;j >= 0;j--) {
		int a = sum1[min(v - 2 * j, num1)] + sum2[j];
		if (a > ans) {
			ans = a;
			flag1 = min(v - 2 * j, num1);
			flag2 = j;
		}
	}
	cout << ans << endl;
	for (int i = 1;i <= flag1;i++) {
		cout << arr1[i].id << " ";
	}
	for (int i = 1;i <= flag2;i++) {
		cout << arr2[i].id << " ";
	}
	return 0;
}
//方法二
#include<iostream>
#include<algorithm>
using namespace std;
int num1 = 0;
int num2 = 0;
int n, v;
int ans = 0;
int flag1 = 0;
int flag2 = 0;
struct arr {
    int id, key;
    bool friend operator <(arr x, arr y) {
        return x.key > y.key;
    }
    arr() = default;
}arr1[100005], arr2[100005];
int read() {
    char ch = getchar();
    int f = 1, x = 0;
    while (ch<'0' || ch>'9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0'&&ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f * x;
}
int main() {
    cin >> n >> v;
    for (int i = 1;i <= n;i++) {
        int t = read();
        int p = read();
        if (t == 1) {
            arr1[++num1].id = i;
            arr1[num1].key = p;
        }
        else {
            arr2[++num2].id = i;
            arr2[num2].key = p;
        }
    }
    sort(arr1 + 1, arr1 + 1 + num1);
    sort(arr2 + 1, arr2 + 1 + num2);
    while (v && (flag1 < num1) && (flag2 < num2)) {
        if (v == 1) {
            ans += arr1[++flag1].key;
            v--;
        }
        else {
            if (arr1[flag1 + 1].key>= arr2[flag2 + 1].key) {
                v--;
                ans += arr1[++flag1].key;
            }
            else {
                if ((num1 - flag1) == 1) {
                    ans += arr2[++flag2].key;
                    v -= 2;
                }
                else {
                    int t = arr1[flag1 + 1].key + arr1[flag1 + 2].key;
                    if (t > arr2[flag2 + 1].key) {
                        ans += t;
                        flag1 += 2;
                        v -= 2;
                    }
                    else {
                        ans += arr2[++flag2].key;
                        v -= 2;
                    }
                }
            }
        }
    }
    if (v && (flag1 < num1)) {
        int t = min(flag1 + v, num1);
        for (int i = flag1 + 1;i <= t;i++) {
            ans += arr1[i].key;
        }
        flag1 = t;
    }
    else {
        if ((v >= 2) && (flag2 < num2)) {
            int t = min(flag2 + v / 2, num2);
            for (int i = flag2 + 1; i <= t;i++) {
                ans += arr2[i].key;
            }
            flag2 = t;
        }
    }
    while ((flag1 >= 2) && (flag2 < num2) && ((arr1[flag1].key + arr1[flag1 - 1].key) < arr2[flag2 + 1].key)) {
        ans -= arr1[flag1].key + arr1[flag1 - 1].key;
        ans += arr2[++flag2].key;
        flag1 -= 2;
    }
    cout << ans << endl;
    for (int i = 1;i <= flag1;i++) {
        cout << arr1[i].id << " ";
    }
    for (int i = 1;i <= flag2;i++) {
        cout << arr2[i].id << " ";
    }
    return 0;
}
