// pode fazer ativ a, b ou c
// nao pode fazer a mesma por 2 ou mais
// dias consecutivos
// maximo total de pontos de felicidade
int main(){_ 
    int n, x; cin >> n;
    int act[n][3];
    int memo[n][3];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++){
            cin >> x;
            act[i][j] = x;
        }
    }
    for (int i = 0; i < 3; i++){
        memo[0][i] = act[0][i];
    }
    for (int i = 1; i < n; i++){
        // escolher se é a, b ou c
        // vou testar com a e todos os outros possíveis do i-1. Mesmo para b e c
        for (int j = 0; j < 3; j++){
            int melhor = 0;
            for (int k = 0; k < 3; k++){
                if (j == k) continue;
                melhor = max(melhor, act[i][j] + memo[i-1][k]);
            }
            memo[i][j] = melhor;
        }
    }
    int maxi = -INT_MAX;
    for (int i = 0; i < 3; i++){
        maxi = max(maxi, memo[n-1][i]);
    }
    cout << maxi << endl;
    return 0;
}