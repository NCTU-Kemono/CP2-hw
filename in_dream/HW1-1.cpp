#include <bits/stdc++.h>
using namespace std;
 
string S, s;
 
int solve(int L, int R, int l, int r) {
 
	if (R - L == 1) {
		if (S[L] == s[l]) return 1;
		else return 0;
	}
 
//	for (int i = 0; i <= R - L; i ++) {
//		if (i == R - L) return 1;
//		if (S[L + i] != s[l + i]) break;
//	}
 
	if ((R - L) % 2) {
		for (int i = 0; i <= R - L; i ++) {
			if (i == R - L) return 1;
			if (S[L + i] != s[l + i]) return 0;
		}	
	}
 
	int M = (L + R) / 2;
	int m = (l + r) / 2;


	return solve(M, R, m, r) && solve(L, M, l, m)
		|| solve(M, R, l, m) && solve(L, M, m, r);
}
 
int main(){

	int T; cin >> T;

	while (T --){
		cin >> s >> S;
		cout << (solve(0, s.size(), 0, s.size())? "YES\n" : "NO\n");
	}
}
