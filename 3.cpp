#include <bits/stdc++.h>
using namespace std;

double e[15];

int main() {
	
	int T; cin >> T;
	double r;
	int n;
	double A;

	while (T --) {
		cin >> r >> n;
		r = r * r / 4 / M_PI;

		int max_e = 0;
		for (int i = 0; i < n; i ++) {
			cin >> e[i];
			if (e[i] > e[max_e]) max_e = i;
		}

		int N = 100;
	   	double L = e[max_e] / 2, R = 200;
		double M;
		double s, Ms;
		
		while (N --) {
			double sum = 0;
			M = (L + R) / 2;
			for (int i = 0; i < n; i ++) {
				if (i == max_e) continue;
				s = (e[i] / 2.0) / M;
				s = asin(s) * 2;
				sum += s;
			}
			Ms = (e[max_e] / 2.0) / M;
			Ms = asin(Ms) * 2;
			if (sum + Ms < M_PI * 2) R = M;
			else L = M;
		}

		double A = 0;
		for (int i = 0; i < n; i ++) {
			A += sqrt(L * L - e[i] * e[i] / 4) * e[i] / 2;
		}

		if (L > e[max_e] / 2) {
			printf("%.15f\n", r - A);
			continue;
		}

		N = 100;
	   	L = e[max_e] / 2, R = 200;

		while (N --) {
			double sum = 0;
			M = (L + R) / 2;
			for (int i = 0; i < n; i ++) {
				if (i == max_e) continue;
				s = (e[i] / 2.0) / M;
				s = asin(s) * 2;
				sum += s;
			}

			Ms = (e[max_e] / 2.0) / M;
			Ms = asin(Ms) * 2;
			if (sum < Ms) L = M;
			else R = M;
		}
		
		A = 0;
		for (int i = 0; i < n; i ++) {
			if (i == max_e) continue;
			A += sqrt(L * L - e[i] * e[i] / 4) * e[i] / 2;
		}
		A -= sqrt(L * L - e[max_e] * e[max_e] / 4) * e[max_e] / 2;
		printf("%.15f\n", r - A);
	}
}

