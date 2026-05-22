// calcular a soma de cada janela de k elementos, da esq p/ dir
// elementos gerados pela funcao  dada
// saida: xor de cada soma
signed main(){_
    ll n, k, z, a, b; 
    cin >> n >> k >> z >> a >> b >> c;
    vector<ll> x(n), soma(n);
    x[0] = z;
    soma[0] = x[0];
    for (ll i = 1; i < n; i++){
        x[i] = add(mult(x[i-1], a), b) % c; 
        soma[i] = soma[i-1] + x[i]; 
    }
    ll resp = soma[k-1];
    ll i = 1;
    while (i < n-k + 1){
        resp ^= soma[i+k - 1] - soma[i-1];
        i++;
    }
    cout << resp << endl;
    return 0;
}