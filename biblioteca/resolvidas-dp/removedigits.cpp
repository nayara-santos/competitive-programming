// dado n, voce pode subtrair 
// um dos digitos do num
// quantos passos requerem para o num 
// ser igual a 0
int dp(int i){
    if (i == 0) return memo[i] = 0;
    if (i < 0) return INT_MAX;
    if (memo[i] != -1) return memo[i];
    int menor = INT_MAX;
    int n = i;
    while (n){
        if (n % 10) menor = min(menor, 1 + dp(i - (n % 10)));
        n /= 10; 
    }
    return memo[i] = menor;
}
int main(){_ 
    int n; cin >> n;
    memset(memo, -1, sizeof(memo));
    cout << dp(n) << endl;
    return 0;
}