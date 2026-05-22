// escolher a cor para tapar os buracos tentando fazer com que o tamanho da menor área monocromática seja o menor possível
// dois ladrilhos adjacentes (compartilham um lado) fazem parte da mesma área se possuem a mesma cor
// Veja o primeiro caso de exemplo, temos três áreas da cor 1 (uma de tamanho 3 e duas de tamanho 2), uma área da cor 2 (de tamanho 3) e uma área da cor 3 de tamanho 7. Uma resposta possível seria escolher a cor 2, fazendo com que a menor área monocromática seja de tamanho 2. Se escolhermos a cor 1, a menor área seria de tamanho 3.
// Caso haja algum buraco, sempre é possível escolher uma cor que não aumente nenhum componente, ou seja, a solução é o menor componente de toda a matriz 
const int MAX = 210;
int lad[MAX][MAX];
bool vis[MAX][MAX];
int h, l;
// cima, baixo, esquerda, direita
vector<pair<int, int>> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool valido(pair<int, int> v, int n){
    return v.f >= 0 && v.f < h && v.s >= 0 && v.s < l && lad[v.f][v.s] == n && !vis[v.f][v.s];
}
int bfs(pair<int, int> p){
    queue<pair<int, int>> q;
    q.push(p); vis[p.f][p.s] = true;
    pair<int, int> v;
    int comp = 1;
    while (!q.empty()){
        v = q.front(); q.pop();
        for (auto m: mov){
            m.f += v.f;
            m.s += v.s;
            if (valido(m, lad[p.f][p.s])){
                q.push(m);
                vis[m.f][m.s] = true;
                comp++;
            }
        }
    }
    return comp;
}
int main(){_
    cin >> h >> l;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < h; i++){
        for (int j = 0; j < l; j++){
            cin >> lad[i][j];
        }
    }
    int area = INT_MAX;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < l; j++){
            if (!vis[i][j]){
                area = min(area, bfs({i, j}));
            }
        }
    }
    cout << area << endl;
    return 0;
}