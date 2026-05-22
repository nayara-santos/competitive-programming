// cthulu se for um grafo nao direcionado que 
// pode ser representado por um conjunto de 3
// ou mais arvores cujas raizes sao conectadas
// por um ciclo simples
// rodo dfs para ver se eh conexo e tem um ciclo
// removo a aresta e rodo de novo p/ ver se tem outro ciclo
// outra forma: checar se n = m
void dfs(int v){
    for (auto w: g[v]){
        if (pais[w] == -1){
            pais[w] = v;
            dfs(w);
        } else if (w != pais[v]){
            ciclo = true;
            aresta.f = w;
            aresta.s = v;
        }
    }
}
int main(){_
    int n, m, x, y; cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(pais, -1, sizeof pais);
    dfs(0);
    bool conexo = true;
    for (int i = 1; i < n; i++){
        if (pais[i] == -1){
            conexo = false;
        }
    }
    int prim, seg, resp = 0;
    while (ciclo){
        resp++;
        ciclo = false;
        prim = aresta.f;
        seg = aresta.s;
        g[prim].erase(remove(g[prim].begin(), g[prim].end(), seg), g[prim].end());
        g[seg].erase(remove(g[seg].begin(), g[seg].end(), prim), g[seg].end());
        dfs(0);
    }
    if (conexo && resp == 1) cout << "FHTAGN!" << endl;
    else cout << "NO" << endl;
    return 0;
}