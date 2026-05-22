// diferentes formas de dividir
// as series de chutes sem aumentar
// o numero de chutes consecutivos
// tambem nao faz serie com k chutes
// n = 4, k = 3
// 4 formas: 4; 2+2; 2+1+1; 1+1+1+1
int main(){
    ll n, k; cin >> n >> k;
    ll memo[n+1][n+1];
    memset(memo, 0, sizeof(memo));
    ll m = 998244353;
    for (ll j = 1; j <= n; j++){
        memo[0][j] = 1;
    }
    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= n; j++){
            memo[i][j] = memo[i][j-1];
            if (j != k && i - j >= 0){
                memo[i][j] += memo[i-j][j];
                memo[i][j] %= m;
            } 
        }
    }
    cout << memo[n][n] << endl;
    return 0;
}