#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;

const LL INF = 0x3f3f3f3f3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, r, f, s, t;
    cin >> c >> r >> f >> s >> t;

    vector<pii> g[c];

    int u, v, w;
    for (int i = 0; i < r; i ++) {
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
    }

    for (int i = 0; i < f; i ++) {
        cin >> u >> v;
        g[u].push_back(pii(v, 0));
        g[v].push_back(pii(u, 0));
    }

    LL d[c][2];
    memset(d, INF, sizeof(d));
    d[s][0] = 0;
    d[s][1] = 0; 

    queue<int> q;
    q.push(s);

    int cur;
    while (q.size()) {
        cur = q.front(); q.pop();
        for (int i = 0; i < g[cur].size(); i ++) {
            pii nxt = g[cur][i];
            bool change = 0;
            if (nxt.second != 0) {
                if(d[nxt.first][1] > d[cur][1] + nxt.second){
                    d[nxt.first][1] = d[cur][1] + nxt.second;
                    change = 1;
                }
                if(d[nxt.first][0] > d[cur][0] + nxt.second){
                    d[nxt.first][0] = d[cur][0] + nxt.second;
                    change = 1; 
                }
            } else
                if(d[nxt.first][1] > d[cur][0] + nxt.second){
                    d[nxt.first][1] = d[cur][0] + nxt.second;
                    change = 1;
                }
            if(change) q.push(nxt.first);
        }
    }
    
    cout << min(d[t][0], d[t][1]) << endl;

}
