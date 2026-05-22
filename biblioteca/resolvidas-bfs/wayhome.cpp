// Após pular do ponto x, pode chegar ao ponto x + a, em que a é um inteiro de 1 a d
// pode pular apenas em pontos com flores (char eh 1)
// num minimo de pulos que o sapo precisa para chegar no n
// modelo como grafo acíclico direcionado
// rodo a bfs para achar o menor caminho
void bfs(int v){
    queue<int> q;
    q.push(v); dist[v] = 0;
    int at;
    while (!q.empty()){
        at = q.front(); q.pop();
        for (auto w: g[at]){
            if (dist[w] == -1){
                q.push(w);
                dist[w] = dist[at] + 1;
            }
        }
    }
}
int main(){_
    int n, d; cin >> n >> d;
    string s; cin >> s;
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < s.size()-1; i++){
        for (int j = i + 1; j <= min(i + d, n-1); j++){
            if (s[i] - '0' && s[j] - '0'){
                g[i].push_back(j);
            }
        }
    }
    bfs(0);
    cout << dist[n-1] << endl;
    return 0;
}