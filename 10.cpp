#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

vector<vector<int> > adj;
int color[1005];
int ans1, ans2;

void dfs(int x){
    for(int i = 0; i < adj[x].size(); i++){
        int y = adj[x][i];
        if(color[y] == INF){
            color[y] = 1 - color[x];
            if(color[y] == 1) ans1++;
            if(color[y] == 0) ans2++;
            dfs(y);
        }
        else if(color[y] == color[x]){
            ans1 = ans2 = -1;
            return;
        }
    }
}

int main(){
    int T, n, m, a, b;
    cin >> T;
    while(T--){
        cin >> n >> m;
        adj.clear();
        adj.resize(n+1);
        memset(color, INF, sizeof(color));
        ans1 = ans2 = 0;
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 1; i <= n; i++){
            if(color[i] == INF){
                color[i] = 1;
                ans1++;
                dfs(i);
                if(ans1 < 0) break;
            }
        }
        if(ans1 < 0) cout << -1 << '\n';
        else
            cout << max(ans1, ans2) << '\n';
    }
    return 0;
}
