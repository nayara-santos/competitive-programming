// n fatos do tipo a eh pior que b
// m declaracoes
// alternative fact: inversa eh verdadeira
// ser pior eh transitivo
// verifico se existe um caminho de c1 p/ c2
// e depois de c2 p c1
void traduzir(string s){
    if (!trad1.count(s)){
        trad1[s] = c;
        c++;
    }
}
void dfs(int v){
    vis[v] = true;
    for (auto w: g[v]){
        if (!vis[w]){
            dfs(w);
        }
    }
}
int main(){_ 
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++){
        string c1, c2; cin >> c1;
        for (int j = 0; j < 4; j++){
            cin >> c2;
        }
        traduzir(c1); traduzir(c2);
        g[trad1[c2]].push_back(trad1[c1]);
    }
    for (int i = 0; i < m; i++){
        string c1, c2; cin >> c1;
        for (int j = 0; j < 4; j++){
            cin >> c2;
        }
        if (!trad1.count(c1) || !trad1.count(c2)){
            cout << "Pants on Fire" << endl;
        } else {
            memset(vis, 0, sizeof vis);
            dfs(trad1[c2]);
            if (vis[trad1[c1]]){
                cout << "Fact" << endl;
            } else {
                memset(vis, 0, sizeof vis);
                dfs(trad1[c1]);
                if (vis[trad1[c2]]){
                    cout << "Alternative Fact" << endl;
                } else {
                    cout << "Pants on Fire" << endl;
                }
            }
        }
    }
    return 0;
}