#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<LL, int> > v;

int main() {
	
	int T;
	cin >> T;

	while (T --) {
		int n;
		cin >> n;
		v.clear(); v.resize(2 * n);

		for (int i = 0; i < 2 * n; i += 2) {
			cin >> v[i].first;
			v[i].second = -1;
			cin >> v[i + 1].first;
			v[i + 1].second = 1;
		}

		sort(v.begin(), v.end());
		
		int ans = 0, cnt = 0;
		for (int i = 0; i < v.size(); i ++) {
			cnt -= v[i].second;
			ans = max(ans, cnt);
		}

		cout << ans << endl;
	}
}
