// entrada: A_k: amplitude media no minuto k
// saida: b1, b2,..., bk
// bk: qtd minutos com media maior ou igual a k
// soma de prefixo
// 2 2 2 1 4
// a:
// min 1 - media 2
// min 5 - media 4
// b:
// media 4 - +1
int main(){
    int n, m; cin >> n >> m;
    int a[n], amp[m + 1];
    int sum[m + 1];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    memset(amp, 0, sizeof(amp));
    for (int i = 0; i < n; i++){
        amp[a[i]] += 1;
    }
    for (int i = m - 1; i >= 1; i--){
        amp[i] += amp[i+1];
    }
    for (int i = 1; i <= m; i++){
        cout << amp[i] << " ";
    }
    cout << endl;
    return 0;
}