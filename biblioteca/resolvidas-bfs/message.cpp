void bfs(int i){
    queue<int> q;
    q.push(i); pai[i] = i;
    int at;
    while (!q.empty()){
        at = q.front(); q.pop();
        for (auto u: g[at]){
            if (pai[u] == -1){
                q.push(u);
                pai[u] = at;
            }
        }
    }
}
vector<int> route(int i){
    vector<int> path;
    while (pai[i] != -1){
        path.push_back(i);
        if (pai[i] == i) break;
        else i = pai[i];
    }
    reverse(path.begin(), path.end());
    return path;
}
int main(){_
    int n, m, a, b; cin >> n >> m;
    memset(pai, -1, sizeof(pai));
    for (int i = 0; i < m; i++){
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(0);
    vector<int> path = route(n - 1);
    if (path.empty()){
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << path.size() << endl;
        for (auto p: path){
            cout << p + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}