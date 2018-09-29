#include <bits/stdc++.h>
using namespace std;

int f[205];

int main() {
	
	int T, n, a; cin >> T;

	while (T --) {
		memset(f, 0, sizeof(f));

		cin >> n;
		for (int i = 0; i < n; i ++) {
			cin >> a;
			f[a] ++;
		}

		int sum = 0, ans = 0;
		for (int i = 2; i < 204; i ++) {
			if (f[i]) sum ++;
			else {
				if (sum % 2) ans += (sum + 1) / 2;
				else ans += sum / 2;
				sum = 0;
			}
		}

		cout << ans << endl;
	}



}
