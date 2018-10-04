#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

vector<vector<int> > adj;
int color[1005];
int ans1, ans2, ans, cnt;

void bfs(int x){
    color[x] = 1;
    ans1++;
    queue<int> q;
    q.push(x);
    while(q.size()){
        int y = q.front(); q.pop();
        for(int i = 0; i < adj[y].size(); i++){
            int j = adj[y][i];
            if(color[j] == INF){
                color[j] = 1 - color[y];
                if(color[j] == 1) ans1++;
                if(color[j] == 0) ans2++;
                q.push(j);
            }
            else if(color[j] == color[y]){
                ans1 = ans2 = -1;
                return;
            }

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
        ans1 = ans2 = ans = cnt = 0;
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 1; i <= n; i++){
            if(color[i] == INF){
                ans1 = ans2 = 0;
                bfs(i);
                if(ans1 < 0) break;
                if(ans1 > ans2) ans += ans1, cnt++;
                else if(ans2 > ans1) ans += ans2, cnt++;
                else ans += ans1; 
            }
        }
        if(ans1 < 0) cout << -1 << '\n';
        else{
            if(cnt % 2) ans -= (cnt-1)/2;
            else ans -= cnt/2;
            n -= ans + ans - 1;
            if(n%2) cout << ans + n/2 << '\n';
            else cout << ans + (n+1)/2 << '\n';
        }
    }
    return 0;
}
