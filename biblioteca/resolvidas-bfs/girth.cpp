// no grafo nao direcionado
// determinar o tamanho do menor ciclo
int bfs(int v){
    queue<int> q;
    q.push(v); pai[v] = v; dist[v] = 0;
    int at;
    int tam = INT_MAX;
    while (!q.empty()){
        at = q.front(); q.pop();
        for (auto w: g[at]){
            if (pai[w] == -1){
                q.push(w);
                pai[w] = at;
                dist[w] = dist[at] + 1;
            } else if (w != pai[at]){
                tam = min(tam, dist[w] + dist[at] + 1);
            }
        }
    }
    return tam;
}
int main(){_
    int n, m, a, b; cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int resp = INT_MAX;
    for (int i = 0; i < n; i++){
        memset(pai, -1, sizeof(pai));
        memset(dist, -1, sizeof(dist));
        resp = min(resp, bfs(i));
    }
    if (resp == INT_MAX) resp = -1;
    cout << resp << endl;
    return 0;
}