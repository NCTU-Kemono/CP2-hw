#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL fac[10005];
LL inv[10005];
const int MOD = 1e9 + 7;

LL extgcd(LL a, LL b, LL &x, LL &y) {
	if (!b) return x= 1, y = 0, a;
	LL res = extgcd(b, a % b, y, x);
	return y -= a / b * x, res;
}

LL modInv(LL a, LL m) {
	LL x, y, d = extgcd(a, m, x, y);
	return d == 1 ? (x + m) % m : -1;
}

LL C(int a, int b) {
	if (a < b) return 0;
	if (a == b || b == 0) return 1;
	return fac[a] * inv[a - b] % MOD * inv[b] % MOD;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T; cin >> T;
	int a, b, M;

	fac[0] = 1; inv[0] = 1;
	fac[1] = 1; inv[1] = 1;

	for (int i = 2; i < 10002; i ++) {
		fac[i] = (fac[i - 1] * i) % MOD;
		inv[i] = modInv(fac[i], MOD);
	}

	while (T --) {
		cin >> a >> b >> M;
		
		LL sum = 1;
		while (1) {	
			sum = (sum * C(a % M, b % M)) % MOD;
			if (!a && !b) break;
			a /= M; b /= M;
		}
		cout << sum << '\n';
	}

}
