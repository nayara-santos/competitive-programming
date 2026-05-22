// 2^n - 1 estacoes
// estacao i tem a_i moedas
// para cada estacao k, incluindo 1:
// pega as a_k moedas
// se k >= 2^(n-1), para de pular
// senao, pula para 2k ou 2k+1
const int MAX = (1 << 18) + 1;
int memo[MAX], coins[MAX];
int pot, lim, pare;
int dp(int k){
    if (k >= pare) return memo[k] = coins[k];
    if (k > lim) return 0;
    if (memo[k] != -1) return memo[k];
    return memo[k] = coins[k] + max(dp(2*k), dp(2*k + 1));
}
int main(){_ 
    int n, a; cin >> n;
    pot = 1 << n;
    lim = pot - 1;
    pare = pot / 2;
    memset(memo, -1, sizeof memo);
    memo[0] = 0;
    coins[0] = 0;
    for (int i = 1; i <= lim; i++){
        cin >> a;
        coins[i] = a;
    }
    cout << dp(1) << endl;
    return 0;
}