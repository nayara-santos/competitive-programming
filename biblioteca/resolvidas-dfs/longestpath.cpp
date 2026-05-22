// achar diametro
void dfs(int v){
    for (auto w: g[v]){
        if (dist[w] == -1){
            dist[w] = dist[v] + 1;
            dfs(w);
        }
    }
}
int main(){_
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dist, -1, sizeof dist);
    dist[0] = 0;
    dfs(0);
    int pos = -1, dmax = -1;
    for (int i = 0; i < n; i++){
        if (dist[i] > dmax){
            pos = i;
            dmax = dist[i];
        }
    }
    memset(dist, -1, sizeof dist);
    dist[pos] = 0;
    dfs(pos);
    int diametro = 0;
    for (int i = 0; i < n; i++){
        diametro = max(diametro, dist[i]);
    }
    cout << diametro << endl;
    return 0;
}