// produzir soma x com moedas disponiveis
// usando o minimo de moedas
// {1, 5, 7} e soma eh 11
// uma solucao otima e 5 + 5 + 1
int main(){_  
    int n, x, c; cin >> n >> x;
    vector<int> coins;
    for (int i = 0; i < n; i++){
        cin >> c;
        coins.push_back(c);
    }
    int m = 1e9;
    vector<int> memo(x + 1, m);
    memo[0] = 0;
    for (int i = 1; i <= x; i++){
        for (auto c: coins){
            if (i - c >= 0){
                memo[i] = min(memo[i], 1 + memo[i - c]);
            }
        }
    }
    if (memo[x] == m) cout << -1 << endl;
    else cout << memo[x] << endl;
    return 0;
}