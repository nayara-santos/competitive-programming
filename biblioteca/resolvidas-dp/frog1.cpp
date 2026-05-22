// sapo quer ir ate n
// se o sapo esta na pedra i
// pula para i + 1 ou i + 2
// custo do pulo eh abs(hi-hj)
// custo total minimo
int dp(int j){
    if (j == 0) return memo[j] = 0;
    if (memo[j] != -1) return memo[j];
    int melhor = INT_MAX;
    for (int i = max(0, j-2); i < j; i++){
        melhor = min(melhor, dp(i) + abs(h[j] - h[i]));
    }
    return memo[j] = melhor;
}
int main(){
    int n; cin >> n;   
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        h.push_back(a);
    }
    memset(memo, -1, sizeof memo);
    cout << dp(n-1) << endl;
    return 0;
}