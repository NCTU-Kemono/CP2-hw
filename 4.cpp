#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int fac[1000]

int main() {
	
	int T; cin >> T;
	int a, b, M;

	for (int i = 0; i < 10003; i ++) {
		dp[i][i] = 1;
		dp[i][0] = 1;
	}

	while (T --) {
		cin >> a >> b >> M;
		cout << find(a % M, b % M) * find(a / M, b / M) << endl;
	}

}
