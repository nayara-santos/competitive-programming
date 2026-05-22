// raiz eh a casa e folhas rest
// contar o num de restaurantes que pode ir
// considerando que nao pode ter m vertices
// consecutivos com gatos
void dfs(int v, int max){
    vis[v] = true;
    if (g[v].size() == 1){
        folhas.push_back(v);
    }
    for (auto w: g[v]){
        if (!vis[w]){
            if (cat[w]){
                consec[w] = consec[v] + 1;
            } else {
                consec[w] = 0;
            }
            if (consec[w] <= max){
                dfs(w, max);
            }
        }
    }
}
int main(){_ 
    int n, m, c; cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> c;
        cat.push_back(c);
    }
    int x, y;
    for (int i = 0; i < n-1; i++){
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(consec, INT_MAX, sizeof consec);
    consec[0] = cat[0];
    dfs(0, m);
    int resp = 0;
    for (int i = 0; i < folhas.size(); i++){
        if (consec[folhas[i]] <= m && folhas[i] != 0) resp++;
    }
    cout << resp << endl;
    return 0;
}