// entrada: pi eh index do superior direto de i
// par (u, k): 
// u: indice do oficial que comeca a ordem
// k: indice da posicao do oficial requerido
// na seq de passagem do comando
// saida: oficial que vai receber o comando
void dfs(int v){
    vis[v] = 1;
    if (!g[v].size()){
        sub[v] = 0;
    }
    for (auto w: g[v]){
        if (!vis[w]){
            seq.push_back(w);
            pos[w] = seq.size() - 1;
            dfs(w);
            sub[v] += sub[w] + 1;
        }
    }
}
int main(){_
    int n, q; cin >> n >> q;
    int p;
    for (int i = 1; i < n; i++){
        cin >> p; p--;
        g[p].push_back(i);
    }
    seq.push_back(0);
    pos[0] = 0;
    dfs(0);
    int u, k;
    for (int i = 0; i < q; i++){
        cin >> u >> k;
        u--; k--;
        if (sub[u] < k){
            cout << -1 << endl;
        } else {
            cout << seq[pos[u] + k] + 1 << endl;
        }
    }
    return 0;
}