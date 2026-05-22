// Maximo num de pares em grafo bipartido
// Escolhendo vertices da esquerda e da direita
void sets(int v){
    queue<int> q;
    q.push(v); nivel[v] = 0;
    int at;
    while (!q.empty()){
        at = q.front(); q.pop();
        for (auto u: g[at]){
            if (nivel[u] == -1){
                q.push(u);
                nivel[u] = nivel[at] + 1;
                if (!(nivel[u] % 2)) l.push_back(u);
            }
        }
    }
}
// BFS do Hopcroft Karp
bool bfs(){
    queue<int> q;
    // percorrendo vertices da esquerda (possiveis comecos de caminho aumentante)
    for (auto i: l){
        if (match[i] == NIL){
            dist[i] = 0;
            q.push(i);
        } else {
            dist[i] = INT_MAX;
        }
    }
    dist[NIL] = INT_MAX;
    int u;
    while (!q.empty()){
        u = q.front(); q.pop();
        if (u != NIL){
            for (auto v: g[u]){
                if (dist[match[v]] == INT_MAX){
                    dist[match[v]] = dist[u] + 1;
                    q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL] != INT_MAX);
}
// DFS do Hopcroft Karp
bool dfs(int u){
    if (u == NIL) return true;
    for (auto v: g[u]){
        if (dist[match[v]] == dist[u] + 1){
            if (dfs(match[v])){
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
    }
    dist[u] = INT_MAX;
    return false;
}
int main(){_
    int n, a, b; cin >> n;
    for (int i = 0; i < n - 1; i++){
        cin >> a >> b; 
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(nivel, -1, sizeof(nivel));
    memset(match, NIL, sizeof(match));
    l.push_back(1);
    sets(1);
    int matches = 0;
    while (bfs()){
        for (auto i: l){
            if (match[i] == NIL && dfs(i)){
                matches++;
            }
        }
    }
    cout << matches << endl;
    return 0;
}