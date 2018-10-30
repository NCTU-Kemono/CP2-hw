#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int T; cin >> T;
	string s;
	map<char, int> m;
	m['L'] = 0; m['O'] = 1; m['V'] = 2; m['E'] = 3;
	
	int cnt[4];

	while (T --) {
		memset(cnt, 0, sizeof(cnt));
		cin >> s;
		for (int i = 0; i < s.size(); i ++) {
			if (m[s[i]] == 0 || m[s[i]] > 0 && cnt[m[s[i]] - 1] > cnt[m[s[i]]])
				cnt[m[s[i]]] ++;
		}
		cout << cnt[3] << endl;
	}

}
