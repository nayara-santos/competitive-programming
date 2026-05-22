// determinar para cada no a distancia max p outro no
int bfs(int v, ll * dist){
    queue<int> q;
    q.push(v); dist[v] = 0;
    int at;
    while (!q.empty()){
        at = q.front(); q.pop();
        for (auto u: g[at]){
            if (dist[u] == -1){
                q.push(u);
                dist[u] = 1 + dist[at];
            }
        }
    }
    return at;
}
int main(){_
    int n, a, b; cin >> n;
    for (int i = 0; i < n - 1; i++){
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(dist1, -1, sizeof(dist1));
    memset(dist2, -1, sizeof(dist2));
    n1 = bfs(0, dist1);
    memset(dist1, -1, sizeof(dist1));
    n2 = bfs(n1, dist1);
    bfs(n2, dist2);
    for (int i = 0; i < n; i++){
        cout << max(dist1[i], dist2[i]) << " ";
    }
    cout << endl;
    return 0;
}