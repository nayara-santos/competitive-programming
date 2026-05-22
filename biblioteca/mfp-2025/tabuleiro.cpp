// florest nxm
// f[n][m]: qtd de macas
// arvores adjacentes c/ num dif
// cobra escolhe subconj e come 1 de cada arv
// saida: config possivel da floresta originalmente
int main(){
    int n, m;
    cin >> n >> m;
    ll forest[110][110];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> forest[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if ((i + j) % 2){
                if (!(forest[i][j] % 2)) forest[i][j]++;
            } else {
                if (forest[i][j] % 2) forest[i][j]++;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << forest[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}