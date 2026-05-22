// circuito eh bom se:
// 1. possivel ir p/ qualquer turista
// a partir de um
// 2. ha exatamente um unico caminho entre nos
// Ou seja, uma arvore
// saida: ruas que precisam ser destruidas e construidas, se for ruim
void dfs(int v){
    vis[v] = 1;
    for (auto u: g[v]){
        if (!vis[u]){
            dfs(u);
        } 
    }
}
int main(){
    int n, m, a, b; cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(vis, 0, sizeof(vis));
    int cons = 0;
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i);
            cons++;
        }
    }
    cons = cons - 1;
    if (cons < 0){
        cout << "RUIM" << " " << 0 << " " << n << endl; 
    } else {
        int dest = (m + cons) - (n - 1);
        if (!cons && !dest) cout << "BOM" << endl;
        else cout << "RUIM" << " " << dest << " " << cons << endl;    
    }
    return 0;
}