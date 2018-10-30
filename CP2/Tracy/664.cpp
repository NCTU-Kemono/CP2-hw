#include <bits/stdc++.h>
using namespace std;
#define MAX 500005

int n, m;
int vis[MAX] = {0}, p[MAX] = {0}, in[MAX] = {0}, out[MAX] = {0}, s[MAX];

int tree[2000000] = {0};
vector<vector<int>> G;

int dfs(int cur) {
    static int cnt = 0;
    int si = 1;
    in[cur] = cnt++;
    for (int i = 0; i < G[cur].size(); i ++) {
        int nxt = G[cur][i];
        if (!vis[nxt]) {
            vis[nxt] = 1;
            p[nxt] = cur;
            si += dfs(nxt);
        }
    }
    out[cur] = cnt++;
    return s[cur] = si;
}

int queryST(int idx, int l, int r, int a, int b) {
    if (r <= a || l >= b) return 0;
    if (a <= l && r <= b) return tree[idx];

    int mid = (l + r) / 2;
    int L = queryST(idx * 2, l, mid, a, b);
    int R = queryST(idx * 2 + 1, mid, r, a, b);

    return L + R;
}

int updateST(int idx, int l, int r, int x, int value) {
    if (l > x || r < x + 1) return tree[idx];
    if (l + 1 == r && l == x) return tree[idx] = value;
    
    int mid = (l + r) / 2;
    int L = updateST(idx * 2, l, mid, x, value);
    int R = updateST(idx * 2 + 1, mid, r, x, value);

    return tree[idx] = L + R;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    G.resize(n + 1);

    int u, v;
    for (int i = 0; i < n - 1; i ++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vis[1] = 1;
    dfs(1);

    for (int i = 1; i <= n; i ++) {
        cout << i << ' ' << p[i] << ' ' << in[i] << ' ' << out[i] << ' ' << s[i] << '\n';
    }
    cin >> m;
    int move, tar;
    for (int i = 0; i < m; i ++) {
        cin >> move >> tar;
        cout << "move: " << move << ' ' << tar << '\n';
        if (move == 1) {
            int ans = 0;
            int find = tar;
            while (find) {
                if (queryST(1, 0, 2 * n, in[find], out[find]) == s[find]) {
                    ans = 1;
                    break;
                }
                find = p[find];
            }
            cout << "ans = " << ans << '\n';
            if (!ans) {
                int state = s[tar] - queryST(1, 0, 2 * n, in[tar], out[tar]);
                updateST(1, 0, 2 * n, in[tar], state);
                updateST(1, 0, 2 * n, out[tar], -state);
            }
        } else if (move == 2) {
            int find = tar, parent = tar;
            while (find) {
                if (queryST(1, 0, 2 * n, in[tar], out[tar]) == s[find])
                    parent = find;
                find = p[find];
            }
            while (tar) {
                if (tar == parent) break;
                int state = queryST(1, 0, 2 * n, in[tar], in[tar] + 1);
                updateST(1, 0, 2 * n, in[tar], state - 1);
                state = queryST(1, 0, 2 * n, out[tar], out[tar] + 1);
                updateST(1, 0, 2 * n, out[tar], state + 1);
                tar = p[tar];
            }
        } else if (move == 3) {
            int ans = 0;
            while (tar) {
                cout << "q: " << queryST(1, 0, 2 * n, in[tar], out[tar]) << ' ' << s[tar] << '\n';
                if (queryST(1, 0, 2 * n, in[tar], out[tar]) == s[tar]) {
                    ans = 1;
                    break;
                }
                tar = p[tar];
            }
            cout << ans << '\n';
        }
    }

}
