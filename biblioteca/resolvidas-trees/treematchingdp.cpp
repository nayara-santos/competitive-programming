// Maximo num de pares em grafo bipartido
// Forma do CSES:
// array<int, 2> dfs(int node, int parent) {
//     array<int, 2> dp = {0, 0};
//     for (int child: g[node]) {
//         if (child == parent) continue;
//         auto child_dp = dfs(child, node);
//         dp[1] = max({dp[0] + child_dp[0] + 1, dp[1] + child_dp[1],
//                      dp[1] + child_dp[0]});
//         dp[0] += max(child_dp[0], child_dp[1]);
//     }
//     return dp;
// }
void dfs(int v, int p){
    for (auto to: g[v]){
        if (to != p){
            dfs(to, v);
            dp[v][0] += max(dp[to][0], dp[to][1]);
        }
    }
    for (auto to: g[v]){
        if (to != p){
            dp[v][1] = max(dp[v][1], dp[to][0] + 1 + dp[v][0] - max(dp[to][0], dp[to][1]));
        }
    }
}
int main(){_
    int n, a, b; cin >> n;
    for (int i = 0; i < n - 1; i++){
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << endl;
    return 0;
}