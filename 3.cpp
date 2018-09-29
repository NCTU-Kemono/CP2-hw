#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int T; cin >> T;
	double r;
	int n;
	double A;

	while (T --) {
		cin >> r >> n;
		r = r * r / 4 / M_PI;
		if (n == 3) {
			int a, b, c; cin >> a >> b >> c;
			double s = (a + b + c) / 2.0;
			A = sqrt(s * (s - a) * (s - b) * (s - c));
		} else if (n == 4) {
			int a, b, c, d; cin >> a >> b >> c >> d;
			double s = (a + b + c + d) / 2.0;
			A = sqrt((s - a) * (s - b) * (s - c) * (s - d));
		} else {
			int a; cin >> a;
			for (int i = 0; i < n; i ++) cin >> a;
			A = n * (a * a / 4.0) / tan(M_PI / n);
		}
		printf("%.8f\n", r - A);
	}
}

