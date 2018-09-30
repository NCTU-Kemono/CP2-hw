#include "bits/stdc++.h"
using namespace std;

int main(){
	int T, N, n;
	char c;
	cin >> T;
	while(T--){
		stack<pair<char, int> > st;
		queue<pair<char, int> > q;
		cin >> N;
		for(int i = 0; i < N; i++){
			cin >> c >> n;
			if(st.size() && c == st.top().first){
				n += st.top().second;
				st.pop();
			}
			if(n%3) st.push(make_pair(c, n%3));
			if(n/3) q.push(make_pair(c, n/3));
		}
		while(q.size()){
			c = q.front().first;
			n = q.front().second;
			q.pop();
			if(st.size() && c == st.top().first){
				n += st.top().second;
				st.pop();
			}
			if(n%3) st.push(make_pair(c, n%3));
			if(n/3) q.push(make_pair(c, n/3));
		}
		int cnt = 0;
		while(st.size()){
			cnt += st.top().second;
			st.pop();
		}
		cout << cnt << '\n';

		// cout << '\n' << "stack\n";
		// while(st.size()){
		// 	cout << st.top().first << " " << st.top().second << '\n';
		// 	st.pop();
		// }
		// cout << '\n' << "queue\n";
		// while(q.size()){
		// 	cout << q.front().first << " " << q.front().second << '\n';
		// 	q.pop();
		// }
	}
	return 0;
}