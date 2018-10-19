#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

vector<vector<int> > adj;
int color[1005];
int ans1, ans2;
vector<int> b1, b2;
int dp[1005][1005];

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
        b1.clear(); b1.push_back(0);
        b2.clear(); b2.push_back(0);
        memset(color, INF, sizeof(color));
        
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 1; i <= n; i++){
            if(color[i] == INF){
                ans1 = ans2 = 0;
                bfs(i);
                b1.push_back(ans1);
                b2.push_back(ans2);
                if(ans1 < 0) break;
            }
        }

        if(ans1 < 0){
            cout << -1 << '\n';
            continue;
        }

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i < b1.size(); i++){
            for(int j = 1000; j >= b1[i]; j --){
                if(dp[i-1][j-b1[i]]) dp[i][j] = 1;
            }
            for(int j = 1000; j >= b2[i]; j --){
                if(dp[i-1][j-b2[i]]) dp[i][j] = 1;
            }
        }

        int i = (n + 1) / 2;
        while(!dp[b1.size()-1][i]) i ++;

        cout << i << '\n';
    }
    return 0;
}
