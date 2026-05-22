// loja vende n livros
// valor total as compras no max x
// max num de paginas que pode comprar
int main(){_ 
    int n, x, a; cin >> n >> x;
    int h[n], s[n];
    vector<vector<int>> memo(n+1, vector<int>(x+1));
    for (int i = 0; i < n; i++){
        cin >> a;
        h[i] = a;
    }
    for (int i = 0; i < n; i++){
        cin >> a;
        s[i] = a;
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= x; j++){
            if (!i || !j) memo[i][j] = 0;
            else {
                if (h[i-1] <= j){
                    memo[i][j] = max(s[i-1] + memo[i-1][j-h[i-1]], memo[i-1][j]);
                } else {
                    memo[i][j] = memo[i-1][j];
                }
            }
        }
    }
    cout << memo[n][x] << endl;
    return 0;
}