#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<float, int> pfi;
typedef pair<int, int> pii;

struct edge {
	int to;
	int p, q;
	float f;
	edge(int _to, int _p, int _q) : to(_to), p(_p), q(_q) {
		int gcd = __gcd(p, q);
		p /= gcd; q /= gcd;
		f = (float)p / q;
	}
};
vector<vector<edge>> g;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int T; cin >> T;
	int n, s, t, e;

	while (T --) {
		cin >> n >> s >> t >> e;
		g.clear(); g.resize(n);

		int u, v, p, q;
		for (int i = 0; i < e; i ++) {
			cin >> u >> v >> p >> q;
			g[u].push_back(edge(v, p, q));
		}

		pii dist[n];
		for(int i = 0; i < n; i++)
			dist[i].F = 0, dist[i].S = 1;
		dist[s].F = 1;
		
		//priority_queue<pfi, vector<pfi>, less<pfi> > pq;
		//pq.push(pfi(1, s));
		
		queue<int> qu;
		qu.push(s);

		while(qu.size()){
			int cur = qu.front(); qu.pop();
			for(int i = 0; i < g[cur].size(); i ++) {
				edge nxt = g[cur][i]; //to, p, q, f
				if (dist[nxt.to].F / (float)dist[nxt.to].S < dist[cur].F / (float)dist[cur].S * nxt.f){
					dist[nxt.to].F = dist[cur].F * nxt.p;
					dist[nxt.to].S = dist[cur].S * nxt.q;
					int gcd = __gcd(dist[nxt.to].F, dist[nxt.to].S);
					dist[nxt.to].F /= gcd;
					dist[nxt.to].S /= gcd;
					qu.push(nxt.to);
				}
			}
		}

		if (!dist[t].F)
			cout << -1 << '\n';
		else
			cout << dist[t].F << ' ' << dist[t].S << '\n';
	}

}
