#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, int> pLi;
typedef long long LL;
#define F first
#define S second

const LL INF = 0x3f3f3f3f3f3f3f3f;
int inq[100100] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, r, f, s, t;
    cin >> c >> r >> f >> s >> t;

    vector<pii> g[100100];

    int u, v, w;
    for (int i = 0; i < r; i ++) {
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
        g[c + u].push_back(pii(c + v, w));
        g[c + v].push_back(pii(c + u, w));
    }

	for (int i = 0; i < f; i ++) {
        cin >> u >> v;
        g[u].push_back(pii(c + v, 0));
    }
    
    LL d[100100];
    memset(d, INF, sizeof(d));
    d[s] = 0; 
    
	priority_queue<pLi, vector<pLi>, greater<pLi>> q;
    q.push(pLi(0, s));
	inq[s] = 1;

    int cur; LL dist;
    while (q.size()) {
        cur = q.top().S; dist = q.top().F; q.pop(); inq[cur] = 0;
		//if (dist > d[cur]) continue;
        for (int i = 0; i < g[cur].size(); i ++) {
            pii nxt = g[cur][i];
            if(d[nxt.F] > d[cur] + nxt.S){
                d[nxt.F] = d[cur] + nxt.S;
				if(!inq[nxt.F]) {
					q.push(pLi(d[nxt.F], nxt.F));
					inq[nxt.F] = 1;
				}
			}
        }
    }


	cout << min(d[t], d[c + t]) << endl;

}
