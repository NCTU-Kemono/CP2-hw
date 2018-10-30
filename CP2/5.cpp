#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long LL;

int n, X;

int x[21][21];
LL dp[2000000];

LL solve(int a, int state) {

	if (dp[state] != -1) return dp[state];

	LL sum = 0;	
	for (int i = 0; i < n; i ++) {
		if (x[a - 1][i]) continue;
		if (state & (1 << i)) {
			sum += solve(a - 1, state ^ (1 << i));
		}
	}
	return dp[state] = sum;
}	

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T --) {
		cin >> n >> X;
		memset(x, 0, sizeof(x));
		memset(dp, -1, sizeof(dp));

		int a, b;
		for (int i = 0; i < X; i ++) {
			cin >> a >> b; a--; b--;
			x[a][b] = 1;
		}
		
		dp[0] = 1;
		cout << solve(n, (1 << n) - 1) << '\n';

	}

}
